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


#ifndef WideIO_H
#define WideIO_H

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


static unsigned long V, R, X, Y, P, C;

// request count type
typedef struct _REQCOUNT {
    uint rowCount;
    uint bankCount;
    uint rankCount;
    uint vaultCount;
} ReqCount;

// writeback type
typedef struct _WideIOWriteBack {
    AddrType maddr;
    void *mdata;
} WideIOWriteBack;

// Tag Type
typedef struct _TagType {
    bool valid;
    bool dirty;
    bool prefetch;  // fromHunter for Miss Coverage
    //long count;
    //long waddr;
    AddrType value;
    //AddrType maddr;
    //struct _TagType *next;
} TagType;

// Tag Row Structure
class TagRow {
    //std::vector<TagType *> tagSets;
    std::vector< std::vector<TagType> > tagSets;
    //std::vector<int> numTags;
    AddrType rowID;
    bool valid;
    bool dirty;
    //bool loading;
    //bool readOnly;
    long close;

public:
    TagRow() {
        valid = false;
        dirty = false;
        //loading = false;
        //readOnly = false;
        close = 0;
    }
    ~TagRow() {
    }
    void setTagRow(TagRow inp, AddrType rowID) {
        valid = true;
        dirty = false;
        this->rowID = rowID;
        if(inp.valid) {
            for(int i=0; i < inp.tagSets.size(); ++i) {
                if(i >= tagSets.size()) {
                    std::vector<TagType> set;
                    tagSets.push_back(set);
                }
                tagSets[i].clear();
                for(int j=0; j < inp.tagSets[i].size(); ++j) {
                    tagSets[i].push_back(inp.tagSets[i][j]);
                }
            }
        }
        else {
            for(int i=0; i < tagSets.size(); ++i) {
                for(int j=0; j < tagSets[i].size(); ++j) {
                    tagSets[i][j].valid = false;
                    tagSets[i][j].dirty = false;
                    tagSets[i][j].value = 0;
                }
            }
        }
    }
    void addSet(int num) {
        std::vector<TagType> set;
        for(int i=0; i < num; ++i) {
            TagType tag;
            tag.valid = false;
            tag.dirty = false;
            tag.prefetch = false; // fromHunter for Miss Coverage
            tag.value = 0;
            set.push_back(tag);
        }
        tagSets.push_back(set);
    }
    long getVictimIndex(AddrType setID) {
        if((setID >= tagSets.size()) || (tagSets[setID].size() == 0)) {
            return -1;
        }
        return tagSets[setID].size() - 1;
    }
    bool accessTagIndex(AddrType setID, long index, bool dirty) {
        if((setID >= tagSets.size()) || (index >= tagSets[setID].size()) || (index < 0)) {
            return false;
        }
        TagType tag = tagSets[setID][index];
        if(dirty) {
            tag.dirty = true;
            this->dirty = true;
        }
        tagSets[setID].erase(tagSets[setID].begin()+index);
        tagSets[setID].insert(tagSets[setID].begin(), tag);
        return true;
    }
    bool setTagIndexAsPrefetch(AddrType setID, long index) {  // fromHunter for Miss Coverage
        if((setID >= tagSets.size()) || (index >= tagSets[setID].size()) || (index < 0)) {
            return false;
        }
        TagType tag = tagSets[setID][index];
        tag.prefetch = true;
        return true;
    }
    bool getSetIndexPrefetch(AddrType setID, long index) {    // fromHunter for Miss Coverage
        TagType tag = tagSets[setID][index];
        return tag.prefetch;
    }
    bool setIndexTag(TagType tag, AddrType setID, long index) {
        if((setID >= tagSets.size()) || (index >= tagSets[setID].size())) {
            return false;
        }
        tagSets[setID][index] = tag;
        return true;
    }
    TagType getIndexTag(AddrType setID, long index) {
        I(setID<tagSets.size());
        I(index<tagSets[setID].size);
        return tagSets[setID][index];
    }
    void setIndexTag(AddrType setID, long index, TagType tag) {
        I(setID<tagSets.size());
        I(index<tagSets[setID].size);
        tagSets[setID][index] = tag;
    }
    bool installTag(AddrType setID, AddrType tagID, bool p = false) {
        long index = getVictimIndex(setID);
        if(index == -1) {
            return false;
        }
        TagType tag;
        tag.valid = true;
        tag.dirty = false;
        tag.prefetch = p;   //fromHunter for Miss Coverage
        tag.value = tagID;
        setIndexTag(tag, setID, index);
        accessTagIndex(setID, index, false);
        valid = true;
        dirty = true;
    }
    bool needsUpdate() {
        return valid && dirty;
    }
    bool needsRowClose(AddrType rowID) {
    	return valid && dirty && (this->rowID != rowID);
    }
    void clear() {
        dirty = false;
    }
    bool isValid() {
        return valid;
    }
    //void setClose(bool value) {
    //  close += value? 1: -1;
    //}
    //bool getClose() {
    //  return close > 0;
    //}
    AddrType getRowID() {
        return rowID;
    }
    bool matchRowID(AddrType rowID) {
        return valid && (this->rowID == rowID);
    }
    std::vector<TagType> getSet(AddrType setID) {
        I(setID < tagSets.size());
        return tagSets[setID];
    }
    void printSet(AddrType setID) {
        I(setID < tagSets.size());
        printf("-> ");fflush(stdout);
        for(int i=0; i < tagSets[setID].size(); ++i) {
            printf("|%s-%s-%016lX", tagSets[setID][i].valid? "V": "I", tagSets[setID][i].dirty? "D": "C", tagSets[setID][i].value);fflush(stdout);
        }
        printf("|\n");fflush(stdout);
    }
    void print() {
        printf("== %s %s %016lX %ld sets [", valid? "V": "I", dirty? "D": "C", rowID, tagSets.size());fflush(stdout);
        for(int i=0; i < tagSets.size(); ++i) {
            if(i != 0) {
                printf(" ");
            }
            printf("%ld", tagSets[i].size());
        }
        printf("]\n");
        for(int i=0; i < tagSets.size(); ++i) {
            printSet(i);
        }
        printf("\n");fflush(stdout);
    }
};


