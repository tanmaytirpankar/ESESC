// Contributed by Jose Renau
//                Ehsan K.Ardestani
//                Mahdi Bojnordi
//
// The ESESC/BSD License
//
// Copyright (c) 2005-2013, Regents of the University of California and
// the ESESC Project.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   - Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
//   - Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
//
//   - Neither the name of the University of California, Santa Cruz nor the
//   names of its contributors may be used to endorse or promote products
//   derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include "SamplerLdSt.h"
#include "EmulInterface.h"
#include "SescConf.h"
#include "BootLoader.h"
#include "TaskHandler.h"
#include "MemObj.h"
#include "GProcessor.h"
#include "GMemorySystem.h"

#include <iostream>

SamplerLdSt::SamplerLdSt(const char *iname, const char *section, EmulInterface *emu, FlowID fid)
  : SamplerBase(iname, section, emu, fid)
  /* SamplerLdSt constructor {{{1 */
{
  finished[fid] = true; // will be set to false in resumeThread
  finished[0] = false;
  //numNonLDSTs = 0;

  nInstForcedDetail = nInstDetail==0? nInstTiming/2:nInstDetail;

  setNextSwitch(nInstSkip);
  if (nInstSkip)
    startRabbit(fid);

  std::cout << "Sampler: ldst, R:" << nInstRabbit
            << ", W:"              << nInstWarmup
            << ", D:"              << nInstDetail
            << ", T:"              << nInstTiming
            << std::endl;

  std::cout << "Sampler: ldst, nInstMax:" << nInstMax
            << ", nInstSkip:"             << nInstSkip
            << ", maxnsTime:"             << maxnsTime
            << std::endl;
}
/* }}} */

SamplerLdSt::~SamplerLdSt()
  /* DestructorRabbit {{{1 */
{
  // Free name, but who cares
}
/* }}} */

///MnB:~
uint64_t SamplerLdSt::queue(uint64_t pc, uint64_t addr, FlowID fid, char op, int src1, int src2, int dest, int dest2, void *dummy, uint64_t smode)
//uint64_t SamplerLdSt::queue(uint64_t pc, uint64_t addr, FlowID fid, char op, int src1, int src2, int dest, int dest2, void *dummy, void *oldData, void *newData)
///:.
  /* main qemu/gpu/tracer/... entry point {{{1 */
{
  // skip all non-LDST instructions: iLALU_LD(10), iSALU_LL(12), iSALU_ST(11), and iSALU_SC(13)
  if((op != 10) && (op != 12) && (op != 11) && (op != 13)) {
  //    numNonLDSTs = 0;
      return 0;
  }
  //else {
  //    numNonLDSTs++;
  //    //return 0;
  //}
  //MSG("SamplerLdSt::queue\tpc=%llx addr=%llx op=%d cpu=%d", pc, addr, op, fid);

  I(fid < emul->getNumEmuls());
  if(likely(!execute(fid, 1)))
    return 0; // QEMU can still send a few additional instructions (emul should stop soon)
  I(mode!=EmuInit);

  // process the current sample mode
  if (getNextSwitch()>totalnInst) {

    if (mode == EmuRabbit || mode == EmuInit) {
      uint64_t rabbitInst = getNextSwitch() - totalnInst;
      execute(fid,rabbitInst);
      // Qemu is not going to return untill it has executed these many instructions
      // Or untill it hits a syscall that causes it to exit
      // Untill then, you are on your own. Sit back and relax!
      return rabbitInst;
    }

    if (mode == EmuDetail || mode == EmuTiming) {
///MnB:~ Memory Data
      emul->queueInstruction(pc,addr, fid, op, src1, src2, dest, dest2, getStatsFlag(), smode);
      //emul->queueInstruction(pc,addr, fid, op, src1, src2, dest, dest2, getStatsFlag(), oldData, newData);
///:.
      return 0;
    }

    I(mode == EmuWarmup);
#if 1
    if ( op == iLALU_LD || op == iSALU_ST)
      // cache warmup fake inst, do not need SRC deps (faster)
///MnB:~ Memory Data
      emul->queueInstruction(0,addr, fid, op, LREG_R0, LREG_R0, LREG_InvalidOutput, LREG_InvalidOutput, false, smode);
      //emul->queueInstruction(0,addr, fid, op, LREG_R0, LREG_R0, LREG_InvalidOutput, LREG_InvalidOutput, false, oldData, newData);
///:.
#else
		//doWarmupOpAddr(static_cast<InstOpcode>(op), addr);
#endif
    return 0;
  }

  // Look for the new mode
  // This can fail because the other thread can update: racy but infrequent, so OK I(getNextSwitch() <= totalnInst);

 // I(mode != next_mode);
  pthread_mutex_lock (&mode_lock);
  //

  if (getNextSwitch() > totalnInst){//another thread just changed the mode
    pthread_mutex_unlock (&mode_lock);
    return 0;
  }

  lastMode = mode;
  nextMode(ROTATE, fid);
  if (lastMode == EmuTiming) { // timing is going to be over

#if 0
		static double last_timing         = 0;
		static long long last_globalClock = 0;

		MSG("%f %lld"
				,iusage[EmuTiming]->getDouble()
				,globalClock-last_globalClock);

		last_timing      = iusage[EmuTiming]->getDouble();
		last_globalClock = globalClock;
#endif

    BootLoader::reportSample();

    if (GProcessor::getWallClock()>=maxnsTime || totalnInst>=nInstMax) {
      markDone();
      pthread_mutex_unlock (&mode_lock);
      return 0;
    }
    if (doPower) {
      uint64_t mytime = getTime();
      int64_t ti = mytime - lastTime;
      I(ti > 0);
      ti = (static_cast<int64_t>(freq)*ti)/1e9;

      BootLoader::getPowerModelPtr()->setSamplingRatio(getSamplingRatio());
      BootLoader::getPowerModelPtr()->calcStats(ti, !(lastMode == EmuTiming), fid);
      lastTime = mytime;
      updateCPI(fid);
      if (doTherm) {
        BootLoader::getPowerModelPtr()->updateSescTherm(ti);
      }
    }
  }
  pthread_mutex_unlock (&mode_lock);

  return 0;
}
/* }}} */

void SamplerLdSt::updateCPI(FlowID fid){
  //extract cpi of last sample interval

  estCPI = getMeaCPI();
  return;

}

void SamplerLdSt::nextMode(bool rotate, FlowID fid, EmuMode mod){
  if (rotate){
    fetchNextMode();
    I(next_mode != EmuInit);

    //If in live mode and warmup is to be forced
    if(BootLoader::genwarm > 0 && next_mode == EmuTiming) {
      BootLoader::genwarm--;
      setMode(EmuWarmup, fid);
      //setMode(EmuDetail, fid);
    } else if(BootLoader::live_warmup > 0 && next_mode == EmuTiming) {
      BootLoader::live_warmup--;
      //BootLoader::sample_count++;
      setMode(EmuDetail, fid);
      //setMode(EmuRabbit, fid);
    } else {
      setMode(next_mode, fid);
    }

    if (next_mode == EmuRabbit){
      setModeNativeRabbit();
    }
    setNextSwitch(getNextSwitch() + sequence_size[sequence_pos]);
  }else{
    I(0);
  }
}

void SamplerLdSt::setStatsFlag(DInst *dinst) {
  // Keep same
}
