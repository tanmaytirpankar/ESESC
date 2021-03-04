// Contributed by Mahdi Nazm Bojnordi
//
// The ESESC/BSD License
//
// Copyright (c) 2005-2016, Regents of the University of Rochester and
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


#ifndef XAMIO_H
#define XAMIO_H

//#include <vector>
#include <queue>
#include <map>

#include "GStats.h"
//#include "CacheCore.h"
//#include "Port.h"
#include "MemRequest.h"
#include "MemObj.h"

#include "SescConf.h"
#include "callback.h"

#include "Snippets.h"

#include "DRAM.h"

typedef uint64_t DataType;


enum XAMMode {
  UNINIT = 0,
  INDXED,
  SEARCH,
  COLINP,
  ROWINP,
  XAMINP,
  XAMOUT
};

static char *XAMModeStr[] = {
  "UNINIT",
  "INDXED",
  "SEARCH",
  "COLINP",
  "ROWINP",
  "XAMINP",
  "XAMOUT",
  NULL
};


enum XCtrlMode {
  CACHE = 0,
  SPRAM,
  SPCAM
};


// writeback type
typedef struct _XAMIOWriteBack {
  AddrType maddr;
  void *mdata;
} XAMIOWriteBack;

// remap entry type
typedef struct _XAMIORemapEntry {
  bool valid;
  //bool block;
  long count;
  Time_t ttime;
  AddrType index;
} XAMIORemapEntry;


// Memory Reference
class XAMIOReference {
protected:
  // arrival time of this reference to the DRAM queue
  Time_t birthTime;
  Time_t climbTime;
  Time_t deathTime;

  bool sentUp;
  long readCount;

  // MemRequest that made this reference
  AddrType smode;
  AddrType maddr;
  AddrType vaultID;
  AddrType bankID;
  AddrType superID;
  AddrType setID;
  AddrType rowID;
  AddrType colID;
  AddrType tagID;
  AddrType addrTag;
  AddrType tagBankID;
  AddrType tagSuperID;
  AddrType tagSetID;
  AddrType tagRowID;
  AddrType tagColID;

  bool read;
  bool search;
  bool keyReset;
  bool maskReset;
  bool columnWrite;
  bool preparePending;
  bool activatePending;
  bool readPending;
  bool writePending;
  bool burstPending;
  bool keyPending;
  bool maskPending;
  bool cacheHit;

  XAMMode burstType;
  ReferenceState state;
  DataType block[8];

  MemRequest *mreq;
  std::vector<MemRequest *> lreqs;
  XAMIORemapEntry *rptr;

public:
  // constructor
  XAMIOReference();
  ~XAMIOReference() {
    //printLog();
    clearLog();
  }

  void setState(ReferenceState state) { this->state = state; addLog("( %s )", ReferenceStateStr[state]); }
  void setMReq(MemRequest *mreq) { this->mreq = mreq; }
  void setRPtr(XAMIORemapEntry *rptr) { this->rptr = rptr; }
  void setSMode(AddrType smode) { this->smode = smode; }
  void setMAddr(AddrType maddr) { this->maddr = maddr; }
  void setVaultID(AddrType vaultID) { this->vaultID = vaultID; }
  void setBankID(AddrType bankID) { this->bankID = bankID; }
  void setSuperID(AddrType superID) { this->superID = superID; }
  void setSetID(AddrType setID) { this->setID = setID; }
  void setRowID(AddrType rowID) { this->rowID = rowID; }
  void setColID(AddrType colID) { this->colID = colID; }
  void setAddrTag(AddrType addrTag) { this->addrTag = addrTag; }
  void setTagBankID(AddrType tagBankID) { this->tagBankID = tagBankID; }
  void setTagSuperID(AddrType tagSuperID) { this->tagSuperID = tagSuperID; }
  void setTagSetID(AddrType tagSetID) { this->tagSetID = tagSetID; }
  void setTagRowID(AddrType tagRowID) { this->tagRowID = tagRowID; }
  void setTagColID(AddrType tagColID) { this->tagColID = tagColID; }

  void setRead(bool value) { this->read = value; }
  void setSearch(bool value) { this->search = value; }
  void setKeyReset(bool value) { this->keyReset = value; }
  void setMaskReset(bool value) { this->maskReset = value; }
  void setColumnWrite(bool value) { this->columnWrite = value; }
  void setPreparePending(bool value) { this->preparePending = value; }
  void setActivatePending(bool value) { this->activatePending = value; }
  void setReadPending(bool value) { this->readPending = value; }
  void setWritePending(bool value) { this->writePending = value; }
  void setBurstPending(bool burstPending, XAMMode burstType) { this->burstPending = burstPending; this->burstType = burstType; }
  void setKeyPending(bool value) { this->keyPending = value; }
  void setMaskPending(bool value) { this->maskPending = value; }
  void setCacheHit(bool value) { this->cacheHit = value; }

