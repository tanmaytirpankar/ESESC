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


#ifndef DDRx_H
#define DDRx_H

//#include <vector>
#include <queue>

#include "GStats.h"
//#include "CacheCore.h"
//#include "Port.h"
#include "MemRequest.h"
#include "MemObj.h"

#include "SescConf.h"
#include "callback.h"

#include "Snippets.h"

#include "DRAM.h"

// Memory Reference
class DDRxReference {
protected:
  // arrival time of this reference to the DRAM queue
  Time_t timeStamp;

  // MemRequest that made this reference
  MemRequest *mreq;

  // DRAM coordinates
  AddrType chanID;
  AddrType rankID;
  AddrType bankID;
  AddrType rowID;

  // next needed DRAM command 
  bool prechargePending;
  bool activatePending;
  bool readPending;
  bool writePending;
  bool ready;
  bool mark;
  bool read;
  bool replicated;
  bool burstPending;

//mani: data pointer for DDRxReference
//  void *data;

public:
  // constructor
  DDRxReference();
  ~DDRxReference() {};

  void setTimeStamp(Time_t timeStamp) { this->timeStamp = timeStamp; }
  void setMReq(MemRequest *mreq) { this->mreq = mreq; }
  void setChannelID(AddrType chanID) { this->chanID = chanID; }
  void setRankID(AddrType rankID) { this->rankID = rankID; }
  void setBankID(AddrType bankID) { this->bankID = bankID; }
  void setRowID(AddrType rowID) { this->rowID = rowID; }
  void setPrechargePending(bool prechargePending) { this->prechargePending = prechargePending; }
  void setActivatePending(bool activatePending) { this->activatePending = activatePending; }
  void setReadPending(bool readPending) { this->readPending = readPending; }
  void setWritePending(bool writePending) { this->writePending = writePending; }
  void setReady(bool ready) { this->ready = ready; }
  void setMarked(bool mark) { this->mark = mark; }
  void setRead(bool read) { this->read = read; }
  void setReplicated(bool replicated) { this->replicated = replicated; }
  void setBurstPending(bool burstPending) { this->burstPending = burstPending; }

//mani: adding data to DDRxReference
  //void setData(void* data, unsigned int blkSize) { this->data = (uint64_t *) malloc(blkSize); memcpy(this->data, data, BLKSIZE); }

  Time_t getTimeStamp() { return timeStamp; }
  MemRequest *getMReq() { return mreq; }
//mani: return data
  //void *getData() { return data; }
  AddrType  getChannelID() { return chanID; }
  AddrType  getRankID() { return rankID; }
  AddrType  getBankID() { return bankID; }
  AddrType  getRowID()  { return rowID; }
  bool needsPrecharge() { return prechargePending; }
  bool needsActivate() { return activatePending; }
  bool needsRead() { return readPending; }
  bool needsWrite() { return writePending; }
  bool isReady() { return ready; }
  bool isMarked() { return mark; }
  bool isRead() { return read; }
  bool isReplicated() { return replicated; }
  bool needsBurst() { return burstPending; }

  //void *getData() {
  //  void *data = this->mreq->getData();
  //  if(data == NULL) {
  //    #define BLKBITS 6
  //    uint64_t *ptr = (uint64_t *)((this->mreq->getPAddr() << BLKBITS) >> BLKBITS);
  //    data = (void *) ptr;
  //  }
  //  return data;
  //}

  // completing memory service
  Time_t complete();
};


// DDRx Bank
class DDRxBank {
protected:
  // Bank state
  STATE state;
  AddrType openRowID;

  // Timestamp for the memory bank
  Time_t lastRefresh;
  Time_t lastPrecharge;
  Time_t lastActivate;
  Time_t lastRead;
  Time_t lastWrite;

  // row buffer hit flag
  bool rowHit;

  // bank statistics
  GStatsCntr numReads;
  GStatsCntr numWrites;
  GStatsCntr numActivates;
  GStatsCntr numPrecharges;
  GStatsCntr numRefreshes;
  GStatsCntr numRowHits;
  GStatsCntr numRowMisses;


public:
  // Costructor
  DDRxBank(const char *name);
  ~DDRxBank() {};

