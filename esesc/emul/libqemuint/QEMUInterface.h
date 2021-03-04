/*
   ESESC: Super ESCalar simulator
   Copyright (C) 2006 University California, Santa Cruz.

   Contributed by Gabriel Southern
                  Jose Renau


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

#ifndef QEMU_INTERFACE_H
#define QEMU_INTERFACE_H

#include <stdint.h>

#include "nanassert.h"

class EmuSampler;

extern EmuSampler *qsamplerlist[];
extern EmuSampler *qsampler;

extern "C" {
  typedef struct QEMUArgs {
    int qargc;
    char **qargv;
  } QEMUArgs;

  void *qemuesesc_main_bootstrap(void *threadargs);
  void QEMUReader_goto_sleep(void *env);
  void QEMUReader_wakeup_from_sleep(void *env);

///MnB:~ Memory Data
  uint64_t QEMUReader_queue_inst(uint64_t pc, uint64_t addr, uint16_t fid, uint16_t op, uint16_t src1, uint16_t src2, uint16_t dest, void *dummy);
  //uint64_t QEMUReader_queue_inst(uint64_t pc, uint64_t addr, uint16_t fid, uint16_t op, uint16_t src1, uint16_t src2, uint16_t dest, void *dummy, void *oldData, void *newData);

  uint64_t QEMUReader_signal_simu(uint32_t fid, uint64_t arg1, uint64_t arg2, uint64_t arg3);
  uint64_t QEMUReader_signal_qemu(uint32_t fid, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4);
///:.

  void QEMUReader_finish(uint32_t fid);
  void QEMUReader_finish_thread(uint32_t fid);

  void QEMUReader_start_roi(uint32_t fid);

  void esesc_set_rabbit(uint32_t fid);
  void esesc_set_warmup(uint32_t fid);
  void esesc_set_timing(uint32_t fid);
  void loadSampler(uint32_t fid);
}

#endif