  DataType* getBlock() { return block; }
  ReferenceState getState() { return this->state; }
  MemRequest* getMReq() { return this->mreq; }
  XAMIORemapEntry *getRPtr() { return this->rptr; }
  AddrType getSMode() { return this->smode; }
  AddrType getMAddr() { return this->maddr; }
  AddrType getVaultID() { return this->vaultID; }
  AddrType getBankID() { return this->bankID; }
  AddrType getSuperID() { return this->superID; }
  AddrType getSetID() { return this->setID; }
  AddrType getRowID() { return this->rowID; }
  AddrType getColID() { return this->colID; }
  AddrType getTagID() { return this->tagID; }
  AddrType getAddrTag() { return this->addrTag; }
  AddrType getTagBankID() { return this->tagBankID; }
  AddrType getTagSuperID() { return this->tagSuperID; }
  AddrType getTagSetID() { return this->tagSetID; }
  AddrType getTagRowID() { return this->tagRowID; }
  AddrType getTagColID() { return this->tagColID; }

  bool isRead() { return this->read; }
  bool isSearch() { return this->search; }
  bool isKeyReset() { return this->keyReset; }
  bool isMaskReset() { return this->maskReset; }
  bool isColumnWrite() { return this->columnWrite; }
  bool needsPrepare() { return this->preparePending; }
  bool needsActivate() { return this->activatePending; }
  bool needsRead() { return this->readPending; }
  bool needsWrite() { return this->writePending; }
  bool needsBurst() { return this->burstPending; }
  XAMMode getBurstType() { return this->burstType; }
  bool needsKey() { return this->keyPending; }
  bool needsMask() { return this->maskPending; }
  bool needsTagAccess() { return (this->state == SENDKEY)||(this->state == READTAG)||(this->state == FINDTAG)||(this->state == SENDTAG)||(this->state == DODIRTY); }
  bool isCacheHit() { return this->cacheHit; }

  void setReadCount(long value) { readCount = value; }
  long decReadCount() { return --readCount; }

  void sendUp();

  std::vector<char *> logText;
  std::vector<Time_t> logTime;
  void addLog(const char *format, ...) {
    //return;
    char *temp = (char *)malloc(1024);
    va_list ap;
    va_start(ap, format);
    vsprintf(temp, format, ap);
    va_end(ap);
    logText.push_back(temp);
    logTime.push_back((Time_t)globalClock);
    //printf("\t@ %ld\t%s\t%s\t%lx\t0x%lx\n", globalClock, temp, read? "READ": "WRITE", smode, maddr); fflush(stdout);
    //if(globalClock > 4699036) exit(0);
    //if(logText.size() > 100) { printState(); printLog(); exit(0); }
  }
  void clearLog() {
    while(logText.size()) {
      free(logText[0]);
      logText.erase(logText.begin());
      logTime.erase(logTime.begin());
    }
  }
  void printLog() {
    printf("%s\t%lx\t0x%lx\n", read? "READ": "WRITE", smode, maddr);
    printf("\tbirth: %lu\tclimb: %lu\tdeath: %lu\n", birthTime, climbTime, deathTime);
    for(long i = 0; i < logText.size(); ++i) {
      printf("\t@ %lu\t%s\n", logTime[i], logText[i]);
    }
    printf("\n");
  }
  void printState() {
    //printf("%s 0x%lx [%ld:%ld:%ld:%ld:%ld]\n", read? "READ": "WRITE", maddr, vaultID, rankID, bankID, rowID, colID);
    //printf(" state            = %s\n", WideIORefStateStr[state]);
    //printf(" updatePending    = %s\n loadPending      = %s\n prechargePending = %s\n activatePending  = %s\n writePending     = %s\n readPending      = %s\n burstPending     = %s\n sentUp           = %s\n", updatePending ? "true": "false", loadPending ? "true": "false", prechargePending ? "true": "false", activatePending  ? "true": "false", writePending     ? "true": "false", readPending      ? "true": "false", burstPending     ? "true": "false", sentUp           ? "true": "false");
  }
};


// XAMIO Set
class XAMIOSet {
protected:
  AddrType numRows;
  AddrType numCols;
  AddrType numSubs;

  // set statistics
  GStatsCntr numCAMReads;
  GStatsCntr numRAMReads;
  GStatsCntr numRowWrites;
  GStatsCntr numColWrites;
  GStatsHist histSetWrites;