  void setState(STATE _state) { state = _state; }
  void setOpenRowID(AddrType _openRowID) { openRowID = _openRowID; }

  void refresh();
  void precharge();
  void activate(AddrType rowID);
  void read();
  void write();

  STATE getState() { return state; }
  AddrType getOpenRowID() { return openRowID; }

  Time_t getLastRefresh() { return lastRefresh; }
  Time_t getLastPrecharge() { return lastPrecharge; }
  Time_t getLastActivate() { return lastActivate; }
  Time_t getLastRead() { return lastRead; }
  Time_t getLastWrite() { return lastWrite; }
};


// DDRx Rank
class DDRxRank {
protected:
  AddrType numBanks;
  AddrType numBanksLog2;

  EMR  emr;
  POWERSTATE powerState;
  bool cke;
  bool urgentRefresh;
  long rankEnergy;

  // Timestamp for the memory rank
  Time_t timeRefresh;
  Time_t lastRefresh;
  Time_t lastPrecharge;
  Time_t lastActivate;
  Time_t lastActive_1;
  Time_t lastActive_2;
  Time_t lastRead;
  Time_t lastWrite;

  // DDRx timing parameters
  Time_t tREFI;   // Refresh Interval period
  Time_t tRFC;    // Refresh Cycle time
  Time_t tRTRS;   // Rank-To-Rank switching time
  Time_t tOST;    // Output Switching Time
  Time_t tRCD;    // Row to Column Delay
  Time_t tCAS;    // Column Access Strobe latency (aka tCL)
  Time_t tCWD;    // Column Write Delay (aka tWL)
  Time_t tCCD;    // Column to Column Delay
  Time_t tWTR;    // Write To Read delay time
  Time_t tWR;     // Write Recovery time
  Time_t tRTP;    // Read to Precharge
  Time_t tRP;     // Row Precharge
  Time_t tRRD;    // Row activation to Row activation Delay
  Time_t tRAS;    // Row Access Strobe
  Time_t tRC;     // Row Cycle
  Time_t tBL;     // Burst Length
  Time_t tCPDED;  // Command Pass Disable Delay
  Time_t tPD;     // Minimum power down duration
  Time_t tXP;     // Time to exit fast power down
  Time_t tXPDLL;  // Time to exit slow power down
  Time_t tFAW;    // Four bank Activation Window

  // DDRx power/energy parameters
  long VDD;       // Operating voltage
  long VDDMax;    // Maximum Operating voltage
  long IDD0;      // Operating current: One bank active-precharge
  long IDD2PF;    // Precharge power-down current, Fast PDN Exit; MRS[12] = 0
  long IDD2PS;    // Precharge power-down current, Slow PDN Exit; MRS[12] = 1
  long IDD2N;     // Precharge standby current
  long IDD3P;     // Active power-down current
  long IDD3N;     // Active standby current
  long IDD4R;     // Operating burst read current
  long IDD4W;     // Operating burst write current
  long IDD5;      // Burst refresh current
  long cycleTime; // DRAM clock cycle time
  long numChips;  // Number of chips per rank

  long eIDD2PF;   // 
  long eIDD2PS;   // 
  long eIDD2N;    // 
  long eIDD3N;    // 
  long eIDD3P;    // 
  long eActivate; // consumed energy per activate command
  long ePrecharge;// consumed energy per precharge command
  long eRead;     // consumed energy per read command
  long eWrite;    // consumed energy per write command
  long eRefresh;  // consumed energy per refresh command

  // internal resources
  std::vector<DDRxBank *> banks;

/*
  // rank statistics
  //GStatsHist stampRefresh;
*/

public:
  // Costructor
  DDRxRank(const char *section, const char *name, AddrType numBanks);
  ~DDRxRank() {};