// Memory Reference
class WideIOReference {
  ReferenceState state;
  WideIOReference *prev, *next;
  bool canceled;
  bool was_prefetch;  //fromHunter
public:
  void addSibling(WideIOReference *mref) {
      if((this->prev == NULL) && (this->next == NULL)) {
          this->prev = mref;
          this->next = mref;
          mref->prev = this;
          mref->next = this;
      }
      else if((this->prev != NULL) && (this->next != NULL)) {
          WideIOReference *temp = this->next;
          temp->prev = mref;
          this->next = mref;
          mref->prev = this;
          mref->next = temp;
      }
      else {
          printf("ERROR: invalid state for the dolfer linked list!\n");
          exit(0);
      }
  }
  void updateSiblings(bool canceled) {
      WideIOReference *temp = this->next;
      while((mreq != NULL) && (temp != NULL) && (temp != this)) {
          temp->canceled = canceled;
          temp->mreq = NULL;
          temp = temp->next;
      }
  }
  void printSiblings() {
      bool done = false;
      WideIOReference *temp = this;
      while ((done != true) && (temp != NULL)) {
          temp->printState();
          temp->printLog();
          temp = temp->next;
          done = temp == this;
      }
  }
  bool isCanceled() { return canceled; }
  bool wasPrefetch() { return this->was_prefetch; }
  void setAsPrefetch() { this->was_prefetch = true; }
  void setState(ReferenceState state) { this->state = state; addLog("( %s )", ReferenceStateStr[state]); }
  ReferenceState getState() { return state; }
  WideIOReference *front, *back;

protected:
  // arrival time of this reference to the DRAM queue
  //Time_t timeStamp;
  Time_t birthTime;
  Time_t climbTime;
  Time_t deathTime;
  Time_t checkTime;

  // MemRequest that made this reference
  AddrType maddr;
  MemRequest *mreq;
  std::vector<MemRequest *> lreqs;
  //std::queue<TagType> toWriteback;
  std::vector<uint64_t> to_prefetch; //fromHunter

  // DRAM coordinates
  AddrType vaultID;
  AddrType rankID;
  AddrType bankID;
  AddrType rowID;
  AddrType colID;
  AddrType setID;
  AddrType blkID;
  AddrType tagID;
  AddrType blkSize;
  AddrType blkSizeLog2;
  AddrType openRowID;