  DataType *content; //[64][8];

public:
  // Costructor
  XAMIOSet(const char *name, AddrType numRows, AddrType numCols);
  ~XAMIOSet() {};

  void write(XAMMode mode, AddrType index, DataType *data);
  void read(XAMMode mode, AddrType index, DataType *output, DataType *mask, DataType *key);

  void getColBlock(AddrType index, DataType *data) {
    if(index < numRows) {
      for(int i = 0; i < numSubs; ++i) {
        data[i] = content[i*numRows + index];
      }
    }
    else {
      printf("ERROR: Invalid getColBlock operation for %d!\n", index);
      exit(0);
    }
  }

  void getRowBlock(AddrType index, DataType *data) {
    if(index < numRows) {
      int c = 0;
      for(int i = 0; i < numSubs; ++i) {
        DataType temp = 1;
        data[i] = 0;
        for(int j = 0; j < numRows; ++j) {
          if(content[c] & (1LL<<index)) {
            data[i] |= temp;
          }
          temp = temp << 1;
          c++;
        }
      }
    }
    else {
      printf("ERROR: Invalid getRowBlock operation for %d!\n", index);
      exit(0);
    }
  }
};


// XAMIO Super Set
class XAMIOSuper {
protected:
  XAMMode mode;
  AddrType numSets;

  // superset statistics
  GStatsCntr numActivates;
  GStatsCntr numKeyWrites;
  GStatsCntr numMaskWrites;

  // internal resources
  std::vector<XAMIOSet *> sets;
  DataType *keyBlock;
  DataType *maskBlock;
  bool maskPending;
  bool keyPending;
  long maskPattern; // -1: custom; otherwise, tagRowID

public:
  XAMIOSuper(const char *name, AddrType numSets, AddrType numRows, AddrType numCols);
  ~XAMIOSuper() {};

  void resetKey() { keyPending = true; }
  void resetMask() { maskPending = true; }
  bool needsKey() { return keyPending; }
  bool needsMask() { return maskPending; }

  void setMaskPattern(long value) { maskPattern = value; }
  long getMaskPattern() { return maskPattern; }

  XAMMode getMode() { return mode; }
  void activate();
  void write(XAMMode bankMode, AddrType setID, AddrType index, DataType *data);
  void read(XAMMode mode, AddrType setID, AddrType index, DataType *output);

  void getColBlock(AddrType setID, AddrType index, DataType *data) { sets[setID]->getColBlock(index, data); }
  void getRowBlock(AddrType setID, AddrType index, DataType *data) { sets[setID]->getRowBlock(index, data); }
};


// XAMIO Bank
class XAMIOBank {
protected:
  XAMMode mode;
  AddrType numSupers;

  // Timestampts
  Time_t lastPrepare;
  Time_t lastActivate;
  Time_t lastWrite;
  Time_t lastRead;

  // bank statistics
  GStatsCntr numPrepares;

  // internal resources
  std::vector<XAMIOSuper *> supers;

public:
  // Costructor
  XAMIOBank(const char *name, AddrType numSupers, AddrType numSets, AddrType numRows, AddrType numCols);
  ~XAMIOBank() {};

  Time_t getLastPrepare() { return lastPrepare; }
  Time_t getLastActivate() { return lastActivate; }
  Time_t getLastWrite() { return lastWrite; }
  Time_t getLastRead() { return lastRead; }

  void resetKey() { for(int i=0; i<numSupers; ++i) { supers[i]->resetKey(); } }
  void resetMask() { for(int i=0; i<numSupers; ++i) { supers[i]->resetMask(); } }
  bool needsKey(AddrType superID) { return supers[superID]->needsKey(); }
  bool needsMask(AddrType superID) { return supers[superID]->needsMask(); }

  XAMMode getMode() { return mode; }
  XAMMode getSuperMode(AddrType superID) { return supers[superID]->getMode(); }
  void prepare();
  void activate(AddrType superID);
  void write(AddrType superID, AddrType setID, AddrType index, DataType *data);
  void read(AddrType superID, AddrType setID, AddrType index, DataType *output);

  void setMaskPattern(AddrType superID, long value) { supers[superID]->setMaskPattern(value); }
  long getMaskPattern(AddrType superID) { return supers[superID]->getMaskPattern(); }

  void getColBlock(AddrType superID, AddrType setID, AddrType index, DataType *data) { supers[superID]->getColBlock(setID, index, data); }
  void getRowBlock(AddrType superID, AddrType setID, AddrType index, DataType *data) { supers[superID]->getRowBlock(setID, index, data); }
};