  STATE getBankState(AddrType bankID) { return banks[bankID]->getState(); }
  AddrType getOpenRowID(AddrType bankID) { return banks[bankID]->getOpenRowID(); }
  long  getForegroundEnergy();
  long  getBackgroundEnergy();
  void  updatePowerState();
  

  Time_t getLastRefresh() { return lastActivate; }
  Time_t getLastActivate() { return lastActivate; }
  Time_t getLastPrecharge() { return lastPrecharge; }
  Time_t getLastRead() { return lastRead; }
  Time_t getLastWrite() { return lastWrite; }

  void enableRefresh(double offset);
  bool isRefreshing();
  //int  neededRefreshes(AddrType bankID);
  bool canIssueRefresh(AddrType bankID);
  bool canIssuePrecharge(AddrType bankID);
  bool canIssueActivate(AddrType bankID);
  bool canIssueRead(AddrType bankID, AddrType rowID);
  bool canIssueWrite(AddrType bankID, AddrType rowID);

  //bool needsUrgentRefresh(){ return urgentRefresh; };
  //void setUrgentRefresh(bool _urgentRefresh) { urgentRefresh = _urgentRefresh; };

  void refresh(void);
  void precharge(AddrType bankID);
  void activate(AddrType bankID, AddrType rowID);
  void read(AddrType bankID, AddrType rowID);
  void write(AddrType bankID, AddrType rowID);

  typedef CallbackMember0<DDRxRank, &DDRxRank::refresh>   refreshCB;

  void prechargeAll(){
      for(int b=0; b < numBanks; ++b) {
          precharge(b);
      }
  };

///MnB:~ Dorsa
  //bool isRefreshing(int _bankID);
///:.
};


// DDRx Channel
class DDRxChannel {
protected:
  AddrType numRanks;
  AddrType numBanks;

  //uint loadBalancing;
  uint refAlgorithm;
  uint schAlgorithm;
  //uint reqQueueSize;
  uint schQueueSize;

  // internal resources
  std::vector<DDRxReference *> schQueue;
  std::vector<DDRxRank *> ranks;

  // DDRx timing parameters
  Time_t tREFI;   // Refresh Interval period
  Time_t tRFC;    // Refresh Cycle time
  Time_t tRTRS;   // Rank-To-Rank switching time
  Time_t tOST;    // Output Switching Time
  Time_t tCAS;    // Column Access Strobe latency (aka tCL)
  Time_t tCWD;    // Column Write Delay (aka tWL)
  Time_t tBL;     // Burst Length

  // DDRx power/energy parameters
  long cycleTime; // DRAM clock cycle time

  // Timestamp for the memory channel
  Time_t timeRefresh;
  Time_t lastRefresh;
  Time_t lastPrecharge;
  Time_t lastActivate;
  Time_t lastRead;
  Time_t lastWrite;
  Time_t consDelay;
  Time_t propDelay;

  // channel statistics
  GStatsCntr backEnergy;
  GStatsCntr foreEnergy;
  GStatsMax  peakPower;
  GStatsAvg  avrgPower;
  GStatsAvg  chanAvgOcc;
  GStatsAvg  chanAvgMAT;
  //GStatsMin  chanMinMAT;
  GStatsMax  chanMaxMAT;
//mani: transfer function required for data encoding
//  Transfer *transfer;
  GStatsHist  *s_modePattern;
  GStatsHist  *s_onesPattern;
  GStatsHist  *s_flipsPattern;
  GStatsHist  *s_flipsPerSlot;
  GStatsHist  *s_flipsPerSlotX;
  GStatsHist  *s_flipsPerSlotXX;
  GStatsHist  *s_encodingDelay;
  GStatsCntr  *s_wireFlips;
  GStatsCntr  *s_onesCount;
  GStatsCntr  *s_operations;
  GStatsHist  *s_chunkCount;
  GStatsCntr  *s_terminationEnergy;
  //GStatsCntr  *s_operationalEnergy;
  GStatsCntr  *s_totalDynEnergy;
  GStatsHist  *s_transMode;