  // next needed DRAM command
  //bool tagCheckPending;
  bool prechargePending;
  bool activatePending;
  bool writePending;
  bool readPending;
  bool updatePending;
  bool loadPending;
  bool burstPending;
  BurstType burstType;
  bool read;
  bool sentUp;
  long blkCount;
  long fchCount;
  long insCount;
  long evcCount;
  long wbkCount;
  long numGrain;
  long numGrainLog2;
  //long mreqType;
  bool folded;
  bool replica;
  bool tagIdeal;
  long numMatch;
  long numPrefetchMatch = 0;  //fromHunter for Miss Coverage
  long numRead;
  long numWrite;
  long numLoad;
  long numUpdate;
  long numEvict;
  long numInstall;
  long numConflict;

  // HBM Cache
  TagRow tagRow;

public:
  // constructor
  WideIOReference();
  ~WideIOReference() {
    //printLog();
    //printSiblings();
    clearLog();
    //exit(0);
  }

  void setMReq(MemRequest *mreq) { this->mreq = mreq; }
  void setMAddr(AddrType maddr) { this->maddr = maddr; }
  void setVaultID(AddrType vaultID) { this->vaultID = vaultID; }
  void setRankID(AddrType rankID) { this->rankID = rankID; }
  void setBankID(AddrType bankID) { this->bankID = bankID; }
  void setRowID(AddrType rowID) { this->rowID = rowID; }
  void setColID(AddrType colID) { this->colID = colID; }
  void setSetID(AddrType setID) { this->setID = setID; }
  void setTagID(AddrType tagID) { this->tagID = tagID; }
  void setTagRow(TagRow tagRow) { this->tagRow = tagRow; }
  void setOpenRowID(AddrType openRowID) { this->openRowID = openRowID; }
  void setToPrefetch(std::vector<uint64_t> to_prefetch) {this->to_prefetch = to_prefetch; }

  void setFolded(bool folded) { this->folded = folded; }
  bool isFolded() { return folded; }
  void setReplica(bool replica) { this->replica = replica; }
  bool isReplica() { return replica; }

  void setLoadPending(bool loadPending) { this->loadPending = loadPending; }
  void setUpdatePending(bool updatePending) { this->updatePending = updatePending; }
  void setPrechargePending(bool prechargePending) { this->prechargePending = prechargePending; }
  void setActivatePending(bool activatePending) { this->activatePending = activatePending; }
  void setReadPending(bool readPending) { this->readPending = readPending; }
  void setWritePending(bool writePending) { this->writePending = writePending; }
  void setRead(bool read) { this->read = read; }
  void setBurstPending(bool burstPending, BurstType burstType) { this->burstPending = burstPending; this->burstType = burstType; }

  Time_t getBirthTime() { return birthTime; }
  Time_t getTagDelay() { return checkTime - birthTime; }
  Time_t getMReqDelay() { return climbTime - birthTime; }
  Time_t getMRefDelay() { return deathTime - birthTime; }
  MemRequest *getMReq() { return mreq; }
  AddrType getMAddr() { return maddr; }
  std::vector<uint64_t> getToPrefetch() {return to_prefetch; }

  AddrType  getVaultID() { return vaultID; }
  AddrType  getRankID() { return rankID; }
  AddrType  getBankID() { return bankID; }
  AddrType  getRowID() { return rowID; }
  AddrType  getColID() { return colID; }
  AddrType  getSetID() { return setID; }
  AddrType  getTagID() { return tagID; }
  TagRow  getTagRow() { return tagRow; }
  AddrType  getOpenRowID() { return openRowID; }

  void setTagIdeal(bool tagIdeal) { this->tagIdeal = tagIdeal; }
  void incNumRead() { numRead++; }
  void incNumWrite() { numWrite++; }
  void incNumLoad() { numLoad++; }
  void incNumUpdate() { numUpdate++; }
  void incNumEvict() { numEvict++; }
  void incNumInstall() { numInstall++; }
  void incNumConflict() { numConflict++; }

