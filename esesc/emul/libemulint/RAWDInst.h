// Contributed by Jose Renau
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

#ifndef RAWDINST_H
#define RAWDINST_H

#include <vector>
#include "Instruction.h"

typedef uint64_t DataType;
typedef uint64_t AddrType;
typedef uint32_t FlowID; 

#include "nanassert.h"

class RAWDInst {
private:
  AddrType    pc;
  AddrType    addr;
  Instruction inst;

  bool keepStats;

public:
  RAWDInst(const RAWDInst &p) {
    pc        = p.pc;
    addr      = p.addr;
    inst      = p.inst;
    keepStats = p.keepStats;
  }

  RAWDInst() {
  }

///MnB:~
  AddrType smode;
  void set(AddrType _pc, AddrType _addr, InstOpcode _op, RegType _src1, RegType _src2, RegType _dest, RegType _dest2, bool _keepStats, AddrType _smode) {
  //void set(AddrType _pc, AddrType _addr, InstOpcode _op, RegType _src1, RegType _src2, RegType _dest, RegType _dest2, bool _keepStats, void *_oldData, void *_newData) {
///:.
    pc   = _pc;
    addr = _addr;
    keepStats = _keepStats;
    smode = _smode;
    //if(smode) printf("MnB: set\t%lx\t%lx\n", addr, smode);
///MnB:~ Memory Data
    inst.set(_op, _src1, _src2, _dest, _dest2);
    //inst.set(_op, _src1, _src2, _dest, _dest2, _oldData, _newData);
///:.
  }

  AddrType    getPC()   const { return pc;   };
  AddrType    getAddr() const { return addr; };
  bool getStatsFlag()   const { return keepStats; };
  AddrType   getSMode() const { return smode; };

  const Instruction *getInst() const { return &inst; };
};

#endif