  unsigned char binaryDataWire[64];        // bank:port:wire
  unsigned char binaryExtraWire[64];       // bank:port:wire
  unsigned char binaryHistWire[1024][64];  // bank:history:wire
  unsigned long ptrHist;                   // bank
  unsigned char binaryMaskWire[64];        // bank:port:wire
  unsigned long binaryCountWire[64];       // bank:port:wire
  unsigned long binaryAccess;              // bank:port

  bool enableTransfer;
  int64_t	  transferMode;
  int64_t     wires;
  int64_t     partitions;
  int64_t     segment;
  int32_t     lineSize;
  //double dynPower;
  //double dynPowerHybrid;
  //double termPower;
  //double termPowerHybrid;

/*
  AddrType channelID;

  // Par-BS marking cap
  ParBSRule rule;
  std::vector<ParBSRule> rules;
  int ParBSMarkCap;

  // TCMS
  unsigned long clusterThresh;
  std::vector<unsigned long> numMisses, MPKI, usedBW;
  std::vector<int> latencyCluster, bandwidthCluster;

*/

public:
  // constructor
  DDRxChannel(const char *section, const char *name, AddrType numRanks, AddrType numBanks);
  ~DDRxChannel() {};

  //int   getNumChannels() { return numChannels; }
  //DDRx *getNextChannel() { return nextChannel; }
  //void  setNextChannel(DDRx *_nextChannel) { nextChannel = _nextChannel; }

  STATE getBankState(AddrType rankID, AddrType bankID) { return ranks[rankID]->getBankState(bankID); }
  AddrType getOpenRowID(AddrType rankID, AddrType bankID) { return ranks[rankID]->getOpenRowID(bankID); }

  void clock();
  bool addReference(DDRxReference *mref);
  void updateQueueState();
  void updatePowerState();

  void enableRefresh(AddrType rankID, double offset);
  bool isRefreshing(AddrType rankID);
  //int  neededRefreshes(AddrType rankID, AddrType bankID);
  bool canIssueRefresh(AddrType rankID, AddrType bankID);
  bool canIssuePrecharge(AddrType rankID, AddrType bankID);
  bool canIssueActivate(AddrType rankID, AddrType bankID);
  bool canIssueRead(AddrType rankID, AddrType bankID, AddrType rowID);
  bool canIssueWrite(AddrType rankID, AddrType bankID, AddrType rowID);

  //void refresh(AddrType rankID, AddrType bankID);
  void precharge(AddrType rankID, AddrType bankID);
  void activate(AddrType rankID, AddrType bankID, AddrType rowID);
  void read(AddrType rankID, AddrType bankID, AddrType rowID);
  void write(AddrType rankID, AddrType bankID, AddrType rowID);

  // ElasticRefresh
  //bool consWait(AddrType rankID, AddrType bankID);
  //bool propWait(AddrType rankID, AddrType bankID);

  // DRAM refresh scheduler
  //void scheduleBasicRefresh();
  //void scheduleDUERefresh();
  //void scheduleElasticRefresh();

  // DRAM command scheduler
  void scheduleFCFS();
  void scheduleFRFCFS();
  //void scheduleTCMS();
  //void scheduleParBS();
  //void scheduleTEST();

  // Row buffer scheduler
  void scheduleRBClose();
/*
  //bool arrive(MemRequest *mreq);
  //void enqueue(DDRxReference *mref);

*/
  void performBurst();