  long getNumMatch() { return numMatch; }
  long getNumPrefetchMatch() { return numPrefetchMatch; }
  long getNumRead() { return numRead; }
  long getNumWrite() { return numWrite; }
  long getNumLoad() { return numLoad; }
  long getNumUpdate() { return numUpdate; }
  long getNumEvict() { return numEvict; }
  long getNumInstall() { return numInstall; }
  long getNumConflict() { return numConflict; }
  long doTagCheck(std::vector<TagType> set) {
    checkTime = globalClock;
    if(tagIdeal) {
        numMatch++;
        return 0;
    }
    for(int i=0; i < set.size(); ++i) {
      if((set[i].valid == true) && (set[i].value == tagID)) {
          numMatch++;
          if (set[i].prefetch == true) {  //fromHunter for Miss Coverage
            numPrefetchMatch++;
          }
          return i;
      }
    }
    return -1;
  }
  bool checkIfPrefetch(std::vector<TagType> set, long i) {  //fromHunter for Miss Coverage
    if (set[i].prefetch == true)
      return true;
    else return false;
  }
  void setBlkSize(long blkSize) {
    this->blkSize = blkSize;
    this->blkSizeLog2 = log2(blkSize);
  }
  void setNumGrain(long numGrain) {
    this->numGrain = numGrain;
    this->numGrainLog2 = log2(numGrain);
  }
  long getNumGrain() { return numGrain; }
  AddrType getGrainAddr(long gid) {
    return (((maddr >> (numGrainLog2 + blkSizeLog2)) << numGrainLog2) + gid) << blkSizeLog2;
  }

  bool needsTagLoad() { return (state == READTAG) || (state == DOPLACE); }
  bool needsSchedule() { return (state == SCRATCH) || (state == READTAG) || (state == MATCHED) || (state == DOPLACE) || (state == DOEVICT) || (state == INSTALL); }
  bool needsPrecharge() { return prechargePending; }
  bool needsActivate() { return activatePending; }
  bool needsWrite() { return writePending; }
  bool needsRead() { return readPending; }
  bool needsUpdate() { return updatePending; }
  bool needsLoad() { return loadPending; }
  bool needsEviction() { return (state == DOEVICT); }
  bool needsInstall() { return (state == INSTALL); }
  bool isRead() { return read; }
  BurstType getBurstType() { return burstType; }
  bool isOutBurst() { return (burstType == READ) || (burstType == LOAD); }
  bool needsBurst() { return burstPending; }
  bool isSentUp() { return sentUp; }
  bool incBlkCount() {
    return (++blkCount >= numGrain);
  }
  bool incFchCount() {
    return (++fchCount >= numGrain);
  }
  bool incInsCount() {
    return (++insCount >= numGrain);
  }
  bool incEvcCount() {
    return (++evcCount >= numGrain);
  }
  bool incWbkCount() {
    return (++wbkCount >= numGrain);
  }

  // sending a response up
  void sendUp();

//////////////
  std::vector<char *> logText;
  std::vector<Time_t> logTime;
  void addLog(const char *format, ...);
  void clearLog() {
    while(logText.size()) {
      free(logText[0]);
      logText.erase(logText.begin());
      logTime.erase(logTime.begin());
    }
  }
  void printLog() {
    printf("%s%s\t0x%lx\n", read? "READ": "WRITE", folded? "-F": "", maddr);
    printf("\tbirth: %lu\tclimb: %lu\tcheck: %lu\tdeath: %lu\n", birthTime, checkTime, climbTime, deathTime);
    for(long i = 0; i < logText.size(); ++i) {
      printf("\t@ %lu\t%s\n", logTime[i], logText[i]);
    }
    printf("\n");
  }
  void printState() {
    printf("%s 0x%lx [%ld:%ld:%ld:%ld:%ld]\n", read? "READ": "WRITE", maddr, vaultID, rankID, bankID, rowID, colID);
    printf(" state            = %s\n", ReferenceStateStr[state]);
    printf(" updatePending    = %s\n loadPending      = %s\n prechargePending = %s\n activatePending  = %s\n writePending     = %s\n readPending      = %s\n burstPending     = %s\n sentUp           = %s\n", updatePending ? "true": "false", loadPending ? "true": "false", prechargePending ? "true": "false", activatePending  ? "true": "false", writePending     ? "true": "false", readPending      ? "true": "false", burstPending     ? "true": "false", sentUp           ? "true": "false");
  }
//////////////
};