// XAMIO Vault
class XAMIOVault {
protected:
  XCtrlMode mode;
  AddrType numBanks;
  AddrType numSupers;
  AddrType numSets;
  AddrType numRows;
  AddrType numRowsLog2;
  AddrType tagSize;
  AddrType tagSizeLog2;
  AddrType ptrEvict;

  // control parameters
  uint schQueueSize;

  // XAMIO timing parameters
  Time_t tCCD;    // Column to Column Delay
  Time_t tWTR;    // Write To Read delay time
  Time_t tRTP;    // Read to Precharge
  Time_t tRRD;    // Row activation to Row activation Delay
  Time_t tRAS;    // Row Access Strobe
  Time_t tRCD;    // Row to Column Delay
  Time_t tFAW;    // Four bank Activation Window
  Time_t tOST;    // Output Switching Time
  Time_t tCAS;    // Column Access Strobe latency (aka tCL)
  Time_t tCWD;    // Column Write Delay (aka tWL)
  Time_t tWR;     // Write Recovery time
  Time_t tRP;     // Row Precharge
  Time_t tRC;     // Row Cycle
  Time_t tBL;     // Burst Length
  //Time_t tREFI;   // Refresh Interval period
  //Time_t tRFC;    // Refresh Cycle time
  //Time_t tRTRS;   // Rank-To-Rank switching time
  //Time_t tOST;    // Output Switching Time
  //Time_t tCAS;    // Column Access Strobe latency (aka tCL)
  //Time_t tCWD;    // Column Write Delay (aka tWL)
  //Time_t tBL;     // Burst Length
  //Time_t tCPDED;  // Command Pass Disable Delay
  //Time_t tPD;     // Minimum power down duration
  //Time_t tXP;     // Time to exit fast power down
  //Time_t tXPDLL;  // Time to exit slow power down

  // XAMIO lifetime parameters
  Time_t tCLOCK;    // Clock cycle (picoseconds)
  Time_t tLIFE;     // Lifetime (years)
  Time_t nDW;       // Number of Durable Writes (millions)
  Time_t nWW;       // Number of Writes per Window
  Time_t tMWW;      // Multiple Write Window
  std::vector<std::vector <Time_t> > lastWrites;

  // Timestamps
  Time_t lastActivate;
  Time_t lastActive_1;
  Time_t lastActive_2;
  Time_t lastWrite;
  Time_t lastRead;

  // internal resources
  std::vector<XAMIOBank *> banks;
  std::vector<XAMIOReference *> schQueue;
  std::queue<XAMIOReference *> retQueue;

  // write wear leveling
//  long        setRemapMode;
//  long        setDirtyLimit;
//  long        bankRemapMode;
//  char       *setWriteFlags;
//  char       *setDirtyFlags;
//  long        numWrites;
//  long        numSetFlags;
//  long        numWriteFlags;
//  long        numDirtyFlags;
//  double      setWriteRatio;
//  AddrType    setOffset;
//  AddrType    bankOffset;
//  GStatsTrac  tracSetWrites;
//  GStatsTrac  tracDirtySets;
//  GStatsCntr  countSetRemap;

  // cache statistics
  GStatsCntr  countWrite;
  GStatsCntr  countInstall;
  GStatsHist  *histWriteWindow;

public:
  // constructor
  XAMIOVault(const char *section, const char *name, XCtrlMode mode, AddrType numBanks, AddrType numSupers, AddrType numSets, AddrType numRows, AddrType rowSize, AddrType tagSize);
  ~XAMIOVault() {};

  //void setHistWriteWindow(GStatsHist  *histWriteWindow) { this->histWriteWindow = histWriteWindow; }

  void resetKey() { for(int i=0; i<numBanks; ++i) { banks[i]->resetKey(); } }
  void resetMask() { for(int i=0; i<numBanks; ++i) { banks[i]->resetMask(); } }
  bool needsKey(AddrType bankID, AddrType superID) { return banks[bankID]->needsKey(superID); }
  bool needsMask(AddrType bankID, AddrType superID) { return banks[bankID]->needsMask(superID); }

  XAMMode getBankMode(AddrType bankID) { return banks[bankID]->getMode(); }
  XAMMode getSuperMode(AddrType bankID, AddrType superID) { return banks[bankID]->getSuperMode(superID); }

