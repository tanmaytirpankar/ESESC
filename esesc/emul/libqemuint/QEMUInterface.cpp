/*
   ESESC: Super ESCalar simulator
   Copyright (C) 2005 University California, Santa Cruz.

   Contributed by Gabriel Southern
                  Jose Renau
                  Sushant Kondguli

This file is part of ESESC.

ESESC is free software; you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation;
either version 2, or (at your option) any later version.

ESESC is    distributed in the  hope that  it will  be  useful, but  WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should  have received a copy of  the GNU General  Public License along with
ESESC; see the file COPYING.  If not, write to the  Free Software Foundation, 59
Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include <pthread.h>

#include "InstOpcode.h"
#include "Instruction.h"
#include "Snippets.h"

#include "QEMUInterface.h"
#include "QEMUReader.h"
#include "EmuSampler.h"

#include "../../../../apps/esesc/simusignal.h"

EmuSampler *qsamplerlist[128];
//EmuSampler *qsampler = 0;
bool* globalFlowStatus = 0;
typedef struct _Signal {
    uint64_t arg1;  // mode
    uint64_t arg2;  // begin
    uint64_t arg3;  // end
    struct _Signal *next;
} Signal;
Signal *head = NULL;

extern "C" void QEMUReader_goto_sleep(void *env);
extern "C" void QEMUReader_wakeup_from_sleep(void *env);
extern "C" int qemuesesc_main(int argc, char **argv, char **envp);

extern "C" void *qemuesesc_main_bootstrap(void *threadargs) {

  static bool qemuStarted = false;
  if (!qemuStarted) {
    qemuStarted = true;
    QEMUArgs *qdata = (struct QEMUArgs *) threadargs;

    int    qargc = qdata->qargc;
    char **qargv = qdata->qargv;

    MSG("Starting qemu with");
    for(int i = 0; i < qargc; i++)
      MSG("arg[%d] is: %s",i,qargv[i]);

    qemuesesc_main(qargc,qargv,NULL);

    MSG("qemu done");

    QEMUReader_finish(0);

    pthread_exit(0);
  }else{
    MSG("QEMU already started! Ignoring the new start.");
  }

  return 0;
}

extern "C" uint32_t QEMUReader_getFid(FlowID last_fid)
{
  return qsamplerlist[last_fid]->getFid(last_fid);
}

extern "C" uint64_t QEMUReader_get_time()
{
  return qsamplerlist[0]->getTime();
}

///MnB:~ Memory Data
extern "C" uint64_t QEMUReader_queue_inst(uint64_t pc, uint64_t addr, uint16_t fid, uint16_t op, uint16_t src1, uint16_t src2, uint16_t dest, void *dummy) {
//extern "C" uint64_t QEMUReader_queue_inst(uint64_t pc, uint64_t addr, uint16_t fid, uint16_t op, uint16_t src1, uint16_t src2, uint16_t dest, void *dummy, void *oldData, void *newData) {
///:.
  I(fid<128); // qsampler statically sized to 128 at most

  //I(qsamplerlist[fid]->isActive(fid) || EmuSampler::isTerminated());

  //MSG("pc=%llx addr=%llx op=%d cpu=%d",pc,addr,op,fid);
///MnB:~ Memory Data
  // iLALU_LD(10), iSALU_LL(12), iSALU_ST(11), and iSALU_SC(13)
  if((op == 10) || (op == 12) || (op == 11) || (op == 13)) {
    // search the signal list
    bool found = false;
    Signal *item, *temp = head;
    while((found != true) && (temp != NULL)) {
        found = ((addr >= temp->arg2) && (addr < temp->arg3));
        item = temp;
        temp = temp->next;
    }
    if(found) {
      //printf("QEMUReader_queue_inst\t%lx\t%lx\n", addr, item->arg1);
      //printf("%d:\tQEMUReader_queue_inst(%lx, %lx, %x, %hx, %hx, %hx, %hx, %p)\n", op, pc, addr, fid, op, src1, src2, dest, dummy);
      if(item->arg1 & SIG_NOSIMU) {
          return 0;
      }
      //if(item->arg1) printf("QEMUReader_queue_inst %lx\t%lx\n", addr, item->arg1);
      return qsamplerlist[fid]->queue(pc,addr,fid,op,src1, src2, dest, LREG_InvalidOutput, dummy, item->arg1);
    }
  }
  return qsamplerlist[fid]->queue(pc,addr,fid,op,src1, src2, dest, LREG_InvalidOutput, dummy, 0);
  //return qsamplerlist[fid]->queue(pc,addr,fid,op,src1, src2, dest, LREG_InvalidOutput, dummy, oldData, newData);
///:.
}

extern "C" uint64_t QEMUReader_signal_qemu(uint32_t fid, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4)
{
  // perform qemu specefic operations
  if(arg1 & SIG_SEARCH) {
      uint64_t match = 0;
      uint64_t *data = (uint64_t *)((void *)arg2);
      for(int i = 0; i < 64; i++) {
          //printf("\t%llx\t%llx\t%llx\n", data[i], arg3, arg4);
          if((arg4 != 0) && ((data[i] & arg4) == (arg3 & arg4))) {
              match |= 1LL<<i;
          }
      }
      //printf("%016llx\n", match);
      return match;
  }

  printf("ERROR: !\n");
  exit(0);
}

extern "C" uint64_t QEMUReader_signal_simu(uint32_t fid, uint64_t arg1, uint64_t arg2, uint64_t arg3)
{
  // search the signal list
  bool found = false;
  Signal *item, *temp = head;
  while((found != true) && (temp != NULL)) {
      found = (arg2 == temp->arg2);
      item = temp;
      temp = temp->next;
  }

  // update the signal list
  if(found) {
    MSG("UPDATE\tQEMUReader_signal_simu(%d, %lx, %lx, %lx)", fid, arg1, arg2, arg3);
    item->arg1 = arg1;
  }
  else {
    MSG("NEW\tQEMUReader_signal_simu(%d, %lx, %lx, %lx)", fid, arg1, arg2, arg3);
    temp = (Signal *)malloc(sizeof(Signal));
    temp->arg1 = arg1;
    temp->arg2 = arg2;
    temp->arg3 = arg3;
    temp->next = head;
    head = temp;
  }

//  qsamplerlist[fid]->signalSimu(fid, arg1, arg2, arg3);
}

extern "C" void QEMUReader_finish(uint32_t fid)
{
  MSG("QEMUReader_finish(%d)",fid);
  qsamplerlist[fid]->stop();
  qsamplerlist[fid]->pauseThread(fid);
  qsamplerlist[fid]->terminate();
}

extern "C" void QEMUReader_finish_thread(uint32_t fid)
{
  MSG("QEMUReader_finish_thread(%d)",fid);
  qsamplerlist[fid]->stop();
  qsamplerlist[fid]->pauseThread(fid);
}

extern "C" void QEMUReader_start_roi(uint32_t fid)
{
  qsamplerlist[fid]->start_roi();
}

extern "C" void QEMUReader_syscall(uint32_t num, uint64_t usecs, uint32_t fid)
{
  //MSG("syscall %d - %lx - %d",num,usecs,fid);
  //qsamplerlist[fid]->syscall(num, usecs, fid);
}

#if 1
extern "C" FlowID QEMUReader_resumeThreadGPU(FlowID uid) {
  return(qsamplerlist[uid]->resumeThread(uid));
}

extern "C" FlowID QEMUReader_cpu_start(uint32_t cpuid) {
  qsamplerlist[0]->setFid(cpuid);
  MSG("cpu_start %d",cpuid);
  return(qsamplerlist[cpuid]->resumeThread(cpuid, cpuid));
}
extern "C" FlowID QEMUReader_cpu_stop(uint32_t cpuid) {
  MSG("cpu_stop %d",cpuid);
  qsamplerlist[cpuid]->pauseThread(cpuid);
}

extern "C" FlowID QEMUReader_resumeThread(FlowID uid, FlowID last_fid) {
  uint32_t fid = qsamplerlist[0]->getFid(last_fid);
  MSG("resume %d -> %d",last_fid,fid);
  return(qsamplerlist[fid]->resumeThread(uid, fid));
}
extern "C" void QEMUReader_pauseThread(FlowID fid) {
  qsamplerlist[fid]->pauseThread(fid);
}

extern "C" void QEMUReader_setFlowCmd(bool* flowStatus) {

}
#endif

extern "C" int32_t QEMUReader_setnoStats(FlowID fid){
  return 0;
}