// linked list structure of references
class WideIORefList {
protected:
    long count;
    WideIOReference *tail;
public:
    WideIORefList() {
        count = 0;
        tail = NULL;
    }
    ~WideIORefList() {};
    void append(WideIOReference *mref) {
        if(tail == NULL) {
            tail = mref;
            tail->front = NULL;
            tail->back  = NULL;
        }
        else {
            mref->front = tail;
            mref->back  = NULL;
            tail->back  = mref;
            tail = mref;
        }
        count++;
    }
    void remove(WideIOReference *mref) {
        WideIOReference *front = mref->front;
        WideIOReference *back  = mref->back;
        if(front != NULL) {
            if(back != NULL) {
                front->back = back;
                back->front = front;
            }
            else {
                tail = front;
                tail->back = NULL;
            }
        }
        else {
            if(back != NULL) {
                back->front = NULL;
            }
            else {
                tail = NULL;
            }
        }
        count--;
    }
};

// WideIO Bank
class WideIOBank {
protected:
  // Bank state
  STATE state;
  AddrType openRowID;
  AddrType lastOpenRowID;
  AddrType nextOpenRowID;

  // Timestamp for the memory bank
  Time_t lastAction;
  Time_t lastRefresh;
  Time_t lastPrecharge;
  Time_t lastActivate;
  Time_t lastRead;
  Time_t lastWrite;

  // row buffer hit flag
  bool rowHit;
  bool pending;
  bool fetching;
  uint readCount;

  // bank statistics
  GStatsCntr numReads;
  GStatsCntr numWrites;
  GStatsCntr numActivates;
  GStatsCntr numPrecharges;
  GStatsCntr numRefreshes;
  GStatsCntr numRowHits;
  GStatsCntr numRowMisses;

  // Cache
  std::vector<TagRow> tags;

public:
  // Costructor
  WideIOBank(const char *name, AddrType numRows);
  ~WideIOBank() {};

  void setState(STATE _state) { state = _state; }
  void setOpenRowID(AddrType _openRowID) { openRowID = _openRowID; }

  void refresh();
  void precharge();
  void activate(AddrType rowID);
  TagRow read(AddrType colID);
  void write(AddrType colID, TagRow *tagRow);
  void precharge_ideal();
  void activate_ideal(AddrType rowID);
  TagRow read_rowID(AddrType rowID, AddrType colID);
  void write_rowID(AddrType rowID, AddrType colID, TagRow *tagRow);

  STATE getState() { return state; }
  AddrType getOpenRowID() { return openRowID; }
  //AddrType getLastOpenRowID() { return lastOpenRowID; }
  //AddrType getNextOpenRowID() { return nextOpenRowID; }
  //std::vector<TagType> *getOpenRow() { return &tags[openRowID]; }

  Time_t getLastAction() { return lastAction; }
  Time_t getLastRefresh() { return lastRefresh; }
  Time_t getLastPrecharge() { return lastPrecharge; }
  Time_t getLastActivate() { return lastActivate; }
  Time_t getLastRead() { return lastRead; }
  Time_t getLastWrite() { return lastWrite; }

  void setPending(bool pending) { this->pending = pending; }
  bool getPending() { return pending; }
  uint getReadCount() { return readCount; }
  void setFetching(bool fetching) { this->fetching = fetching; }
  bool getFetching() { return fetching; }
};


// WideIO Rank
class WideIORank {
protected:
  AddrType numBanks;
  AddrType numBanksLog2;

  EMR  emr;
  POWERSTATE powerState;
  bool cke;
  //bool urgentRefresh;
  long rankEnergy;

  // Timestamp for the memory rank
  //Time_t timeRefresh;
  Time_t lastRefresh;
  Time_t lastPrecharge;
  Time_t lastActivate;
  Time_t lastActive_1;
  Time_t lastActive_2;
  Time_t lastRead;
  Time_t lastWrite;

  // WideIO timing parameters
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

  // WideIO power/energy parameters
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
  //long cycleTime; // DRAM clock cycle time
  //long numChips;  // Number of chips per rank

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
  std::vector<WideIOBank *> banks;

/*
  // rank statistics
  //GStatsHist stampRefresh;
*/

public:
  // Costructor
  WideIORank(const char *section, const char *name, AddrType numBanks, AddrType numRows);
  ~WideIORank() {};

  STATE getBankState(AddrType bankID) { return banks[bankID]->getState(); }
  AddrType getOpenRowID(AddrType bankID) { return banks[bankID]->getOpenRowID(); }
  //AddrType getLastOpenRowID(AddrType bankID) { return banks[bankID]->getLastOpenRowID(); }
  //AddrType getNextOpenRowID(AddrType bankID) { return banks[bankID]->getNextOpenRowID(); }
  //std::vector<TagType> *getOpenRow(AddrType bankID) { return banks[bankID]->getOpenRow(); }
  long  getForegroundEnergy();
  long  getBackgroundEnergy();
  void  updatePowerState();