  //int transfer(unsigned char *d);
  //int getHammingWeight(unsigned int value, unsigned int length);
  //void getChunks(unsigned int partitionSize, unsigned char * ptr);
  //struct Mask{
  //unsigned int value[8];
  //};
  //typedef HASH_MAP<unsigned int,Mask> maskMap;
  //maskMap M;

///MnB:~ Dorsa
/*
  #define C 4
  #define L 5
  #define N 1<<L

  class CountingBloomFilter{
      std::vector< std::vector<int> > cnt;

  public:
      CountingBloomFilter() {
          for(int c=0; c < C; ++c) {
              std::vector<int> tmp;
              for(int n=0; n < N; ++n) {
                  tmp.push_back(0);
              }
              cnt.push_back(tmp);
          }
      };

      int hash(int h, int a, int b, int c, int bw, int cw) {
          int l;
          int value = 0;
          int data  = ((((a<<bw)|b)<<cw)|c)>>h;

          for(l=0; l < L; ++l, data >>= C) {
              value = (value<<1)|(data&0x01);
          }
          for(data=l=0; l < L; ++l, value >>= 1) {
              data = (data<<1)|(value&0X01);
          }
          //printf("%d: %x %x %x %d %d => %x\n", h, a<<(bw+cw), b<<cw, c, bw, cw, data);
          return data;
      };

      // increment the counters
      void inc(int a, int b, int c, int bw, int cw) {
          for(int i=0; i < C; ++i) {
              ++cnt[i][hash(i, a, b, c, bw, cw)];
          }
      };

      // decrement the counters
      void dec(int a, int b, int c, int bw, int cw) {
          for(int i=0; i < C; ++i) {
              --cnt[i][hash(i, a, b, c, bw, cw)];
          }
      };

      // retrieve the counters
      int get(int a, int b, int c, int bw, int cw) {
          int min  = 1<<16;
          for(int i=0; i < C; ++i) {
              int tmp = cnt[i][hash(i, a, b, c, bw, cw)];
              if(min > tmp) {
                  min = tmp;
              }
          }
          if(min < 0) {
              printf("ERROR: a Bloom counter reached below 0!!");
              exit(0);
          }
          return min;
      };
  };

  CountingBloomFilter numPendRow;

  void addReqQueue(DDRxReference *mref) { reqQueue.push_back(mref); }
  int  getReqQueueSize() { return reqQueue.size(); }
  int  getNumPendReq() { return reqQueue.size()+schQueue.size();}
  int  getNumPendReq(AddrType _rankID) {
      int num=0;
      for(int i=0; i < reqQueue.size(); ++i) {
          if(reqQueue[i]->getRankID() == _rankID) {
              ++num;
          }
      }
      for(int i=0; i < schQueue.size(); ++i) {
          if(schQueue[i]->getRankID() == _rankID) {
              ++num;
          }
      }
      return num;
  }
  int  getNumPendReq(AddrType _rankID, AddrType _bankID) {
      int num=0;
      for(int i=0; i < reqQueue.size(); ++i) {
          if((reqQueue[i]->getRankID() == _rankID)&&(reqQueue[i]->getBankID() == _bankID)) {
              ++num;
          }
      }
      for(int i=0; i < schQueue.size(); ++i) {
          if((schQueue[i]->getRankID() == _rankID)&&(schQueue[i]->getBankID() == _bankID)) {
              ++num;
          }
      }
      return num;
  }
  int  getNumPendReq(AddrType _rankID, AddrType _bankID, AddrType _rowID) {
      int num=0;
      for(int i=0; i < reqQueue.size(); ++i) {
          if((reqQueue[i]->getRankID() == _rankID)&&(reqQueue[i]->getBankID() == _bankID)&&(reqQueue[i]->getRowID() == _rowID)) {
              ++num;
          }
      }
      for(int i=0; i < schQueue.size(); ++i) {
          if((schQueue[i]->getRankID() == _rankID)&&(schQueue[i]->getBankID() == _bankID)&&(schQueue[i]->getRowID() == _rowID)) {
              ++num;
          }
      }
      return num;
  }
  int  getNumPendRow(AddrType _rankID, AddrType _bankID) {
      std::vector<AddrType> rows;
      for(int i=0; i < reqQueue.size(); ++i) {
          if((reqQueue[i]->getRankID() == _rankID)&&(reqQueue[i]->getBankID() == _bankID)) {
              bool isDistinct = true;
              AddrType  row = reqQueue[i]->getRowID();
              for(int j=0; j < rows.size(); ++j) {
                  if(rows[j] == row) {
                      isDistinct = false;
                  }
              }
              if(isDistinct) {
                  rows.push_back(row);
              }
          }
      }
      for(int i=0; i < schQueue.size(); ++i) {
          if((schQueue[i]->getRankID() == _rankID)&&(schQueue[i]->getBankID() == _bankID)) {
              bool isDistinct = true;
              AddrType  row = schQueue[i]->getRowID();
              for(int j=0; j < rows.size(); ++j) {
                  if(rows[j] == row) {
                      isDistinct = false;
                  }
              }
              if(isDistinct) {
                  rows.push_back(row);
              }
          }
      }
      return rows.size();
  }
  int  getNumPendRow(AddrType _rankID) {
      int num = 0;
      for(int i=0; i < numBanks; ++i) {
          num += getNumPendRow(_rankID, i);
      }
      return num;
  }
  int  getNumPendRow() {
      int num = 0;
      for(int i=0; i < numRanks; ++i) {
          num += getNumPendRow(i);
      }
      return num;
  }
  bool isOpenRowID(AddrType _rankID, AddrType _bankID, AddrType _rowID) {
      return (_rowID == getOpenRowID(_rankID, _bankID));
  }
  bool isPendingRow(AddrType _rankID, AddrType _bankID, AddrType _rowID) {
      if(_rowID == getOpenRowID(_rankID, _bankID)) {
          return true;
      }
      else {
          for(int i=0; i < reqQueue.size(); ++i) {
              if((reqQueue[i]->getRankID() == _rankID)&&(reqQueue[i]->getBankID() == _bankID)&&(reqQueue[i]->getRowID() == _rowID)) {
                  return true;
              }
          }
          for(int i=0; i < schQueue.size(); ++i) {
              if((schQueue[i]->getRankID() == _rankID)&&(schQueue[i]->getBankID() == _bankID)&&(schQueue[i]->getRowID() == _rowID)) {
                  return true;
              }
          }
          return false;
      }
  }
//    unsigned long getParam(int nIndex) {
//        if(nIndex < params.size()) {
//            return params[nIndex];
//        }
//        return 0;
//    }
  bool checkReplicate(unsigned long long addr) {
      for(int i=0; i < params.size();  i+=2) {
          if((params[i] <= addr)&&(addr <= params[i+1])) {
              return true;
          }
      }
      return false;
  }
  bool isRefreshing(AddrType _rankID, AddrType _bankID) {
      return ranks[_rankID]->isRefreshing(_bankID);
  }
*/
///:.
};