  bool isFull();
  bool canIssuePrepare(AddrType bankID);
  bool canIssueActivate(AddrType bankID);
  bool canIssueRead(AddrType bankID);
  bool canIssueWrite(AddrType bankID);
  void prepare(AddrType bankID);
  void activate(AddrType bankID, AddrType superID);
  void write(AddrType bankID, AddrType superID, AddrType setID, AddrType index, DataType *data);
  void read(AddrType bankID, AddrType superID, AddrType setID, AddrType index, DataType *output);
  void performBurst();
  void receiveReturned();

  void clock();
  void addReference(XAMIOReference *mref);
  void retReference(XAMIOReference *mref);

  // update queue state
  void updateCACHEQueue();
  void updateSPRAMQueue();
  void updateSPCAMQueue();

  // command scheduler
  void scheduleCACHE();
  void scheduleSPRAM();
  void scheduleSPCAM();

  void setMaskPattern(AddrType bankID, AddrType superID, long value) { banks[bankID]->setMaskPattern(superID, value); }
  long getMaskPattern(AddrType bankID, AddrType superID) { return banks[bankID]->getMaskPattern(superID); }

  void getColBlock(AddrType bankID, AddrType superID, AddrType setID, AddrType index, DataType *data) { banks[bankID]->getColBlock(superID, setID, index, data); }
  void getRowBlock(AddrType bankID, AddrType superID, AddrType setID, AddrType index, DataType *data) { banks[bankID]->getRowBlock(superID, setID, index, data); }
};


// XAMIO Interface
class XAMIO: public MemObj {
protected:
  // dimensions
  AddrType memSize;
  AddrType xamSize;
  AddrType numVaults;
  AddrType numCVaults;
  AddrType numRVaults;
  AddrType numSVaults;
  AddrType numBanks;
  AddrType numTBanks;
  AddrType numDBanks;
  AddrType numSupers;
  AddrType numSets;
  AddrType numRows;
  AddrType rowSize;
  AddrType tagSize;
  AddrType numTags;

  // intermediate parameters
  AddrType memSizeLog2;
  AddrType xamSizeLog2;
  AddrType numCVaultsLog2;
  AddrType numRVaultsLog2;
  AddrType numSVaultsLog2;
  AddrType numBanksLog2;
  AddrType numSupersLog2;
  AddrType numSetsLog2;
  AddrType numRowsLog2;
  AddrType rowSizeLog2;
  AddrType tagSizeLog2;
  AddrType numTagsLog2;
  AddrType numDBanksLog2;
  AddrType numTBanksLog2;

  // internal resources
  std::vector<XAMIOVault *> vaults;
  std::queue<XAMIOReference *> receivedQueue;
  XAMIORemapEntry *remapTable;
  long remapTableNext;

  // WideIO statistics
  GStatsCntr  countReceived;
  GStatsCntr  countServiced;
  GStatsCntr  countSentLower;
  GStatsCntr  countWriteBack;
  GStatsCntr  countSkipped;

  GStatsCntr  countCacheHit;
  GStatsCntr  countCacheMiss;
  GStatsTrac  tracHitRatio;

  GStatsAvg   avgAccessTime;
  GStatsTrac  tracAccessTime;
  GStatsTrac  tracRemapNext;
  GStatsTrac  tracNumSkipped;
  //GStatsHist  *histWriteWindow;

public:
  XAMIO(MemorySystem* current, const char *section, const char *device_name = NULL);
  ~XAMIO() {};

  // Entry points to schedule that may schedule a do?? if needed
  void req(MemRequest *mreq)         { doReq(mreq); };
  void reqAck(MemRequest *mreq)      { doReqAck(mreq); };
  void setState(MemRequest *mreq)    { doSetState(mreq); };
  void setStateAck(MemRequest *mreq) { doSetStateAck(mreq); };
  void disp(MemRequest *mreq)        { doDisp(mreq); }

  // These do the real work
  void doReq(MemRequest *mreq);
  void doReqAck(MemRequest *mreq);
  void doSetState(MemRequest *mreq);
  void doSetStateAck(MemRequest *mreq);
  void doDisp(MemRequest *mreq);

  void tryPrefetch(AddrType addr, bool doStats);

  TimeDelta_t ffread(AddrType addr);
  TimeDelta_t ffwrite(AddrType addr);

  bool isBusy(AddrType addr) const;

  void addRequest(MemRequest *mreq, bool read);
  bool sendToVault(XAMIOReference *mref);
  void doSkipBlocks(void);
  void completeMRef(void);
  void doWriteBacks(void);
  void doFetchBlock(void);
  void finishXAMIO(void);
  void dispatchRefs(void);
  void manageXAMIO(void);

  typedef CallbackMember0<XAMIO, &XAMIO::manageXAMIO>   ManageXAMIOCB;
  bool clockScheduled;
};

#endif  // XAMIO_H