  Time_t getLastBankPrecharge(AddrType bankID) { return banks[bankID]->getLastPrecharge(); }
  Time_t getLastBankAction(AddrType bankID) { return banks[bankID]->getLastAction(); }

  Time_t getLastRefresh() { return lastActivate; }
  Time_t getLastActivate() { return lastActivate; }
  Time_t getLastPrecharge() { return lastPrecharge; }
  Time_t getLastRead() { return lastRead; }
  Time_t getLastWrite() { return lastWrite; }

  void enableRefresh(double offset);
  bool isRefreshing();
  //int  neededRefreshes(AddrType bankID);
  //bool canIssueRefresh(AddrType bankID);
  bool canIssuePrecharge(AddrType bankID);
  bool canIssueActivate(AddrType bankID);
  bool canIssueRead(AddrType bankID, AddrType rowID);
  bool canIssueWrite(AddrType bankID, AddrType rowID);

  //bool needsUrgentRefresh(){ return urgentRefresh; };
  //void setUrgentRefresh(bool _urgentRefresh) { urgentRefresh = _urgentRefresh; };

  void refresh(void);
  void precharge(AddrType bankID);
  void activate(AddrType bankID, AddrType rowID);
  TagRow read(AddrType bankID, AddrType colID);
  void write(AddrType bankID, AddrType colID, TagRow *tagRow);
  void precharge_ideal(AddrType bankID);
  void activate_ideal(AddrType bankID, AddrType rowID);
  TagRow read_rowID(AddrType bankID, AddrType rowID, AddrType colID);
  void write_rowID(AddrType bankID, AddrType rowID, AddrType colID, TagRow *tagRow);

  void setPending(AddrType bankID, bool pending) { banks[bankID]->setPending(pending); }
  bool getPending(AddrType bankID) { return banks[bankID]->getPending(); }
  uint getReadCount(AddrType bankID) { return banks[bankID]->getReadCount(); }
  void setFetching(AddrType bankID, bool fetching) { banks[bankID]->setFetching(fetching); }
  bool getFetching(AddrType bankID) { return banks[bankID]->getFetching(); }

  typedef CallbackMember0<WideIORank, &WideIORank::refresh>   refreshCB;
};


// WideIO Vault
class WideIOVault {
protected:
  AddrType rowSize;
  AddrType blkSize;
  AddrType tagSize;
  AddrType setSize;
  AddrType grnSize;
  AddrType numBlks;
  AddrType numWays;
  AddrType numSets;
  AddrType numRanks;
  AddrType numBanks;
  AddrType numRows;

  AddrType blkSizeLog2;
  AddrType grnSizeLog2;

  //AddrType softPage;
  //AddrType softPageLog2;

  uint schQueueSize;
  uint repQueueSize;
  //uint refAlgorithm;
  uint schAlgorithm;
  uint rowAlgorithm;
  //uint cachingMode;
  //uint fetchRowSize;
  //uint mtypeControl;
  //uint alphaCounter;
  //uint gammaCounter;
  long long counter;

  // internal resources
  std::vector<WideIOReference *> schQueue;
  std::vector<WideIOReference *> repQueue;
  std::queue<WideIOReference *> retQueue;
  std::vector<WideIORank *> ranks;
  std::vector< std::vector<TagRow> > tagBuffer;
  bool inputRefReceived;
  bool tagBufferUpdated;
  bool retunReqReceived;
  bool bankRowActivated;

  // WideIO timing parameters
  Time_t tREFI;   // Refresh Interval period
  Time_t tRFC;    // Refresh Cycle time
  Time_t tRTRS;   // Rank-To-Rank switching time
  Time_t tOST;    // Output Switching Time
  Time_t tCAS;    // Column Access Strobe latency (aka tCL)
  Time_t tCWD;    // Column Write Delay (aka tWL)
  Time_t tBL;     // Burst Length

  // Timestamp for the memory vault
  //Time_t timeRefresh;
  Time_t lastRefresh;
  Time_t lastPrecharge;
  Time_t lastActivate;
  Time_t lastRead;
  Time_t lastWrite;