// DDRx Interface
class DDRx: public MemObj {
protected:
  uint addrMapping;
  bool DDRxBypassed;
  AddrType size;
  AddrType numChannels;
  AddrType numRanks;
  AddrType numBanks;
  AddrType pageSize;
  AddrType llcBlkSize;
  AddrType llcSize;
  AddrType llcAssoc;

  AddrType softPageSize;
  AddrType softPageSizeLog2;

  AddrType numChannelsLog2;
  AddrType numRanksLog2;
  AddrType numBanksLog2;
  AddrType pageSizeLog2;
  AddrType llcBlkSizeLog2;
  AddrType llcEffSizeLog2;

  // internal resources
  std::vector<DDRxChannel *> channels;
  std::queue<DDRxReference *> receivedQueue;

  // DDRx statistics
  GStatsCntr countReceived;
  GStatsCntr countServiced;

  //GStatsFreq freqBlockUsage;
  //GStatsFreq freqPageUsage;
  //GStatsFreq freqFootPrint;
  //GStatsTrac tracFootPrint;

  GStatsAvg  avgAccessTime;
  GStatsTrac tracAccessTime;

public:
  DDRx(MemorySystem* current, const char *section, const char *device_name = NULL);
  ~DDRx() {};

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
  void finishDDRx(void);
  void manageDDRx(void);

  typedef CallbackMember0<DDRx, &DDRx::manageDDRx>   ManageDDRxCB;
  bool clockScheduled;
};

#endif  // DDRx_H