  // vault statistics
  GStatsCntr backEnergy;
  GStatsCntr foreEnergy;


public:
  // constructor
  WideIOVault(const char *section, const char *name, AddrType numRanks, AddrType numBanks, AddrType numRows);
  ~WideIOVault() {};

  STATE getBankState(AddrType rankID, AddrType bankID) { return ranks[rankID]->getBankState(bankID); }
  AddrType getOpenRowID(AddrType rankID, AddrType bankID) { return ranks[rankID]->getOpenRowID(bankID); }

  Time_t getLastBankPrecharge(AddrType rankID, AddrType bankID) { return ranks[rankID]->getLastBankPrecharge(bankID); }
  Time_t getLastBankAction(AddrType rankID, AddrType bankID) { return ranks[rankID]->getLastBankAction(bankID); }

  void clock();
  bool isFull();
  void addReference(WideIOReference *mref);
  void retReference(WideIOReference *mref);
  void updateQueueState();
  void updatePowerState();

  void enableRefresh(AddrType rankID, double offset);
  bool isRefreshing(AddrType rankID);
  //bool canIssueRefresh(AddrType rankID, AddrType bankID);
  bool canIssuePrecharge(AddrType rankID, AddrType bankID);
  bool canIssueActivate(AddrType rankID, AddrType bankID);
  bool canIssueRead(AddrType rankID, AddrType bankID, AddrType rowID);
  bool canIssueWrite(AddrType rankID, AddrType bankID, AddrType rowID);

  void precharge(AddrType rankID, AddrType bankID);
  void activate(AddrType rankID, AddrType bankID, AddrType rowID);
  TagRow read(AddrType rankID, AddrType bankID, AddrType rowID, AddrType colID);
  void write(AddrType rankID, AddrType bankID, AddrType rowID, AddrType colID, TagRow *tagRow);
  void precharge_ideal(AddrType rankID, AddrType bankID);
  void activate_ideal(AddrType rankID, AddrType bankID, AddrType rowID);

  // DRAM command scheduler
  void scheduleFCFS();
  void scheduleFRFCFS();
  void scheduleTEST();
  void scheduleDATA();

  // Row buffer scheduler
  void scheduleRBClose();
  //void scheduleRBLatch();
  //void scheduleRBCache();
  //void scheduleRBFetch();
  //void scheduleRBReAct();
  //void scheduleRBReTag();

  // Install scheduler
  void scheduleInstall();

  ReqCount getReqCount(AddrType rankID, AddrType bankID, AddrType rowID);

  void performBurst();
  void performTagCheck();
  void performReplace();
  void receiveReturned();
};


// WideIO Interface
class WideIO: public MemObj {
protected:

  //uint addrMapping; 
  bool do_prefetching = true; // fromHunter

  bool prefetch_all_reqs = false;    // fromHunter
  bool prefetch_only_misses = false; // fromHunter

  bool prefetch_with_bingo = true;   // fromHunter
  bool bingo_prefetch_only_misses = true; //fromHunter  // BINGO has its own method of deciding when to prefetch or not, but I'm seeing better results
                                                        // only listening to their suggestion when the current request is a DRAM miss

  bool prefetch_with_bop = false;  //fromHunter    // Note you also need to uncomment to include 'bop.cpp'

  bool init_done = false;     // fromHunter
  uint dispatch;
  uint num_total_requests;
  uint num_cycles;
  AddrType softPage;
  AddrType memSize;
  AddrType hbmSize;
  AddrType rowSize;
  AddrType blkSize;
  AddrType numVaults;
  AddrType numRanks;
  AddrType numBanks;
  AddrType numRows;

  //AddrType numScouts;
  //uint maxScout;
  //typedef struct _Scout {
  //  AddrType mpage;
  //  long count;
  //  bool recent;
  //} Scout;
  //std::vector<Scout> scouts;
  //typedef struct _Folder {
  // AddrType mpage;
  // long count;
  //} Folder;
  //AddrType foldOffset;
  //AddrType numFolders;
  //uint maxFolder;
  //std::vector<Folder> folders;

  AddrType softPageLog2;
  AddrType memSizeLog2;
  AddrType hbmSizeLog2;
  AddrType rowSizeLog2;
  AddrType blkSizeLog2;
  AddrType numVaultsLog2;
  AddrType numRanksLog2;
  AddrType numBanksLog2;
  AddrType numRowsLog2;

  // internal resources
  std::vector<WideIOVault *> vaults;
  std::queue<WideIOReference *> receivedQueue;
  //WideIORefList pendingList;

  // WideIO statistics
  GStatsCntr  countReceived;
  GStatsCntr  countServiced;
  GStatsCntr  countSentLower;
  GStatsCntr  countWriteBack;
  GStatsCntr  countSkipped;

  GStatsPie   pieTagAccess;
  GStatsCntr  countHit;
  GStatsCntr  countMiss;
  GStatsCntr  countRead;
  GStatsCntr  countWrite;
  GStatsCntr  countLoad;
  GStatsCntr  countUpdate;
  GStatsCntr  countEvict;
  GStatsCntr  countInstall;
  GStatsTrac  tracHitRatio;

  GStatsCntr countMissesSaved;    //fromHunter for Miss Coverage
  GStatsCntr countOverPredicted;  //fromHunter for Miss Coverage

  //GStatsPie  pieRowAccess;
  //GStatsCntr countCurTogo;
  //GStatsCntr countPreTogo;
  //GStatsCntr countNxtTogo;
  //GStatsCntr countCurPend;
  //GStatsCntr countPrePend;
  //GStatsCntr countNxtPend;

  //GStatsPie  pieBlkAccess;
  //GStatsCntr countDieHits;
  //GStatsCntr countCurHits;
  //GStatsCntr countPreHits;
  //GStatsCntr countNxtHits;
  //GStatsCntr countDieMiss;
  //GStatsCntr countCurMiss;
  //GStatsCntr countPreMiss;
  //GStatsCntr countNxtMiss;

  GStatsFreq freqBlockUsage;
  GStatsFreq freqBlockAccess;
  //GStatsFreq freqPageUsage;
  //GStatsTrac tracSkipRatio;
  //GStatsHeat heatRead;
  //GStatsHeat heatWrite;
  //GStatsHeat heatReadHit;
  //GStatsHeat heatWriteHit;
  //GStatsHeat heatBlockMiss;
  //GStatsHeat heatBlockUsage;
  GStatsHist histConflicts;

  GStatsAvg  avgAccessTime;
  GStatsTrac tracAccessTime;
  GStatsAvg  avgTCheckTime;
  GStatsTrac tracTCheckTime;
  GStatsHist histTCheckTimes;


public:
  WideIO(MemorySystem* current, const char *section, const char *device_name = NULL);
  ~WideIO() {};

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
  bool sendToVault(WideIOReference *mref);
  void doSkipBlocks(void);
  void doPrefetcher(void);  //fromHunter
  void completeMRef(void);
  void doWriteBacks(void);
  void doFetchBlock(void);
  void finishWideIO(void);
  void dispatchRefs(void);
  void manageWideIO(void);

  static bool isBorder(unsigned long x, unsigned long  y) { return ((x & ((1<<C)-1)) == (x>>C)) || ((y & ((1<<P)-1)) == (y>>P)); }
  static unsigned long computeDimX(void) { return (1 << (V + X + C)) + (1 << (V + X)) + 1; }
  static unsigned long computeDimY(void) { return (1 << (R + Y + P)) + (1 << (R + Y)) + 1; }
  static unsigned long computeX(unsigned long p) {
    //return (((p >> C) & ((1<<V)-1)) << (X+C)) | (((p >> (R+V+C)) & ((1<<X)-1)) << C) | (p & ((1<<C)-1));
    unsigned long x = (((p>>(R+Y+X+C))&((1<<V)-1))<<(X+C)) | (p&((1<<(X+C))-1));
    return 1 + x + (x>>C);
  }
  static unsigned long computeY(unsigned long p) {
    //return (((p >> (V+C)) & ((1<<R)-1)) << (Y+P)) | (((p >> (X+R+V+C)) & ((1<<Y)-1)) << (P)) | ((p >> (Y+X+R+V+C)) & ((1<<P)-2));
    unsigned long y = (((p>>(Y+X+C))&((1<<R)-1))<<(Y+P)) | (((p>>(X+C))&((1<<Y)-1))<<P) | ((p>>(V+R+Y+X+C))&((1<<P)-1));
    return 1 + y + (y>>P);
  }

  typedef CallbackMember0<WideIO, &WideIO::manageWideIO>   ManageWideIOCB;
  bool clockScheduled;
};

#endif  // WideIO_H
