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


#include "SescConf.h"
#include "MemorySystem.h"
#include "DDRx.h"
//#include <iostream>
//#include "stdlib.h"
//#include <queue>
//#include <cmath>


// DDRx clock, scaled wrt globalClock
//Time_t globalClock;
Time_t DDRxMultiplier;
std::queue<ServicedRequest> DDRxServicedQ;


// memory reference constructor
DDRxReference::DDRxReference()
  /* constructor {{{1 */
  : timeStamp(0)
  , mreq(NULL)
  , rankID(0)
  , bankID(0)
  , rowID(0)
  , prechargePending(true)
  , activatePending(true)
  , readPending(true)
  , writePending(true)
  , ready(false)
  , mark(false)
  , read(true)
  // data added to DDRxReference
  //, data(NULL)
{
  // nothing to do
}

// finishing memory service
Time_t DDRxReference::complete() {
  //Time_t when = 0;
  ServicedRequest sreq;
  sreq.time = globalClock - timeStamp;
  sreq.mreq = mreq;
  DDRxServicedQ.push(sreq);
  return globalClock - timeStamp;
}



// bank constructor
DDRxBank::DDRxBank(const char *name)
  : state(IDLE)
  , openRowID(0)
  , lastRefresh(0)
  , lastPrecharge(0)
  , lastActivate(0)
  , lastRead(0)
  , lastWrite(0)
  , rowHit(false)
  , numReads("%s:reads", name)
  , numWrites("%s:writes", name)
  , numActivates("%s:activates", name)
  , numPrecharges("%s:precharges", name)
  , numRefreshes("%s:refreshes", name)
  , numRowHits("%s:rowHits", name)
  , numRowMisses("%s:rowMisses", name)
{
  // nothing to do
}

// refresh bank
void DDRxBank::refresh()
{
  state       = IDLE;
  openRowID   = 0;
  lastRefresh = globalClock;
  rowHit      = false;
  numRefreshes.inc();
}

// Precharge bank
void DDRxBank::precharge()
{
  state         = IDLE;
  openRowID     = 0;
  lastPrecharge = globalClock;
  rowHit        = false;
  numPrecharges.inc();
}

// Activate row
void DDRxBank::activate(AddrType rowID)
{
  state        = ACTIVE;
  openRowID    = rowID;
  lastActivate = globalClock;
  rowHit       = false;
  numActivates.inc();
}

// Read from open row
void DDRxBank::read()
{
  if(rowHit) {
    numRowHits.inc();
  }
  else {
    numRowMisses.inc();
  }
  lastRead = globalClock;
  rowHit   = true;
  numReads.inc();
}

// Write to open row
void DDRxBank::write()
{
  if(rowHit) {
    numRowHits.inc();
  }
  else {
    numRowMisses.inc();
  }
  lastWrite = globalClock;
  rowHit    = true;
  numWrites.inc();
}



// rank constructor
DDRxRank::DDRxRank(const char *section, const char *name, AddrType numBanks)
  : emr(SLOW)
  , powerState(sIDD2N)
  , rankEnergy(0)
  , cke(true)
  , urgentRefresh(false)
  , timeRefresh(0)
  , lastRefresh(0)
  , lastPrecharge(0)
  , lastActivate(0)
  , lastActive_1(0)
  , lastActive_2(0)
  , lastRead(0)
  , lastWrite(0)
    //, stampRefresh("ddrx_%d_rank_%d_stamp_refresh", _channelID, _rankID)
{
  this->numBanks = numBanks;

  // Check timing parameters
  SescConf->isInt(section, "tREFI");     // Refresh Interval period
  SescConf->isInt(section, "tRFC");      // Refresh Cycle time
  SescConf->isInt(section, "tRTRS");     // Rank-To-Rank switching time
  SescConf->isInt(section, "tOST");      // Output Switching Time
  SescConf->isInt(section, "tRCD");      // Row to Column Delay
  SescConf->isInt(section, "tCAS");      // Column Access Strobe latency (aka tCL)
  SescConf->isInt(section, "tCWD");      // Column Write Delay (aka tWL)
  SescConf->isInt(section, "tCCD");      // Column to Column Delay
  SescConf->isInt(section, "tWTR");      // Write To Read delay time
  SescConf->isInt(section, "tWR");       // Write Recovery time
  SescConf->isInt(section, "tRTP");      // Read to Precharge
  SescConf->isInt(section, "tRP");       // Row Precharge
  SescConf->isInt(section, "tRRD");      // Row activation to Row activation Delay
  SescConf->isInt(section, "tRAS");      // Row Access Strobe
  SescConf->isInt(section, "tRC");       // Row Cycle
  SescConf->isInt(section, "tBL");       // Burst Length
  SescConf->isInt(section, "tCPDED");    // Command Pass Disable Delay
  SescConf->isInt(section, "tPD");       // Minimum power down duration
  SescConf->isInt(section, "tXP");       // Time to exit fast power down
  SescConf->isInt(section, "tXPDLL");    // Time to exit slow power down
  SescConf->isInt(section, "tFAW");      // Four bank Activation Window

  // Check power/energy parameters
  SescConf->isInt(section, "VDD");       // Operating voltage
  SescConf->isInt(section, "VDDMax");    // Maximum Operating voltage
  SescConf->isInt(section, "IDD0");      // Operating current: One bank active-precharge
  SescConf->isInt(section, "IDD2PF");    // Precharge power-down current, Fast PDN Exit; MRS[12] = 0
  SescConf->isInt(section, "IDD2PS");    // Precharge power-down current, Slow PDN Exit; MRS[12] = 1
  SescConf->isInt(section, "IDD2N");     // Precharge standby current
  SescConf->isInt(section, "IDD3P");     // Active power-down current
  SescConf->isInt(section, "IDD3N");     // Active standby current
  SescConf->isInt(section, "IDD4R");     // Operating burst read current
  SescConf->isInt(section, "IDD4W");     // Operating burst write current
  SescConf->isInt(section, "IDD5");      // Burst refresh current
  SescConf->isInt(section, "cycleTime"); // DRAM clock cycle time
  SescConf->isInt(section, "numChips");  // Number of chips per rank

  // Check bank count
  SescConf->isInt(section, "numBanks");


  // Read timing parameters
  tREFI      = SescConf->getInt(section, "tREFI");
  tRFC       = SescConf->getInt(section, "tRFC");
  tRTRS      = SescConf->getInt(section, "tRTRS");
  tOST       = SescConf->getInt(section, "tOST");
  tRCD       = SescConf->getInt(section, "tRCD");
  tCAS       = SescConf->getInt(section, "tCAS");
  tCWD       = SescConf->getInt(section, "tCWD");
  tCCD       = SescConf->getInt(section, "tCCD");
  tWTR       = SescConf->getInt(section, "tWTR");
  tWR        = SescConf->getInt(section, "tWR");
  tRTP       = SescConf->getInt(section, "tRTP");
  tRP        = SescConf->getInt(section, "tRP");
  tRRD       = SescConf->getInt(section, "tRRD");
  tRAS       = SescConf->getInt(section, "tRAS");
  tRC        = SescConf->getInt(section, "tRC");
  tBL        = SescConf->getInt(section, "tBL");
  tCPDED     = SescConf->getInt(section, "tCPDED");
  tPD        = SescConf->getInt(section, "tPD");
  tXP        = SescConf->getInt(section, "tXP");
  tXPDLL     = SescConf->getInt(section, "tXPDLL");
  tFAW       = SescConf->getInt(section, "tFAW");

  // handling no refresh
  SescConf->isInt(section, "refAlgorithm");
  if(SescConf->getInt(section, "refAlgorithm") == 0) {
    tRFC = 0;
  }

  // Read power/energy parameters
  VDD        = SescConf->getInt(section, "VDD");
  VDDMax     = SescConf->getInt(section, "VDDMax");
  IDD0       = SescConf->getInt(section, "IDD0");
  IDD2PF     = SescConf->getInt(section, "IDD2PF");
  IDD2PS     = SescConf->getInt(section, "IDD2PS");
  IDD2N      = SescConf->getInt(section, "IDD2N");
  IDD3P      = SescConf->getInt(section, "IDD3P");
  IDD3N      = SescConf->getInt(section, "IDD3N");
  IDD4R      = SescConf->getInt(section, "IDD4R");
  IDD4W      = SescConf->getInt(section, "IDD4W");
  IDD5       = SescConf->getInt(section, "IDD5");
  cycleTime  = SescConf->getInt(section, "cycleTime");
  numChips   = SescConf->getInt(section, "numChips");
  // new formulas based on micron power calculator
  long vt    = numChips * cycleTime * VDD * VDD / VDDMax;
  eIDD2PF    = IDD2PF * cycleTime * 8 * VDD * VDD / VDDMax;
  eIDD2PS    = IDD2PS * cycleTime * 8 * VDD * VDD / VDDMax;
  eIDD3P     = IDD3P  * cycleTime * 8 * VDD * VDD / VDDMax;
  eIDD2N     = IDD2N  * cycleTime * 8 * VDD * VDD / VDDMax;
  eIDD3N     = IDD3N  * cycleTime * 8 * VDD * VDD / VDDMax;
  eActivate  =  (IDD0 - ((IDD3N* tRAS)/tRC  + (IDD2N * (tRC - tRAS)/tRC))) * VDD * tRC *  cycleTime * 8 * VDD / VDDMax; //((IDD0 * tRC) - (IDD3N * tRAS + IDD2N * (tRP))) * vt;
 // tBL* ((number of reads + write)* tBL / dramcycles) /2
  ePrecharge = IDD2N * (tRP) * vt;
  eRead      = (IDD4R - IDD3N) * VDD * (tBL/8) * (tBL/2) * cycleTime * 8 * VDD / VDDMax;
  //eRead      = 0;
  eWrite     = (IDD4W - IDD3N) * VDD * (tBL/8) * (tBL/2) * cycleTime * 8 * VDD / VDDMax;
  //eWrite     = 0;
  eRefresh   = ((IDD5  - IDD3N) * tRFC * VDD)/tREFI * cycleTime * 8 * VDD / VDDMax;






  // Read bank count
  numBanks = SescConf->getInt(section, "numBanks");
  numBanksLog2 = log2(numBanks);


  banks = *(new std::vector<DDRxBank *>(numBanks));
  for(int b = 0; b < numBanks; ++b) {
    char temp[256]; sprintf(temp, "%s:%d", name, b);
    banks[b] = new DDRxBank(temp);
  }

///MnB:~ Dorsa
/*
  // Check DRAM coordinates
  SescConf->isInt(section, "numRanks");
  long nr = SescConf->getInt(section, "numRanks");
  long ri = _rankID + _channelID*nr;
  timeRefresh = - ri*tRFC;
*/
///:.
}

///MnB:~ Dorsa
/*
bool DDRxRank::isRefreshing(AddrType _bankID)
{
  return (globalClock < (lastRefresh + tRFC));
}
*/
///:.


// enable refresh
void DDRxRank::enableRefresh(double offset)
{
  Time_t delay = (double)tREFI*offset + 1;

  // schedule the first refresh
  CallbackBase *cb = refreshCB::create(this);
  EventScheduler::schedule((TimeDelta_t) delay, cb);
}

// check for an ongoing refresh
bool DDRxRank::isRefreshing()
{
    return (globalClock < lastRefresh + tRFC);
}

// number of needed refreshes ?
//int DDRxRank::neededRefreshes(AddrType bankID)
//{
//  return (globalClock - timeRefresh) / tREFI;
//}

// can a refresh issue now ?
bool DDRxRank::canIssueRefresh(AddrType bankID)
{
  // Check for ongoing refresh
  if(isRefreshing()) {
      return false;
  }

  // Enforce tRP
  if(globalClock < lastPrecharge + tRP) {
    return false;
  }

  // Enforce tRFC
  if(globalClock < lastRefresh + tRFC) {
    return false;
  }

  return true;
}


// can a precharge issue now to the given bank ?
bool DDRxRank::canIssuePrecharge(AddrType bankID)
{
  // Check for ongoing refresh
  if(isRefreshing()) {
      return false;
  }

  //Enforce tWR
  if(globalClock < (banks[bankID]->getLastWrite() + tCWD + tBL) + tWR) {
    return false;
  }

  //Enforce tRTP
  if(globalClock < banks[bankID]->getLastRead() + tRTP) {
    return false;
  }

  //Enforce tRAS
  if(globalClock < banks[bankID]->getLastActivate() + tRAS) {
    return false;
  }

  return true;
}


// can an activate issue now to the given bank ?
bool DDRxRank::canIssueActivate(AddrType bankID)
{
  // Check for ongoing refresh
  if(isRefreshing()) {
      return false;
  }

  // Enforce tRFC
  if(globalClock < lastRefresh + tRFC) {
    return false;
  }

  // Enforce tFAW
  if(globalClock < lastActive_2 + tFAW) {
    return false;
  }

  // Enforce tRP
  if(globalClock < banks[bankID]->getLastPrecharge() + tRP) {
    return false;
  }

  // Enforce tRRD
  for(int i=0; i < numBanks; i++) {
    if(i != bankID) {
      if(globalClock < banks[i]->getLastActivate() + tRRD) {
        return false;
      }
    }
  }

  // Enforce tRC
  if(globalClock < banks[bankID]->getLastActivate() + tRC) {
    return false;
  }

  return true;
}

// can a read issue to the given bank and row ?
bool DDRxRank::canIssueRead(AddrType bankID, AddrType rowID)
{
  // Check for ongoing refresh
  if(isRefreshing()) {
      return false;
  }

  //Enforce page misses
  if(banks[bankID]->getOpenRowID() != rowID) {
    return false;
  }

  //Enforce tRCD
  if(globalClock < banks[bankID]->getLastActivate() + tRCD) {
    return false;
  }

  //Enforce tCCD
  if((globalClock < lastRead + tCCD) || (globalClock < lastWrite + tCCD)) {
    return false;
  }

  //Enforce tWTR
  if(globalClock < (lastWrite + tCWD + tBL) + tWTR) {
    return false;
  }

  return true;
}


// Can a write issue to the given bank and row ?
bool DDRxRank::canIssueWrite(AddrType bankID, AddrType rowID)
{
  // Check for ongoing refresh
  if(isRefreshing()) {
      return false;
  }

  //Enforce page misses
  if(banks[bankID]->getOpenRowID() != rowID) {
    return false;
  }

  //Enforce tRCD
  if(globalClock < banks[bankID]->getLastActivate() + tRCD) {
    return false;
  }

  //Enforce tCCD
  if((globalClock < lastRead + tCCD) || (globalClock < lastWrite + tCCD)) {
    return false;
  }

  return true;
}


// Refresh
void DDRxRank::refresh(void)
{
  //Timing
  lastRefresh  = globalClock;
  //timeRefresh += tREFI;
  //stampRefresh.sample(globalClock);

  //refresh all the banks
  for(int i=0; i < numBanks; ++i) {
    banks[i]->refresh();
  }

  //Energy
  rankEnergy += eRefresh;

  //power
  cke = true;

  // schedule a refresh
  CallbackBase *cb = refreshCB::create(this);
  EventScheduler::schedule((TimeDelta_t) tREFI, cb);
}


// Precharge given bank
void DDRxRank::precharge(AddrType bankID)
{
  //Timing
  lastPrecharge = globalClock;
  banks[bankID]->precharge();

  //Energy
  rankEnergy += ePrecharge;

  //power
  cke = true;
  //PowerClock = 0;
}

//Activate given row in given bank
void DDRxRank::activate(AddrType bankID, AddrType rowID)
{
  //Timing
  lastActive_2 = lastActive_1;
  lastActive_1 = lastActivate;
  lastActivate = globalClock;
  banks[bankID]->activate(rowID);

  //Energy
  rankEnergy += eActivate;

  //power
  cke = true;
  //PowerClock = 0;
}

//Read from given row in given bank
void DDRxRank::read(AddrType bankID, AddrType rowID)
{
  //Timing
  lastRead = globalClock;
  banks[bankID]->read();

  //Energy
  rankEnergy += eRead;

  //power
  cke = true;
  //PowerClock = 0;
}

//Write to given row in given bank
void DDRxRank::write(AddrType bankID, AddrType rowID)
{
  //Timing
  lastWrite = globalClock;
  banks[bankID]->write();

  //Energy
  rankEnergy += eWrite;

  //power
  cke = true;
  //PowerClock = 0;
}


// Get DDRx rank's background energy
long DDRxRank::getForegroundEnergy()
{
  long energy = rankEnergy;
  rankEnergy  = 0;
  return energy;
}

// Get DDRx rank's background energy
long DDRxRank::getBackgroundEnergy()
{
  //Return energy for current power state
  switch (powerState) {
  case sIDD2PF:
    return eIDD2PF;
    break;
  case sIDD2PS:
    return eIDD2PS;
    break;
  case sIDD3P:
    return eIDD3P;
    break;
  case sIDD2N:
    return eIDD2N;
    break;
  case sIDD3N:
    return eIDD3N;
    break;
  default:
    printf("ERROR: Illegal rank power state '%d'!\n", powerState);
    exit(1);
    break;
  }
}

// Update DDRx power state
void DDRxRank::updatePowerState()
{
  // Flag indicating all banks are precharged
  bool allBanksPrecharged = true;

  for(int i=0; i < numBanks; i++) {
    if(banks[i]->getState() == ACTIVE) {
      allBanksPrecharged = false;
    }
  }

  // If CKE is low
  if(cke == false) {
    // If all banks are precharged
    if(allBanksPrecharged) {
      //If using fast-exit mode
      if(emr == FAST) {
        powerState = sIDD2PF;
      }
      else{
        powerState = sIDD2PS;
      }
    }
    else{
      powerState = sIDD3P;
    }
  }
  else{
    //If all banks are precharged
    if(allBanksPrecharged) {
      powerState = sIDD2N;
    }
    else{
      powerState = sIDD3N;
    }
  }
}


// DDRx Channel Controller
DDRxChannel::DDRxChannel(const char *section, const char *name, AddrType numRanks, AddrType numBanks)
  : backEnergy("%s:background_energy", name)
  , foreEnergy("%s:foreground_energy", name)
  , peakPower("%s:peak_power", name)
  , avrgPower("%s:average_power", name)
  , chanAvgOcc("%s:average_occupancy", name)
  , chanAvgMAT("%s:average_latency", name)
  //, chanMinMAT("%s:minimum_latency", name)
  , chanMaxMAT("%s:maximum_latency", name)
{
  this->numRanks = numRanks;
  this->numBanks = numBanks;

  // check user defined parameters
  SescConf->isGT(section, "schQueueSize", 0);
  SescConf->isInt(section, "refAlgorithm");
  SescConf->isInt(section, "schAlgorithm");

  SescConf->isInt(section, "tREFI");
  SescConf->isInt(section, "tRFC");
  SescConf->isInt(section, "tRTRS");
  SescConf->isInt(section, "tOST");
  SescConf->isInt(section, "tCAS");
  SescConf->isInt(section, "tCWD");
  SescConf->isInt(section, "tBL");

  SescConf->isPower2(section, "llcBlkSize", 0);

  SescConf->isInt(section, "cycleTime");

  // read in user-defined parameters
  schQueueSize = SescConf->getInt(section, "schQueueSize");
  refAlgorithm = SescConf->getInt(section, "refAlgorithm");
  schAlgorithm = SescConf->getInt(section, "schAlgorithm");
  tREFI        = SescConf->getInt(section, "tREFI");
  tRFC         = SescConf->getInt(section, "tRFC");
  tRTRS        = SescConf->getInt(section, "tRTRS");
  tOST         = SescConf->getInt(section, "tOST");
  tCAS         = SescConf->getInt(section, "tCAS");
  tCWD         = SescConf->getInt(section, "tCWD");
  tBL          = SescConf->getInt(section, "tBL");

  //dynPower = SescConf->getDouble(section, "dynPower");
  //dynPowerHybrid = SescConf->getDouble(section, "dynPowerHybrid");
  //termPower = SescConf->getDouble(section, "termPower");
  //termPowerHybrid = SescConf->getDouble(section, "termPowerHybrid");

  lineSize = SescConf->getInt(section, "llcBlkSize");

  enableTransfer = false;
  if(SescConf->checkBool(section,"enableTransfer")) {
    enableTransfer = SescConf->getBool(section,"enableTransfer");
  }

  if(enableTransfer) {
    s_modePattern = new GStatsHist("%s:ModePattern",name);
    s_onesPattern = new GStatsHist("%s:OnesPattern",name);
    s_flipsPattern = new GStatsHist("%s:FlipsPattern",name);
    s_flipsPerSlot = new GStatsHist("%s:FlipsPerSlot",name);
    s_flipsPerSlotX = new GStatsHist("%s:FlipsPerSlotX",name);
    s_flipsPerSlotXX = new GStatsHist("%s:FlipsPerSlotXX",name);
    s_encodingDelay = new GStatsHist("%s:EncodingDelay",name);

    s_transMode = new GStatsHist("%s:TransMode",name);
    s_wireFlips = new GStatsCntr("%s:WireFlips",name);
    s_onesCount = new GStatsCntr("%s:OnesCount",name);
    s_operations = new GStatsCntr("%s:Operations",name);
    s_chunkCount = new GStatsHist("%s:ChunkCount",name);

    s_terminationEnergy = new GStatsCntr("%s:TerminationEnergy",name);
    //s_operationalEnergy = new GStatsCntr("%s:OperationalEnergy",name);
    s_totalDynEnergy = new GStatsCntr("%s:TotalDynEnergy",name);

    if(SescConf->checkInt(section,"transferMode")) {
        transferMode = SescConf->getInt(section,"transferMode");
    }

    if(SescConf->checkInt(section,"dataWires")) {
        wires = SescConf->getInt(section,"dataWires");
    }

    partitions = 8;
    segment = wires/partitions;
    if(wires != (segment*partitions)) {
        printf("\nERROR: bad partition value for '%s'!!\n\n", name);
        exit(0);
    }
  }

  // constant masks required for getChunk
  //Mask four_bit= { { 0x0F , 0xF0 , 0x00 , 0x00, 0x00 , 0x00, 0x00 , 0x00 } };
  //Mask two_bit= { { 0x03, 0x0C, 0x30, 0xC0, 0x00 , 0x00, 0x00 , 0x00 } };
  //Mask eight_bit= { { 0xFF, 0x00 , 0x00 , 0x00, 0x00 , 0x00, 0x00 , 0x00 } };
  //Mask one_bit= { { 0x01, 0x02, 0x04, 0x08 , 0x10 , 0x20, 0x40, 0x80 } };

  //M[8]=eight_bit;
  //M[4]=four_bit;
  //M[2]=two_bit;
  //M[1]=one_bit;

  cycleTime    = SescConf->getInt(section, "cycleTime");

  ranks = *(new std::vector<DDRxRank *>(numRanks));
  for(int r = 0; r < numRanks; ++r) {
    char temp[256]; sprintf(temp, "%s:%d", name, r);
    ranks[r] = new DDRxRank(section, temp, numBanks);
  }
}

/*
void
DDRxChannel::getChunks(unsigned int partitionSize, unsigned char * ptr) {

	if(M.find(partitionSize) != M.end()) {
		Mask mask=M[partitionSize];
	int k=0;
	int byteSize=8;
	int nibbleSize=byteSize/partitionSize;
	unsigned char *temp= (unsigned char *)(malloc(nibbleSize*lineSize*sizeof(unsigned char)));
		for(int i=0;i<lineSize;i++) {
			k = nibbleSize*i;
			for(int j=nibbleSize-1;j>=0;j--){
				temp[k] = (ptr[i] & mask.value[j]) >> ( partitionSize * (j) );
				k++;
			}
		}
	memcpy(ptr,temp,nibbleSize*lineSize);
	free(temp);
	}
	else {
		// something wrong
	}
}

//HammingWeight
int
DDRxChannel::getHammingWeight(unsigned int value, unsigned int length){
    unsigned int count=0;
    for(unsigned int i = 0; (i < length) && value; value >>= 1, ++i) {
        if(value & 1) {
            count++;
        }
    }
    return count;
}


// transfer data
int
DDRxChannel::transfer(unsigned char *d) {
    if(d) {
        int byteSize = 8;           // constant value
        int additionalLat = 0;      // additional access time due to transmission time
        int totalFlips = 0;         // total wire flips due to data transfer
        int totalOnes = 0;         // total wire flips due to data transfer
        //int bank = (addr>>bankShift) & numBanksMask;

        s_operations->inc();

        // BIN: Binary Data Encoding (NRZ)
        if(transferMode == 0) {
            unsigned int maxDelayPerSlot = 1;
            int numflips = 0;
            int chunkSize = 1;
            int slots = (lineSize * byteSize ) / (wires * chunkSize) ;
            int nibbleSize = byteSize/chunkSize;

            unsigned char* tempValue = (unsigned char*)malloc(nibbleSize*lineSize*sizeof(unsigned char));
            memcpy(tempValue, d, lineSize);
            getChunks(chunkSize, tempValue);

            for(int s = 0; s < slots; s++) {
                for(int i = 0; i < wires; i++) {
                    unsigned char dataChunk = tempValue[i + (s*wires)];
                    s_chunkCount->sample(true, dataChunk);
                    if (dataChunk != binaryDataWire[i])	 {
                        binaryDataWire[i] = dataChunk;
                        ++numflips;
                    }
                    totalOnes += (binaryDataWire[i])? 1: 0;
                }
                additionalLat += maxDelayPerSlot;
                s_flipsPerSlot->sample(true, numflips);
                totalFlips += numflips;
                numflips = 0;
            }
            free(tempValue);
        }
        // BIC: Bus Invert Coding
        else if(transferMode == 1) {
            unsigned int maxDelayPerSlot = 1;
            int tmpflips = 0;
            int numflips = 0;
            int numflipsX = 0;
            int chunkSize = 1;
            int slots = (lineSize * byteSize ) / (wires * chunkSize) ;
            int nibbleSize = byteSize/chunkSize;
            bool invert;

            unsigned char* tempValue = (unsigned char*)malloc(nibbleSize*lineSize*sizeof(unsigned char));
            memcpy(tempValue, d, lineSize);
            getChunks(chunkSize, tempValue);
            for(int s = 0; s < slots; s++) {
                for(int p = 0; p < partitions; p++) {
                    invert = false;
                    tmpflips = (binaryExtraWire[p])? 1: 0;
                    binaryExtraWire[p] = 0;
                    for(int i = 0, w = p*segment; i < segment; i++, w++) {
                        unsigned char dataChunk = tempValue[w + (s*wires)];
                        s_chunkCount->sample(true, dataChunk);
                        if(dataChunk != binaryDataWire[w])	 {
                            ++tmpflips;
                        }
                    }
                    numflipsX += tmpflips;

                    // make inversion decision
                    if(tmpflips > segment/2) {
                        invert = true;
                        tmpflips = segment - tmpflips + 1;
                        binaryExtraWire[p] = 1;
                        totalOnes += (binaryExtraWire[p])? 1: 0;
                    }
                    numflips += tmpflips;

                    // update wire states
                    for(int i = 0, w = p*segment; i < segment; i++, w++) {
                        unsigned char dataChunk = tempValue[w + (s*wires)];
                        dataChunk = invert? (1-dataChunk): dataChunk;
                        binaryDataWire[w] = dataChunk;
                        totalOnes += (binaryDataWire[i])? 1: 0;
                    }
                }
                additionalLat += maxDelayPerSlot;
                s_flipsPerSlot->sample(true, numflips);
                s_flipsPerSlotX->sample(true, numflipsX);
                totalFlips += numflips;
                numflips = 0;
                numflipsX = 0;
            }
            free(tempValue);
        }
        // DBI: Data Bus Inversion Coding
        else if(transferMode == 2) {
            unsigned int maxDelayPerSlot = 1;
            int tmpOnes = 0;
            int numOnes = 0;
            int numflipsX = 0;
            int chunkSize = 1;
            int slots = (lineSize * byteSize ) / (wires * chunkSize) ;
            int nibbleSize = byteSize/chunkSize;
            bool invert;

            unsigned char* tempValue = (unsigned char*)malloc(nibbleSize*lineSize*sizeof(unsigned char));
            memcpy(tempValue, d, lineSize);
            getChunks(chunkSize, tempValue);

            for(int s = 0; s < slots; s++) {
                for(int p = 0; p < partitions; p++) {
                    invert = false;
                    tmpOnes = 0;
                    //binaryExtraWire[p] = 0;
                    for(int i = 0, w = p*segment; i < segment; i++, w++) {
                        unsigned char dataChunk = tempValue[w + (s*wires)];
                        s_chunkCount->sample(true, dataChunk);
                        if(dataChunk) {
                            ++tmpOnes;
                        }
                    }
                    //numflipsX += tmpflips;

                    // make inversion decision
                    if(tmpOnes > segment/2) {
                        invert = true;
                        tmpOnes = segment - tmpOnes + 1;
                        totalFlips += (binaryExtraWire[p])? 0: 1;
                        binaryExtraWire[p] = 1;
                    }
                    else {
                        totalFlips += (binaryExtraWire[p])? 1: 0;
                        binaryExtraWire[p] = 0;
                    }
                    numOnes += tmpOnes;

                    // update wire states
                    for(int i = 0, w = p*segment; i < segment; i++, w++) {
                        unsigned char dataChunk = tempValue[w + (s*wires)];
                        dataChunk = invert? (1-dataChunk): dataChunk;
                        totalFlips += (binaryDataWire[w] != dataChunk)? 1: 0;
                        binaryDataWire[w] = dataChunk; //? (1-binaryDataWire[w]): binaryDataWire[w];
                    }
                }
                additionalLat += maxDelayPerSlot;
                //s_flipsPerSlot->sample(true, numflips);
                //s_flipsPerSlotX->sample(true, numflipsX);
                totalOnes += numOnes;
                numOnes = 0;
            }
            free(tempValue);
        }
        // DZC: Dynamic Zero Compression
        else if(transferMode == 3) {
            printf("ERROR: transferMode DZC (%ld) yet to be implemented!!\n\n", transferMode);
            exit(0);
        }
        // DESC: Time Based Encoding
        else if(transferMode == 4) {
            printf("ERROR: transferMode DESC (%ld) yet to be implemented!!\n\n", transferMode);
            exit(0);
        }
        // SETS: Sparse Encoding with NRZI
        else if(transferMode == 5) {
            printf("ERROR: transferMode SETS (%ld) yet to be implemented!!\n\n", transferMode);
            exit(0);
        }
        // HIST: History based Encoding
        else if(transferMode == 6) {
            unsigned int maxDelayPerSlot = 1;
            int numflips = 0;
            int numflipsX = 0;
            int chunkSize = 1;
            int slots = (lineSize * byteSize ) / (wires * chunkSize) ;
            int nibbleSize = byteSize/chunkSize;

            unsigned char* tempValue = (unsigned char*)malloc(nibbleSize*lineSize*sizeof(unsigned char));
            memcpy(tempValue, d, lineSize);
            getChunks(chunkSize, tempValue);

            for(int s = 0; s < slots; s++) {
                long index = 0;
                long hdist = wires + partitions;
                for(int h = 0; h < (1<<partitions); ++h) {
                    int tmpOnes = 0;
                    //int tmpflips = 0;
                    for(int m = 1<<(partitions-1), i = 0; m; m>>=1, ++i) {
                        unsigned char bit = m&h? 1: 0;
                        //tmpflips += (binaryExtraWire[i])? (1 - bit): bit;
                        tmpOnes += bit;
                    }
                    for(int w = 0; w < wires; ++w) {
                        unsigned char dataChunk = tempValue[w + (s*wires)];
                        tmpOnes += dataChunk? (1 - binaryHistWire[h][w]): binaryHistWire[h][w];
                    }
                    if(hdist > tmpOnes) {
                        hdist = tmpOnes;
                        index = h;
                    }
                }

                // update wire states and hist table
                //numflips = 0;
                for(int m = 1<<(partitions-1), i = 0; m; m>>=1, ++i) {
                    unsigned char bit = m&index? 1: 0;
                    numflips += (binaryExtraWire[i])? (1 - bit): bit;
                    binaryExtraWire[i] = bit;
                }
                for(int w = 0; w < wires; ++w) {
                    unsigned char dataChunk = tempValue[w + (s*wires)];
                    unsigned char bit = dataChunk? (1 - binaryHistWire[index][w]): binaryHistWire[index][w];
                    s_chunkCount->sample(true, dataChunk);
                    numflips += binaryDataWire[w]? (1 - bit): bit;
                    numflipsX += binaryDataWire[w]? (1 - dataChunk): dataChunk;
                    binaryDataWire[w] = bit;
                    binaryHistWire[ptrHist][w] = dataChunk;
                }
                ptrHist = (ptrHist + 1) & ((1L<<partitions) - 1);
                additionalLat += maxDelayPerSlot;
                s_flipsPerSlot->sample(true, numflips);
                s_flipsPerSlotX->sample(true, numflipsX);
                totalFlips += numflips;
                totalOnes += hdist;
                numflips = 0;
                numflipsX = 0;
            }
            free(tempValue);
        }
        // CLUS: Cluster based Encoding
        else if(transferMode == 7) {
            printf("ERROR: transferMode CLUS (%ld) yet to be implemented!!\n\n", transferMode);
            exit(0);
        }
        // CAFO: Cost Aware Flip Optimization
        else if(transferMode == 8) {
            unsigned int maxDelayPerSlot = 2;
            int tmpflips = 0;
            int numflips = 0;
            int numflipsX = 0;
            int chunkSize = 1;
            int slots = (lineSize * byteSize ) / (wires * chunkSize) ;
            int nibbleSize = byteSize/chunkSize;
            bool invert;
            wires = 32; // for CAFO
            partitions = 2; // for CAFO
            segment = 16; // for CAFO

            unsigned char* tempValue = (unsigned char*)malloc(nibbleSize*lineSize*sizeof(unsigned char));
            memcpy(tempValue, d, lineSize);
            getChunks(chunkSize, tempValue);

            unsigned char* modeValue = (unsigned char*)malloc(wires*sizeof(unsigned char));

            // vertical process
            for(int i = 0; i < wires; i++) {
                int tmpOnes = 0;
                for(int s = 0; s < slots; s++) {
                    tmpOnes += (tempValue[i + (s*wires)])? 1: -1;
                }
                modeValue[i] = (tmpOnes > 0)? 1: 0;
                totalOnes += (modeValue[i])? 1: 0;
            }

            // horizontal process
            for(int s = 0; s < slots; s++) {
                for(int p = 0; p < partitions; p++) {
                    int tmpOnes = 0;
                    invert = false;
                    tmpflips = 0; //(binaryExtraWire[p])? 1: 0;
                    //binaryExtraWire[p] = 0;
                    for(int i = 0, w = p*segment; i < segment; i++, w++) {
                        unsigned char dataChunk = tempValue[w + (s*wires)];
                        s_chunkCount->sample(true, dataChunk);
                        dataChunk = (modeValue[w])? (1-dataChunk): dataChunk;
                        tmpOnes += dataChunk? 1: 0;
                    }
                    //numflipsX += tmpflips;

                    // make inversion decision
                    if(tmpOnes > segment/2) {
                        invert = true;
                        tmpOnes = segment - tmpOnes + 1;
                        tmpflips += (binaryExtraWire[p])? 0: 1;
                        binaryExtraWire[p] = 1;
                        totalOnes++;
                    }
                    else {
                        tmpflips += (binaryExtraWire[p])? 1: 0;
                        binaryExtraWire[p] = 0;
                    }

                    // update wire states
                    for(int i = 0, w = p*segment; i < segment; i++, w++) {
                        unsigned char dataChunk = tempValue[w + (s*wires)];
                        dataChunk = (modeValue[w])? (1-dataChunk): dataChunk;
                        dataChunk = invert? (1-dataChunk): dataChunk;
                        tmpflips += (binaryDataWire[w] == dataChunk)? 1: 0;
                        binaryDataWire[w] = dataChunk;
                        totalOnes += (binaryDataWire[w])? 1: 0;
                    }
                    numflips += tmpflips;
                }
                additionalLat += maxDelayPerSlot;
                s_flipsPerSlot->sample(true, numflips);
                //s_flipsPerSlotX->sample(true, numflipsX);
                totalFlips += numflips;
                numflips = 0;
                //numflipsX = 0;
            }

            // send mode bits
//            for(int p = 0; p < partitions; p++) {
//                invert = false;
//                tmpflips = (binaryExtraWire[p])? 1: 0;
//                binaryExtraWire[p] = 0;
//                for(int i = 0, w = p*segment; i < segment; i++, w++) {
//                    if(modeValue[w] != binaryDataWire[w])	 {
//                        ++tmpflips;
//                    }
//                }
//
//                // make inversion decision
//                if(tmpflips > segment/2) {
//                    invert = true;
//                    tmpflips = segment - tmpflips + 1;
//                    binaryExtraWire[p] = 1;
//                }
//                numflips += tmpflips;
//
//                // update wire states
//                for(int i = 0, w = p*segment; i < segment; i++, w++) {
//                    unsigned char dataChunk = invert? (1-modeValue[w]): modeValue[w];
//                    binaryDataWire[w] = dataChunk;
//                }
//            }
//            additionalLat += maxDelayPerSlot;
//            s_flipsPerSlot->sample(true, numflips);
//            totalFlips += numflips;
//            numflips = 0;
            free(tempValue);
            free(modeValue);
        }
        // LSBC: Low Swing Binary Coding
        else if(transferMode == 9) {
            unsigned int maxDelayPerSlot = 1;
            int numflips = 0;
            int chunkSize = 1;
            int slots = (lineSize * byteSize ) / (wires * chunkSize) ;
            int nibbleSize = byteSize/chunkSize;

            unsigned char* tempValue = (unsigned char*)malloc(nibbleSize*lineSize*sizeof(unsigned char));
            memcpy(tempValue, d, lineSize);
            getChunks(chunkSize, tempValue);

            for(int s = 0; s < slots; s++) {
                for(int i = 0; i < wires; i++) {
                    unsigned char dataChunk = tempValue[i + (s*wires)];
                    s_chunkCount->sample(true, dataChunk);
                    if (dataChunk != binaryDataWire[i])	 {
                        binaryDataWire[i] = dataChunk;
                        ++numflips;
                    }
                    totalOnes = 0; //+= (binaryDataWire[i])? 1: 0;
                }
                additionalLat += maxDelayPerSlot;
                s_flipsPerSlot->sample(true, numflips);
                totalFlips += numflips;
                numflips = 0;
            }
            free(tempValue);
        }
        // FADE: Frequency Assisted Coding
        else if(transferMode == 10) {
            int chunkSize = 8;
            unsigned int maxDelayPerSlot = chunkSize + (chunkSize >> 1); // chunk size dependent for FADE
            int numflips = 0;
            int numflipsX = 0;
            int slots = (lineSize * byteSize ) / (wires * chunkSize) ;
            int nibbleSize = byteSize/chunkSize;

            unsigned char* tempValue = (unsigned char*)malloc(nibbleSize*lineSize*sizeof(unsigned char));
            memcpy(tempValue, d, lineSize);
            getChunks(chunkSize, tempValue);

            for(int s = 0; s < slots ; s++) {
                for(int i = 0; i < wires ; i++) {
                    int accessByte = i + (s * wires);
                    unsigned int dataChunk;
                    unsigned int dataChunkAlpha = (unsigned int)tempValue[accessByte];
                    unsigned int dataChunkBeta  = (i & 3)? ((unsigned int)tempValue[accessByte - 1]): 0b01010101;

                    int HMWAlpha     = getHammingWeight(dataChunkAlpha, chunkSize);
                    int HMWAlphaBeta = getHammingWeight(dataChunkAlpha ^ dataChunkBeta, chunkSize);
                    int HMWAlphaBar  = getHammingWeight(~dataChunkAlpha, chunkSize);

                    if((HMWAlpha <= 4) && (HMWAlphaBeta < HMWAlpha)) {
                        dataChunk = dataChunkAlpha ^ dataChunkBeta;
                        numflips++; //because of 1 in FADEMODE
                        s_transMode->sample(true, 2);
                    }
                    else if((HMWAlpha > 4) && (HMWAlphaBeta >= HMWAlphaBar)){
                        dataChunk = ~dataChunkAlpha;
                        numflips++; //because of FADEMODE
                        s_transMode->sample(true, 1);
                    }
                    else {
                        dataChunk = dataChunkAlpha;
                        s_transMode->sample(true, 0);
                    }
                    numflips = numflips + getHammingWeight(dataChunk, chunkSize);
                }
                additionalLat += maxDelayPerSlot;
                s_flipsPerSlot->sample(true, numflips);
                totalFlips += numflips;
                totalOnes += 0;//numflips;
                numflips = 0;
            }
            free(tempValue);
        }
        // TEST: Under Development Coding
        else if(transferMode == 11) {
            unsigned int maxDelayPerSlot = 1;
            int tmpflips = 0;
            int numflips = 0;
            int numflipsX = 0;
            int chunkSize = 1;
            int slots = (lineSize * byteSize ) / (wires * chunkSize) ;
            int nibbleSize = byteSize/chunkSize;
            int mode; // 0: AND; 1: XOR

            unsigned char* tempValue = (unsigned char*)malloc(nibbleSize*lineSize*sizeof(unsigned char));
            memcpy(tempValue, d, lineSize);
            getChunks(chunkSize, tempValue);

            for(int s = 0; s < slots; s++) {
                for(int p = 0; p < partitions; p++) {
                    mode = 0; // AND
                    tmpflips = 0;
                    for(int i = 0, w = p*segment; (i < segment) && (mode == 0); i++, w++) {
                        unsigned char dataChunk = 1 - tempValue[w + (s*wires)];
                        //unsigned char codeChunk = binaryHistWire[bank][0][w]&dataChunk;
                        tmpflips += ((binaryDataWire[w] == 1) && (dataChunk == 1))? 1: 0;
                        if(((dataChunk == 0) && (binaryDataWire[w] == 0)) || (tmpflips > (segment/2))){
                            mode = 1; // ORG
                        }
                    }
                    s_modePattern->sample(true, mode);

                    // update wire states
                    tmpflips = (binaryExtraWire[p])? (1-mode): mode;
                    binaryExtraWire[p] = mode;
                    for(int i = 0, w = p*segment; i < segment; i++, w++) {
                        unsigned char dataChunk = tempValue[w + (s*wires)];
                        numflipsX += (binaryDataWire[w] == dataChunk)? 0: 1;
                        if(mode == 0) {
                            if((dataChunk == 0) && (binaryDataWire[w] == 1)) {
                                binaryDataWire[w] = 1 - binaryDataWire[w];
                                tmpflips++;
                            }
                        }
                        else {
                            if(dataChunk != binaryDataWire[w]) {
                                binaryDataWire[w] = dataChunk;
                                tmpflips++;
                            }
                        }
                    }
                    numflips += tmpflips;
                }
                additionalLat += maxDelayPerSlot;
                s_flipsPerSlot->sample(true, numflips);
                s_flipsPerSlotX->sample(true, numflipsX);
                totalFlips += numflips;
                numflips = 0;
                numflipsX = 0;
            }
            free(tempValue);
        }
        // Undefined Transfer Mode
        else {
            printf("\nERROR: UNDEFINED TRANSFER MODE FOR DDRx!!\n\n");
            exit(0);
        }

        s_onesCount->add(totalOnes);
        s_wireFlips->add(totalFlips);
        //double bFE = (totalFlips * bitFlipEnergy);
        //double tDE = bFE + operationalEnergy;
        totalOnes = totalFlips;
        long hybridFlips = 0;
        long hybridOnes = 0;
        double tDE = (totalFlips * dynPower * cycleTime + hybridFlips * dynPowerHybrid * 0.5 * cycleTime) / 1000000 ; // cycle time needs to be multiplied
	    double tP = (totalOnes * termPower  * cycleTime + hybridOnes * termPowerHybrid * 0.5 * cycleTime) / 1000000 ; // cycle time needs to be multiplied

	    s_terminationEnergy->add(tP);
        //s_operationalEnergy->add(operationalEnergy, true);
        s_totalDynEnergy->add(tDE);
        s_encodingDelay->sample(additionalLat);

        return additionalLat;
    }
    else {
        printf("ERROR: DDRxChannel::transfer(NULL)!!\n");
        exit(0);
    }

    // default additional access latency
    return 0;
}
*/

// adding memory reference to DDRx channel
bool DDRxChannel::addReference(DDRxReference *mref)
{
  //MSG("\na request with chanID %ld was received in addReference().", mref->getChannelID());
  if(schQueue.size() < schQueueSize) {
    STATE bankState = getBankState(mref->getRankID(), mref->getBankID());
    AddrType openRowID = getOpenRowID(mref->getRankID(), mref->getBankID());

    // update memory reference state in the queue
    mref->setTimeStamp(globalClock);
    mref->setPrechargePending(bankState == ACTIVE && mref->getRowID() != openRowID);
    mref->setActivatePending(bankState == IDLE || mref->getRowID() != openRowID);
    mref->setReadPending(mref->isRead());
    mref->setWritePending(!mref->isRead());

    // add the memory reference to the scheduling queue
    schQueue.push_back(mref);
    return true;
  }
  return false;
}


// Update the state of the scheduling queue after issuing a DRAM command
void DDRxChannel::updateQueueState()
{
  for(int i=0; i < schQueue.size(); ++i) {
    STATE bankState = getBankState(schQueue[i]->getRankID(), schQueue[i]->getBankID());
    AddrType openRowID = getOpenRowID(schQueue[i]->getRankID(), schQueue[i]->getBankID());

    schQueue[i]->setPrechargePending((bankState == ACTIVE) && (schQueue[i]->getRowID() != openRowID));
    schQueue[i]->setActivatePending((bankState == IDLE) || (schQueue[i]->getRowID() != openRowID));
  }
}

// update power state of the channel
void DDRxChannel::updatePowerState()
{
    long fore = 0;
    long back = 0;

    for(int r=0; r < numRanks; ++r) {
        fore += ranks[r]->getForegroundEnergy();
        back += ranks[r]->getBackgroundEnergy();
        ranks[r]->updatePowerState();
    }

    backEnergy.add((double)back/1000000.0);
    foreEnergy.add((double)fore/1000000.0);
    peakPower.sample(true, (double)(fore+back)/cycleTime);
    avrgPower.sample(true, (double)(fore+back)/cycleTime);
}

// enable refresh at rank level
void DDRxChannel::enableRefresh(AddrType rankID, double offset)
{
    ranks[rankID]->enableRefresh(offset);
}

// check for an ongoing refresh
bool DDRxChannel::isRefreshing(AddrType rankID)
{
    return ranks[rankID]->isRefreshing();
}

// number of needed refresh operations to a given bank ?
//int DDRxChannel::neededRefreshes(AddrType rankID, AddrType bankID)
//{
//    return ranks[rankID]->neededRefreshes(bankID);
//}

// Can a refresh to given rank issue now ?
bool DDRxChannel::canIssueRefresh(AddrType rankID, AddrType bankID)
{
    return ranks[rankID]->canIssueRefresh(bankID);
}

//Can a precharge to given rank and bank issue now ?
bool DDRxChannel::canIssuePrecharge(AddrType rankID, AddrType bankID)
{
    //Check intra-rank constraints
    return ranks[rankID]->canIssuePrecharge(bankID);
}

//Can an activate to given rank and bank issue now ?
bool DDRxChannel::canIssueActivate(AddrType rankID, AddrType bankID)
{
    //Check intra-rank constraints
    return ranks[rankID]->canIssueActivate(bankID);
}


// Can a read to given rank, bank, and row issue now
bool DDRxChannel::canIssueRead(AddrType rankID, AddrType bankID, AddrType rowID)
{
    // Check intra-rank constraints
    if(!ranks[rankID]->canIssueRead(bankID, rowID)) {
        return false;
    }

    // Enforce tRTRS
    for(int i=0; i < numRanks; i++) {
        if(i != rankID) {
            // Consecutive read commands
            if(globalClock < (ranks[i]->getLastRead() + tBL) + tRTRS) {
                return false;
            }

            // Write command followed by read command
            //if(globalClock < (ranks[i]->getLastWrite() + tCWD + tBL - tCAS) + tRTRS) {
            if((globalClock + tCAS) < (ranks[i]->getLastWrite() + tCWD + tBL) + tRTRS) {
                return false;
            }
        }
    }

    return true;
}

// Can a write to given rank, bank, and row issue now
bool DDRxChannel::canIssueWrite(AddrType rankID, AddrType bankID, AddrType rowID) {
    // Check intra-rank constraints
    if(!ranks[rankID]->canIssueWrite(bankID, rowID)) {
        return false;
    }

    // Enforce tRTRS
    for(int i=0; i < numRanks; i++) {
        // Read followed by write, any two ranks
        //if(globalClock < (ranks[i]->getLastRead() + tCAS + tBL - tCWD) + tRTRS) {
        if((globalClock + tCWD) < (ranks[i]->getLastRead() + tCAS + tBL) + tRTRS) {
            return false;
        }

        // Write followed by write, different ranks
        if(i != rankID) {
            // Enforce tOST
            if(globalClock < (ranks[i]->getLastWrite() + tBL) + tOST) {
                return false;
            }
        }
    }

    return true;
}

// constant wait time for ElasticRefresh
//bool DDRxChannel::consWait(AddrType rankID, AddrType bankID) {
//    return ((globalClock < ranks[rankID]->getLastRefresh()) + consDelay);
//}

// proportional wait time for ElasticRefresh
//bool DDRxChannel::propWait(AddrType rankID, AddrType bankID) {
//    return ((globalClock < ranks[rankID]->getLastRefresh()) + propDelay);
//}

// Refresh a rank
//void DDRxChannel::refresh(AddrType rankID, AddrType bankID)
//{
//    ranks[rankID]->refresh(bankID);
//    lastRefresh  = globalClock;
//    timeRefresh += tREFI;
//}

// Precharge a bank
void DDRxChannel::precharge(AddrType rankID, AddrType bankID)
{
    ranks[rankID]->precharge(bankID);
    lastPrecharge = globalClock;
}

// Activate a row
void DDRxChannel::activate(AddrType rankID, AddrType bankID, AddrType rowID)
{
    ranks[rankID]->activate(bankID, rowID);
    lastActivate = globalClock;
}

// Read a block
void DDRxChannel::read(AddrType rankID, AddrType bankID, AddrType rowID)
{
    ranks[rankID]->read(bankID, rowID);
    lastRead = globalClock;
}

// Write a block
void DDRxChannel::write(AddrType rankID, AddrType bankID, AddrType rowID)
{
    ranks[rankID]->write(bankID, rowID);
    lastWrite = globalClock;
}

// Send a clock signal to the DDRx channel controller
void DDRxChannel::clock()
{
  // Update with respect to refresh
  for(long i = 0; i < schQueue.size(); i++) {
      DDRxReference *mref = schQueue[i];
      if(isRefreshing(mref->getRankID())) {
          mref->setPrechargePending(true);
          mref->setActivatePending(true);
      }
  }

  // Schedule a DDRx command if needed
  switch(schAlgorithm) {
      case 0: //FCFS
          scheduleFCFS();
          break;
      case 1: //FRFCFS
          scheduleFRFCFS();
          break;
//      case 2: //ParBS
//          scheduleParBS();
//          break;
//      case 3: //TCMS
//          scheduleTCMS();
//          break;
//      case 4: //TEST
//          scheduleTEST();
//          break;
      default:
          printf("ERROR: Illegal ID for DDRx command scheduler!\n");
          exit(0);
  }

  // Transfer a BURST if needed
  performBurst();

  // Update the DRAM power state
  updatePowerState();
}


// Basic refresh algorithm
//void DDRxChannel::scheduleBasicRefresh()
//{
//    // check all ranks for refresh
//    for(int r=0; r < numRanks; ++r) {
//        if(neededRefreshes(r, 0) && canIssueRefresh(r, 0)) {
//            refresh(r, 0);
//            updateQueueState();
//        }
//    }
//}

// DeferUntilEmpty refresh algorithm
//void DDRxChannel::scheduleDUERefresh()
//{
//    // check all ranks for refresh
//    for(int r=0; r < numRanks; ++r) {
//        int backlog = neededRefreshes(r, 0);
//
//        if(ranks[r]->needsUrgentRefresh()) {
//            if(canIssueRefresh(r, 0)) {
//                refresh(r, 0);
//                updateQueueState();
//            }
//            ranks[r]->setUrgentRefresh(backlog != 0);
//        }
//        else if(backlog > 0) {
//            switch (backlog) {
//                case 0:
//                case 1:
//                case 2:
//                case 3:
//                case 4:
//                case 5:
//                case 6:
//
//                    // check for any pending requests in rank buffers
//                    for(int i=0; i < schQueue.size(); ++i) {
//                        if(schQueue[i]->getRankID() == r) {
//                            break;
//                        }
//                    }
//
//                    // issue the refresh command if allowed
//                    if(canIssueRefresh(r, 0)) {
//                        refresh(r, 0);
//                        updateQueueState();
//                    }
//                    break;
//
//                case 7:
//                    // high priority
//
//                    // issue the refresh command if allowed
//                    if(canIssueRefresh(r, 0)) {
//                        refresh(r, 0);
//                        updateQueueState();
//                    }
//                    ranks[r]->setUrgentRefresh(true);
//                    break;
//
//                default:
//                    printf("ERROR: number of postponed refresh commands exceeded the limit!\n");
//                    exit(0);
//            }
//        }
//    }
//}


// ElasticRefresh algorithm
//void DDRxChannel::scheduleElasticRefresh()
//{
//    // check all ranks for refresh
//    for(int r=0; r < numRanks; ++r) {
//        int backlog = neededRefreshes(r, 0);
//
//        if(ranks[r]->needsUrgentRefresh()) {
//            if(canIssueRefresh(r, 0)) {
//                refresh(r, 0);
//                updateQueueState();
//            }
//            ranks[r]->setUrgentRefresh(backlog != 0);
//        }
//        else if(backlog > 0) {
//            switch (backlog) {
//                case 0:
//                case 1:
//                case 2:
//                    // constant delay
//                    if(consWait(r, 0)) {
//                        break;
//                    }
//
//                    // check for any pending requests in rank buffers
//                    for(int i=0; i < schQueue.size(); ++i) {
//                        if(schQueue[i]->getRankID() == r) {
//                            break;
//                        }
//                    }
//
//                    // issue the refresh command if allowed
//                    if(canIssueRefresh(r, 0)) {
//                        refresh(r, 0);
//                        updateQueueState();
//                    }
//                    break;
//                case 3:
//                case 4:
//                case 5:
//                case 6:
//                    // proportional delay
//                    if(propWait(r, 0)) {
//                        break;
//                    }
//
//                    // check for any pending requests in rank buffers
//                    for(int i=0; i < schQueue.size(); i++) {
//                        if(schQueue[i]->getRankID() == r) {
//                            break;
//                        }
//                    }
//
//                    // issue the refresh command if allowed
//                    if(canIssueRefresh(r, 0)) {
//                        refresh(r, 0);
//                        updateQueueState();
//                    }
//                    break;
//
//                case 7:
//                    // high priority
//
//                    // issue the refresh command if allowed
//                    if(canIssueRefresh(r, 0)) {
//                        refresh(r, 0);
//                        updateQueueState();
//                    }
//                    ranks[r]->setUrgentRefresh(true);
//                    break;
//
//                default:
//                    printf("ERROR: number of postponed refresh commands exceeded the limit!\n");
//                    exit(0);
//            }
//        }
//    }
//}


// FCFS command scheduling algorithm
void DDRxChannel::scheduleFCFS()
{
  DDRxReference *mref = NULL;

  if(schQueue.empty()) {
    return;
  }

  mref = schQueue[0];
  if(mref->needsPrecharge()) {
    if(canIssuePrecharge(mref->getRankID(), mref->getBankID())) {
      precharge(mref->getRankID(), mref->getBankID());
      mref->setPrechargePending(false);
      updateQueueState();
    }
    return;
  }

  if(mref->needsActivate()) {
    if(canIssueActivate(mref->getRankID(), mref->getBankID())) {
      activate(mref->getRankID(), mref->getBankID(), mref->getRowID());
      mref->setActivatePending(false);
      updateQueueState();
    }
    return;
  }

  if(mref->needsRead()) {
    if(canIssueRead(mref->getRankID(), mref->getBankID(), mref->getRowID())) {
      read(mref->getRankID(), mref->getBankID(), mref->getRowID());
      mref->setReadPending(false);
      mref->setBurstPending(true);
    }
    return;
  }

  if(mref->needsWrite()) {
    if(canIssueWrite(mref->getRankID(), mref->getBankID(), mref->getRowID())) {
      write(mref->getRankID(), mref->getBankID(), mref->getRowID());
      mref->setWritePending(false);
      mref->setBurstPending(true);
    }
    return;
  }
}



// FR-FCFS command scheduling algorithm
void DDRxChannel::scheduleFRFCFS()
{
    DDRxReference *mref = NULL;
    Time_t oldestTime = globalClock + 1;
    int oldestIndex = -1;

    // Find the oldest ready READ command
    for(int i=0; i < schQueue.size(); i++) {
        if((!schQueue[i]->needsPrecharge()) && (!schQueue[i]->needsActivate())) {
            if(schQueue[i]->needsRead()) {
                if(canIssueRead(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                    //If the read is older than the oldest CAS command found so far
                    if(schQueue[i]->getTimeStamp() < oldestTime) {
                        mref = schQueue[i];
                        oldestTime = schQueue[i]->getTimeStamp();
                        oldestIndex = i;
                    }
                }
            }
        }
    }

    // If no READ command was ready, find the oldest ready WRITE command
    if(mref == NULL) {
        for(int i=0; i < schQueue.size(); i++) {
            if((!schQueue[i]->needsPrecharge()) && (!schQueue[i]->needsActivate())) {
                if(schQueue[i]->needsWrite()) {
                    if(canIssueWrite(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                        //If the write is older than the oldest CAS command found so far
                        if(schQueue[i]->getTimeStamp() < oldestTime) {
                            mref = schQueue[i];
                            oldestTime = schQueue[i]->getTimeStamp();
                            oldestIndex = i;
                        }
                    }
                }
            }
        }
    }

    // If no READ command was ready, find the oldest ready (read) ACTIVATE
    if(mref == NULL) {
        for(int i=0; i < schQueue.size(); ++i) {
            if(schQueue[i]->needsActivate() && schQueue[i]->needsRead()) {
                if(canIssueActivate(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                    if(schQueue[i]->getTimeStamp() < oldestTime) {
                        mref = schQueue[i];
                        oldestTime = schQueue[i]->getTimeStamp();
                        oldestIndex = i;
                    }
                }
            }
        }
    }

    // If no (read) ACTIVATE command was ready, find the oldest ready (read) PRECHARGE
    if(mref == NULL) {
        for(int i=0; i < schQueue.size(); ++i) {
            if(schQueue[i]->needsPrecharge() && schQueue[i]->needsRead()) {
                if(canIssuePrecharge(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                    if(schQueue[i]->getTimeStamp() < oldestTime) {
                        mref = schQueue[i];
                        oldestTime = schQueue[i]->getTimeStamp();
                        oldestIndex = i;
                    }
                }
            }
        }
    }

    // If no WRITE command was ready, find the oldest ready (write) ACTIVATE
    if(mref == NULL) {
        for(int i=0; i < schQueue.size(); ++i) {
            if(schQueue[i]->needsActivate() && schQueue[i]->needsWrite()) {
                if(canIssueActivate(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                    if(schQueue[i]->getTimeStamp() < oldestTime) {
                        mref = schQueue[i];
                        oldestTime = schQueue[i]->getTimeStamp();
                        oldestIndex = i;
                    }
                }
            }
        }
    }

    // If no ACTIVATE command was ready, find the oldest ready (write) PRECHARE
    if(mref == NULL) {
        for(int i=0; i < schQueue.size(); ++i) {
            if(schQueue[i]->needsPrecharge() && schQueue[i]->needsWrite()) {
                if(canIssuePrecharge(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                    if(schQueue[i]->getTimeStamp() < oldestTime) {
                        mref = schQueue[i];
                        oldestTime = schQueue[i]->getTimeStamp();
                        oldestIndex = i;
                    }
                }
            }
        }
    }

    // Issue a ready command
    if(mref != NULL) {
        if(mref->needsPrecharge()) {
            if(canIssuePrecharge(mref->getRankID(), mref->getBankID())) {
                precharge(mref->getRankID(), mref->getBankID());
                mref->setPrechargePending(false);
                updateQueueState();
            }
            return;
        }

        if(mref->needsActivate()) {
            if(canIssueActivate(mref->getRankID(), mref->getBankID())) {
                activate(mref->getRankID(), mref->getBankID(), mref->getRowID());
                mref->setActivatePending(false);
                updateQueueState();
            }
            return;
        }

        if(mref->needsRead()) {
            if(canIssueRead(mref->getRankID(), mref->getBankID(), mref->getRowID())) {
                read(mref->getRankID(), mref->getBankID(), mref->getRowID());
                mref->setReadPending(false);
                mref->setBurstPending(true);
            }
            return;
        }

        if(mref->needsWrite()) {
            if(canIssueWrite(mref->getRankID(), mref->getBankID(), mref->getRowID())) {
                write(mref->getRankID(), mref->getBankID(), mref->getRowID());
                mref->setWritePending(false);
                mref->setBurstPending(true);
            }
            return;
        }
    }
}

/*
//PAR-BS command scheduling
void DDRxChannel::scheduleParBS() {
    bool isAnyMarked = false;
    bool isAnyValid  = false;

    // check for any remaining marked reference int the queue
    for(int i=0; i < schQueueSize; ++i) {
        if(schQueue[i]->isValid()) {
            isAnyValid = true;
        }
        if(schQueue[i]->isMarked()) {
            isAnyMarked = true;
        }
    }

    // proceed if there is a valid reference in the queue
    if(isAnyValid) {
        Time_t oldestTime = globalClock;
        DDRxReference *mRef = NULL;
        int lowestOrder = numThreads;
        int index = -1;

        // mark the references if needed
        if(!isAnyMarked) {
            // form a new batch by marking
            for(int i=0; i < schQueueSize; ++i) {
                schQueue[i]->setMarked(schQueue[i]->isValid());
            }

            // reset thread ordering counters
            for(int c=0; c < numThreads; ++c) {
                for(int b=0; b < numBanks; ++b) {
                    rules[c].bankLoad[b] = 0;
                }
                rules[c].coreID  = c;
                rules[c].totRule = 0;
            }

            // count the thread requests
            for(int i=0; i < schQueueSize; ++i) {
                if(schQueue[i]->isMarked()) {
                    int coreID = schQueue[i]->getCoreID();
                    AddrType bankID = schQueue[i]->getBankID();

                    if(coreID < 0 || coreID >= numThreads) {
                        //printf("ERROR: bad core id (%d) is used in Par-BS!\n", coreID);
                        //exit(1);
                        coreID = 0; // set to 0 for write back requests
                    }

                    ++rules[coreID].bankLoad[bankID];
                    ++rules[coreID].totRule;
                }
            }

            // find the maximum bank loads for threads
            for(int c=0; c < numThreads; ++c) {
                rules[c].maxRule = 0;
                for(int b=0; b < numBanks; ++b) {
                    if(rules[c].maxRule < rules[c].bankLoad[b]) {
                        rules[c].maxRule = rules[c].bankLoad[b];
                    }
                }
            }

            // ranking cores
            for(int i=0; i < numThreads-1; ++i) {
                for(int j=i+1; j < numThreads; ++j) {
                    if(rules[i].maxRule > rules[j].maxRule) {
                        rule = rules[i];
                        rules[i] = rules[j];
                        rules[j] = rule;
                    }
                    else if(rules[i].maxRule == rules[j].maxRule) {
                        if(rules[i].totRule > rules[j].totRule) {
                            rule = rules[i];
                            rules[i] = rules[j];
                            rules[j] = rule;
                        }
                    }
                }
            }

            // prioritize requests in the request queue
            for(int p=0; p < numThreads; ++p) {
                for(int i=0; i < schQueueSize; ++i) {
                    if((schQueue[i]->isMarked()) && (schQueue[i]->getCoreID() == rules[p].coreID)) {
                        schQueue[i]->setThreadOrder(p);
                    }
                }
            }

        } // end of marking


        // scheduling based on:
        // 1. Marked ready requests are prioritized over not marked
        // 2. Row hit request are prioritized over row conflict/closed requests
        // 3. Higher rank first
        // 4. Oldest first

        // find the CAS request among all marked requests
        for(int i=0; i < schQueueSize; ++i) {
            if(schQueue[i]->isValid() && schQueue[i]->isMarked()) {
                if((!schQueue[i]->needsPrecharge()) && (!schQueue[i]->needsActivate())) {
                    if(schQueue[i]->needsRead()) {
                        if(canIssueRead(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                            if(schQueue[i]->getThreadOrder() < lowestOrder) {
                                mRef = schQueue[i];
                                oldestTime  = schQueue[i]->getTimeStamp();
                                lowestOrder = schQueue[i]->getThreadOrder();
                                index = i;
                            }
                            else if((mRef != NULL) && (schQueue[i]->getThreadOrder() == lowestOrder)) {
                                if(schQueue[i]->getTimeStamp() < oldestTime) {
                                    mRef = schQueue[i];
                                    oldestTime  = schQueue[i]->getTimeStamp();
                                    lowestOrder = schQueue[i]->getThreadOrder();
                                    index = i;
                                }
                            }
                        }
                    }
                    else if(schQueue[i]->needsWrite()) {
                        if(canIssueWrite(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                            if(schQueue[i]->getThreadOrder() < lowestOrder) {
                                mRef = schQueue[i];
                                oldestTime  = schQueue[i]->getTimeStamp();
                                lowestOrder = schQueue[i]->getThreadOrder();
                                index = i;
                            }
                            else if((mRef != NULL) && (schQueue[i]->getThreadOrder() == lowestOrder)) {
                                if(schQueue[i]->getTimeStamp() < oldestTime) {
                                    mRef = schQueue[i];
                                    oldestTime  = schQueue[i]->getTimeStamp();
                                    lowestOrder = schQueue[i]->getThreadOrder();
                                    index = i;
                                }
                            }
                        }
                    }
                }
            }
        }

        // find the oldest high-priority RAS among all marked requests
        if(mRef == NULL) {
            for(int i=0; i < schQueueSize; ++i) {
                if(schQueue[i]->isValid() && schQueue[i]->isMarked()) {
                    if(schQueue[i]->needsPrecharge()) {
                        if(canIssuePrecharge(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                            if(schQueue[i]->getThreadOrder() < lowestOrder) {
                                mRef = schQueue[i];
                                oldestTime  = schQueue[i]->getTimeStamp();
                                lowestOrder = schQueue[i]->getThreadOrder();
                                index = i;
                            }
                            else if((mRef != NULL) && (schQueue[i]->getThreadOrder() == lowestOrder)) {
                                if(schQueue[i]->getTimeStamp() < oldestTime) {
                                    mRef = schQueue[i];
                                    oldestTime  = schQueue[i]->getTimeStamp();
                                    lowestOrder = schQueue[i]->getThreadOrder();
                                    index = i;
                                }
                            }
                        }
                    }
                    else if(schQueue[i]->needsActivate()) {
                        if(canIssueActivate(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                            if(schQueue[i]->getThreadOrder() < lowestOrder) {
                                mRef = schQueue[i];
                                oldestTime  = schQueue[i]->getTimeStamp();
                                lowestOrder = schQueue[i]->getThreadOrder();
                                index = i;
                            }
                            else if((mRef != NULL) && (schQueue[i]->getThreadOrder() == lowestOrder)) {
                                if(schQueue[i]->getTimeStamp() < oldestTime) {
                                    mRef = schQueue[i];
                                    oldestTime  = schQueue[i]->getTimeStamp();
                                    lowestOrder = schQueue[i]->getThreadOrder();
                                    index = i;
                                }
                            }
                        }
                    }
                }
            }
        }

        // find the CAS request among all un-marked requests
        if(mRef == NULL) {
            for(int i=0; i < schQueueSize; ++i) {
                if(schQueue[i]->isValid()) {
                    if((!schQueue[i]->needsPrecharge()) && (!schQueue[i]->needsActivate())) {
                        if(schQueue[i]->needsRead()) {
                            if(canIssueRead(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                                if(schQueue[i]->getThreadOrder() < lowestOrder) {
                                    mRef = schQueue[i];
                                    oldestTime  = schQueue[i]->getTimeStamp();
                                    lowestOrder = schQueue[i]->getThreadOrder();
                                    index = i;
                                }
                                else if((mRef != NULL) && (schQueue[i]->getThreadOrder() == lowestOrder)) {
                                    if(schQueue[i]->getTimeStamp() < oldestTime) {
                                        mRef = schQueue[i];
                                        oldestTime  = schQueue[i]->getTimeStamp();
                                        lowestOrder = schQueue[i]->getThreadOrder();
                                        index = i;
                                    }
                                }
                            }
                        }
                        else if(schQueue[i]->needsWrite()) {
                            if(canIssueWrite(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                                if(schQueue[i]->getThreadOrder() < lowestOrder) {
                                    mRef = schQueue[i];
                                    oldestTime  = schQueue[i]->getTimeStamp();
                                    lowestOrder = schQueue[i]->getThreadOrder();
                                    index = i;
                                }
                                else if((mRef != NULL) && (schQueue[i]->getThreadOrder() == lowestOrder)) {
                                    if(schQueue[i]->getTimeStamp() < oldestTime) {
                                        mRef = schQueue[i];
                                        oldestTime  = schQueue[i]->getTimeStamp();
                                        lowestOrder = schQueue[i]->getThreadOrder();
                                        index = i;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // find the oldest high-priority RAS among all un-marked requests
        if(mRef == NULL) {
            for(int i=0; i < schQueueSize; ++i) {
                if(schQueue[i]->isValid()) {
                    if(schQueue[i]->needsPrecharge()) {
                        if(canIssuePrecharge(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                            if(schQueue[i]->getThreadOrder() < lowestOrder) {
                                mRef = schQueue[i];
                                oldestTime  = schQueue[i]->getTimeStamp();
                                lowestOrder = schQueue[i]->getThreadOrder();
                                index = i;
                            }
                            else if((mRef != NULL) && (schQueue[i]->getThreadOrder() == lowestOrder)) {
                                if(schQueue[i]->getTimeStamp() < oldestTime) {
                                    mRef = schQueue[i];
                                    oldestTime  = schQueue[i]->getTimeStamp();
                                    lowestOrder = schQueue[i]->getThreadOrder();
                                    index = i;
                                }
                            }
                        }
                    }
                    else if(schQueue[i]->needsActivate()) {
                        if(canIssueActivate(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                            if(schQueue[i]->getThreadOrder() < lowestOrder) {
                                mRef = schQueue[i];
                                oldestTime  = schQueue[i]->getTimeStamp();
                                lowestOrder = schQueue[i]->getThreadOrder();
                                index = i;
                            }
                            else if((mRef != NULL) && (schQueue[i]->getThreadOrder() == lowestOrder)) {
                                if(schQueue[i]->getTimeStamp() < oldestTime) {
                                    mRef = schQueue[i];
                                    oldestTime  = schQueue[i]->getTimeStamp();
                                    lowestOrder = schQueue[i]->getThreadOrder();
                                    index = i;
                                }
                            }
                        }
                    }
                }
            }
        }

        // issue the next command if any
        if(mRef != NULL) {
            if(mRef->needsPrecharge()) {
                precharge(mRef->getRankID(), mRef->getBankID());
                mRef->setPrechargePending(false);
                updateQueueState();

                return;
            }

            if(mRef->needsActivate()) {
                activate(mRef->getRankID(), mRef->getBankID(), mRef->getRowID());
                mRef->setActivatePending(false);
                updateQueueState();
                return;
            }

            if(mRef->needsRead()) {
                read(mRef->getRankID(), mRef->getBankID(), mRef->getRowID());
                mRef->setReadPending(false);
                Time_t delay = mref->complete(DDRxMultiplier * (tCAS + tBL + 1));
                chanAvgMAT.sample((double) delay, true);
                //chanMinMAT.sample((double) delay, true);
                chanMaxMAT.sample((double) delay, true);
                freeList->push_back(index);
                return;
            }

            if(mRef->needsWrite()) {
                write(mRef->getRankID(), mRef->getBankID(), mRef->getRowID());
                mRef->setWritePending(false);
                Time_t delay = mref->complete(DDRxMultiplier * (tCWD + tBL + 1));
                chanAvgMAT.sample((double) delay, true);
                //chanMinMAT.sample((double) delay, true);
                chanMaxMAT.sample((double) delay, true);
                freeList->push_back(index);
                return;
            }
        }
    }
}

//TCM command scheduling
void DDRxChannel::scheduleTCMS()
{
    int c_ptr = -1;
    int index = -1;
    DDRxReference *mRef = NULL;

    // grouping threads at the begining of each quanta
    if((globalClock % 1000000) == 1) {
        // initialization
        unsigned long sumBW = 0;
        latencyCluster.clear();
        bandwidthCluster.clear();
        std::vector<int> unclassified;
        for(int i=0; i < numThreads; ++i) {
            unclassified.push_back(i);
        }

        // claculate total used bandwidth
        unsigned long totalBW = 0;
        for(int i=0; i < numThreads; ++i) {
            totalBW = totalBW + usedBW[i];
        }

        // threads classification
        while(!unclassified.empty()) {
            // find thread with lowest MPKI
            int j = 0;
            for(unsigned int i=1; i < unclassified.size(); ++i) {
                if(MPKI[unclassified[j]] > MPKI[unclassified[i]]) {
                    j = i;
                }
            }

            sumBW = sumBW + usedBW[unclassified[j]];
            if(sumBW <= (clusterThresh * totalBW / numThreads)) {
                latencyCluster.push_back(unclassified[j]);
                unclassified.erase(unclassified.begin() + j);
            }
            else {
                break;
            }
        }

        bandwidthCluster = unclassified;

        // reset statistics
        for(int i=0; i < numThreads; ++i) {
            usedBW[i] = 0;
        }

    }

    // update MPKI
    if((globalClock % 1000000) == 0) {
        for(int i=0; i < numThreads; ++i) {
            MPKI[i] = numMisses[i] >> 10;
            numMisses[i] = 0;
        }
    }


    // insertion shuffling
    if((globalClock % 800) == 0) {
        std::vector<int> tmp = bandwidthCluster;
        bandwidthCluster.clear();
        while(!tmp.empty()) {
            int r = rand()%tmp.size();
            bandwidthCluster.push_back(tmp[r]);
            tmp.erase(tmp.begin() + r);
        }
    }


    // scheduling
    // 1. highest-rank
    // 2. row-hit
    // 3. oldest
    if(!latencyCluster.empty()) { // latency-sensitive
        for(unsigned int j, i=0; i < schQueueSize; ++i) {
            if(schQueue[i]->isValid()) {
                for(j=0; j < latencyCluster.size(); ++j) {
                    if(schQueue[i]->getCoreID() == latencyCluster[j]) {
                        break;
                    }
                }

                if((j < latencyCluster.size()) && ((c_ptr == -1) || (c_ptr >= j))) {
                    // CAS
                    if((!schQueue[i]->needsPrecharge()) && (!schQueue[i]->needsActivate())) {
                        if(schQueue[i]->needsRead()) {
                            if(canIssueRead(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                                if((index == -1) || ((schQueue[i]->getTimeStamp() < schQueue[index]->getTimeStamp()) || schQueue[index]->needsActivate() || schQueue[index]->needsPrecharge())) {
                                    mRef = schQueue[i];
                                    index = i;
                                    c_ptr = j;
                                }
                            }
                        }
                        else if(schQueue[i]->needsWrite()) {
                            if(canIssueWrite(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                                if((index == -1) || ((schQueue[i]->getTimeStamp() < schQueue[index]->getTimeStamp()) || schQueue[index]->needsActivate() || schQueue[index]->needsPrecharge())) {
                                    mRef = schQueue[i];
                                    index = i;
                                    c_ptr = j;
                                }
                            }
                        }
                    }
                    // ACT
                    else if(!schQueue[i]->needsPrecharge()) {
                        if(canIssueActivate(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                            if((index == -1) || (((schQueue[i]->getTimeStamp() < schQueue[index]->getTimeStamp()) && schQueue[index]->needsActivate()) || schQueue[index]->needsPrecharge())) {
                                mRef = schQueue[i];
                                index = i;
                                c_ptr = j;
                            }
                        }
                    }
                    // PRE
                    else {
                        if(canIssuePrecharge(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                            if((index == -1) || ((schQueue[i]->getTimeStamp() < schQueue[index]->getTimeStamp()) && schQueue[index]->needsPrecharge())) {
                                mRef = schQueue[i];
                                index = i;
                                c_ptr = j;
                            }
                        }
                    }
                }
            }
        }
    }

    if(!mRef && !bandwidthCluster.empty()) { // bandwidth-sensitive
        for(int j, i=0; i < schQueueSize; ++i) {
            if(schQueue[i]->isValid()) {
                for(j=0; j < bandwidthCluster.size(); ++j) {
                    if(schQueue[i]->getCoreID() == bandwidthCluster[j])
                        break;
                }

                if((j < bandwidthCluster.size()) && ((c_ptr == -1) || (c_ptr >= j))) {
                    // CAS
                    if((!schQueue[i]->needsPrecharge()) && (!schQueue[i]->needsActivate())) {
                        if(schQueue[i]->needsRead()) {
                            if(canIssueRead(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                                if((index == -1) || ((schQueue[i]->getTimeStamp() < schQueue[index]->getTimeStamp()) || schQueue[index]->needsActivate() || schQueue[index]->needsPrecharge())) {
                                    mRef = schQueue[i];
                                    index = i;
                                    c_ptr = j;
                                }
                            }
                        }
                        else if(schQueue[i]->needsWrite()) {
                            if(canIssueWrite(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                                if((index == -1) || ((schQueue[i]->getTimeStamp() < schQueue[index]->getTimeStamp()) || schQueue[index]->needsActivate() || schQueue[index]->needsPrecharge())) {
                                    mRef = schQueue[i];
                                    index = i;
                                    c_ptr = j;
                                }
                            }
                        }
                    }
                    // ACT
                    else if(!schQueue[i]->needsPrecharge()) {
                        if(canIssueActivate(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                            if((index == -1) || (((schQueue[i]->getTimeStamp() < schQueue[index]->getTimeStamp()) && schQueue[index]->needsActivate()) || schQueue[index]->needsPrecharge())) {
                                mRef = schQueue[i];
                                index = i;
                                c_ptr = j;
                            }
                        }
                    }
                    // PRE
                    else {
                        if(canIssuePrecharge(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                            if((index == -1) || ((schQueue[i]->getTimeStamp() < schQueue[index]->getTimeStamp()) && schQueue[index]->needsPrecharge())) {
                                mRef = schQueue[i];
                                index = i;
                                c_ptr = j;
                            }
                        }
                    }
                }
            }
        }
    }

    // issue the next command if any
    if(mRef != NULL) {
        if(mRef->needsPrecharge()) {
//            ++usedBW[mRef->getCoreID()];

            precharge(mRef->getRankID(), mRef->getBankID());
            mRef->setPrechargePending(false);
            updateQueueState();

            return;
        }

        if(mRef->needsActivate()) {
            ++usedBW[mRef->getCoreID()];

            activate(mRef->getRankID(), mRef->getBankID(), mRef->getRowID());
            mRef->setActivatePending(false);
            updateQueueState();

            return;
        }

        if(mRef->needsRead()) {
            ++usedBW[mRef->getCoreID()];

            read(mRef->getRankID(), mRef->getBankID(), mRef->getRowID());
            mRef->setReadPending(false);
            Time_t delay = mref->complete(DDRxMultiplier * (tCAS + tBL + 1));
            chanAvgMAT.sample((double) delay, true);
            //chanMinMAT.sample((double) delay, true);
            chanMaxMAT.sample((double) delay, true);
            freeList->push_back(index);

            return;
        }

        if(mRef->needsWrite()) {
            ++usedBW[mRef->getCoreID()];

            write(mRef->getRankID(), mRef->getBankID(), mRef->getRowID());
            mRef->setWritePending(false);
            Time_t delay = mref->complete(DDRxMultiplier * (tCWD + tBL + 1));
            chanAvgMAT.sample((double) delay, true);
            //chanMinMAT.sample((double) delay, true);
            chanMaxMAT.sample((double) delay, true);
            freeList->push_back(index);

            return;
        }
    }

}



//Schedule a command using test scheduling
void DDRxChannel::scheduleTEST()
{
    DDRxReference *mRef = NULL;
    Time_t oldestTime = globalClock;
    int index = -1;

    for(int i=0; i<schQueueSize; i++) {
        if(schQueue[i]->isValid()) {
            if((!schQueue[i]->needsPrecharge()) && (!schQueue[i]->needsActivate())) {
                if(schQueue[i]->needsRead()) {
                    if(canIssueRead(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                        if(schQueue[i]->getTimeStamp() < oldestTime) {
                            mRef = schQueue[i];
                            oldestTime = schQueue[i]->getTimeStamp();
                            index = i;
                        }
                    }
                }
                else if(schQueue[i]->needsWrite()) {
                    if(canIssueWrite(schQueue[i]->getRankID(), schQueue[i]->getBankID(), schQueue[i]->getRowID())) {
                        if(schQueue[i]->getTimeStamp() < oldestTime) {
                            if((index == -1) || (!schQueue[index]->needsRead())) {
                                mRef = schQueue[i];
                                oldestTime = schQueue[i]->getTimeStamp();
                                index = i;
                            }
                        }
                    }
                }
            }
        }
    }

    if(mRef == NULL) {
        for(int i=0; i<schQueueSize; i++) {
            if(schQueue[i]->isValid()) {
                if(schQueue[i]->needsPrecharge()) {
                    if(canIssuePrecharge(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                        if(schQueue[i]->getTimeStamp() < oldestTime) {
                            mRef = schQueue[i];
                            oldestTime = schQueue[i]->getTimeStamp();
                            index = i;
                        }
                    }
                }
                else if(schQueue[i]->needsActivate()) {
                    if(canIssueActivate(schQueue[i]->getRankID(), schQueue[i]->getBankID())) {
                        if(schQueue[i]->getTimeStamp() < oldestTime) {
                            mRef = schQueue[i];
                            oldestTime = schQueue[i]->getTimeStamp();
                            index = i;
                        }
                    }
                }
            }
        }
    }

    if(mRef != NULL) {
        if(mRef->needsPrecharge()) {

//            bool bCAS = false;
//            for(int i=0; i<schQueueSize; i++) {
//                if(schQueue[i]->isValid() && ((!schQueue[i]->needsPrecharge()) && (!schQueue[i]->needsActivate()))) {
//                    if((schQueue[i]->getRankID() == mRef->getRankID()) && (schQueue[i]->getBankID() == mRef->getBankID())) {
//                        bCAS = true;
//                    }
//                }
//            }
//
//            if(bCAS) {
//                return;
//            }

            precharge(mRef->getRankID(), mRef->getBankID());
            mRef->setPrechargePending(false);
            updateQueueState();
            return;
        }

        if(mRef->needsActivate()) {
            activate(mRef->getRankID(), mRef->getBankID(), mRef->getRowID());
            mRef->setActivatePending(false);
            updateQueueState();
            return;
        }

        if(mRef->needsRead()) {
            read(mRef->getRankID(), mRef->getBankID(), mRef->getRowID());
            mRef->setReadPending(false);
            Time_t delay = mref->complete(DDRxMultiplier * (tCAS + tBL + 1));
            chanAvgMAT.sample((double) delay, true);
            //chanMinMAT.sample((double) delay, true);
            chanMaxMAT.sample((double) delay, true);
            freeList->push_back(index);
            return;
        }

        if(mRef->needsWrite()) {
            write(mRef->getRankID(), mRef->getBankID(), mRef->getRowID());
            mRef->setWritePending(false);
            Time_t delay = mref->complete(DDRxMultiplier * (tCWD + tBL + 1));
            chanAvgMAT.sample((double) delay, true);
            //chanMinMAT.sample((double) delay, true);
            chanMaxMAT.sample((double) delay, true);
            freeList->push_back(index);
            return;
        }
    }

}

*/


// Performing Data Burst
void DDRxChannel::performBurst()
{
  int index;
  DDRxReference *mref = NULL;
  // Find the oldest ready to complete burst
  for(int i=0; i < schQueue.size() && mref == NULL; i++) {
      //printf("*\n");
      if(schQueue[i]->needsBurst()) {
          //printf("\t%s\taddr: %016lx\n", schQueue[i]->isRead()? "R": "W", schQueue[i]->getMReq()->getPAddr());
          if(globalClock > (schQueue[i]->isRead()? (lastRead + tCAS): (lastWrite + tCWD)) + tBL) {
              //MSG("BURST Complete!");
              mref = schQueue[i];
              index = i;
          }
      }
  }

  // Complete data burst
  if(mref != NULL) {
      Time_t delay = mref->complete();
      chanAvgMAT.sample(true, (double) delay);
      //chanMinMAT.sample((double) delay);
      chanMaxMAT.sample(true, (double) delay);
      //transfer((unsigned char *) mref->getData());
      delete mref;
      schQueue.erase(schQueue.begin() + index);
  }
}


// DDRx Interface
DDRx::DDRx(MemorySystem* current, const char *section, const char *name)
  /* constructor {{{1 */
  : MemObj(section, name)
  , clockScheduled(false)

  , countReceived("%s:received", name)
  , countServiced("%s:serviced", name)

  //, freqBlockUsage("%s:freqBlockUsage", name)
  //, freqPageUsage("%s:freqPageUsage", name)
  //, freqFootPrint("%s:freqFootPrint", name)
  //, tracFootPrint("%s:tracFootPrint", name)

  , avgAccessTime("%s:avgAccessTime", name)
  , tracAccessTime("%s:tracAccessTime", name)
{
  MemObj *lower_level = NULL;

  I(current);

  SescConf->isBool(section, "DDRxBypassed");
  DDRxBypassed = SescConf->getBool(section, "DDRxBypassed");

  DDRxMultiplier = SescConf->getInt(section, "multiplier");
  if(DDRxMultiplier != 1) {
    printf("ERROR: DDRxMultiplier must be set to 1!\n");
    exit(0);
  }

  // check config parameters
  SescConf->isInt(section, "addrMapping");
  SescConf->isPower2(section, "size", 0);
  SescConf->isPower2(section, "numChannels", 0);
  SescConf->isPower2(section, "numRanks", 0);
  SescConf->isPower2(section, "numBanks", 0);
  SescConf->isPower2(section, "pageSize", 0);
  SescConf->isPower2(section, "llcSize", 0);
  SescConf->isPower2(section, "llcAssoc", 0);
  SescConf->isPower2(section, "llcBlkSize", 0);
  SescConf->isPower2(section, "softPageSize", 0);

  // read in config parameters
  addrMapping  = SescConf->getInt(section, "addrMapping");
  size         = SescConf->getInt(section, "size") * 1024LL * 1024LL; // HBM Size (MB)
  numChannels  = SescConf->getInt(section, "numChannels");
  numRanks     = SescConf->getInt(section, "numRanks");
  numBanks     = SescConf->getInt(section, "numBanks");
  pageSize     = SescConf->getInt(section, "pageSize");
  llcSize      = SescConf->getInt(section, "llcSize");
  llcAssoc     = SescConf->getInt(section, "llcAssoc");
  llcBlkSize   = SescConf->getInt(section, "llcBlkSize");
  softPageSize = SescConf->getInt(section, "softPageSize");

  // intermediate parameters
  numChannelsLog2  = log2(numChannels);
  numRanksLog2     = log2(numRanks);
  numBanksLog2     = log2(numBanks);
  pageSizeLog2     = log2(pageSize);
  llcBlkSizeLog2   = log2(llcBlkSize);
  llcEffSizeLog2   = log2(llcSize/llcAssoc);
  softPageSizeLog2 = log2(softPageSize);


  // internal organization
  channels = *(new std::vector<DDRxChannel *>(numChannels));
  for(int c = 0; c < numChannels; ++c) {
    char temp[256]; sprintf(temp, "%s:%d", name, c);
    channels[c] = new DDRxChannel(section, temp, numRanks, numBanks);
  }

  // enable refresh
  SescConf->isInt(section, "refAlgorithm");
  if(SescConf->getInt(section, "refAlgorithm") == 1) {
      for(int c = 0; c < numChannels; ++c) {
          for(int r = 0; r < numRanks; ++r) {
              channels[c]->enableRefresh(r, (double)(c*numRanks+r) / (double) (numChannels*numRanks));
          }
      }
  }

  // statistics
  //freqBlockUsage.setPFName(SescConf->getCharPtr("", "reportFile",0));
  //freqBlockUsage.setPlotLabels("Block Usage", "Frequency");
  //freqPageUsage.setPFName(SescConf->getCharPtr("", "reportFile",0));
  //freqPageUsage.setPlotLabels("Page Usage", "Frequency");
  tracAccessTime.setPFName(SescConf->getCharPtr("", "reportFile",0));
  tracAccessTime.setPlotLabels("Execution Time (x1024 cycles)", "Average Access Time (cycles)");
  //tracFootPrint.setPFName(SescConf->getCharPtr("", "reportFile",0));
  //tracFootPrint.setPlotLabels("Execution Time (x1024 cycles)", "Memory Footprint (bytes)");
  //freqFootPrint.setPFName(SescConf->getCharPtr("", "reportFile",0));
  //freqFootPrint.setPlotLabels("Footprint", "Frequency");

  // display conf
  printf("DDRx [Size: %ld, Channels:%ld, Ranks:%ld, Banks:%ld, pageSize:%ld]\n", size, numChannels, numRanks, numBanks, pageSize);

  // set the lower level
  lower_level = current->declareMemoryObj(section, "lowerLevel");
  if(lower_level) {
    addLowerLevel(lower_level);
  }
}
/* }}} */

void DDRx::doReq(MemRequest *mreq)
  /* request reaches the memory controller {{{1 */
{
#if 0
#define BLKBITS 6
#define BLKSIZE (1<<BLKBITS)
#define BLKWORD (BLKSIZE>>3)
  char *MsgActionStr[9] = {
        "ma_setInvalid",
        "ma_setValid",
        "ma_setDirty",
        "ma_setShared",
        "ma_setExclusive",
        "ma_MMU",
        "ma_VPCWU",
        "ma_MAX",
        NULL
  };
  uint64_t *data = (uint64_t *) mreq->getData();
  //printf("R %016lx %016lx ", mreq->getAddr(), *((uint64_t *)mreq->getAddr()));
  //printf("R %016lx ", mreq->getAddr());
  printf("%s\t%016lx ", MsgActionStr[mreq->getAction()], mreq->getAddr());
  if(data) {
    for(int i=BLKWORD-1; i >= 0; --i) {
      printf("%016lx", data[i]);
    }
  }
  printf("\n");
#endif

  //MSG("\nDDRx::doReq for Addr %llx", mreq->getAddr());
  if(mreq->getAction() == ma_setDirty) {
      addRequest(mreq, false);
  }
  else {
      addRequest(mreq, true);
  }
}
/* }}} */

void DDRx::doReqAck(MemRequest *mreq)
  /* push up {{{1 */
{
  I(0);
}
/* }}} */

void DDRx::doDisp(MemRequest *mreq)
  /* push down {{{1 */
{
#if 0
#define BLKBITS 6
#define BLKSIZE (1<<BLKBITS)
#define BLKWORD (BLKSIZE>>3)
  char *MsgActionStr[9] = {
        "ma_setInvalid",
        "ma_setValid",
        "ma_setDirty",
        "ma_setShared",
        "ma_setExclusive",
        "ma_MMU",
        "ma_VPCWU",
        "ma_MAX",
        NULL
  };
  //uint64_t *data = (uint64_t *) mreq->getData();
  //printf("W %016lx %016lx ", mreq->getAddr(), *((uint64_t *)mreq->getAddr()));
  //printf("W %016lx ", mreq->getAddr());
  printf("%s\t%lx ", MsgActionStr[mreq->getAction()], mreq->getAddr());
  //if(data) {
  //  for(int i=BLKWORD-1; i >= 0; --i) {
  //    printf("%016lx", data[i]);
  //  }
  //}
  printf("\n");
#endif

  //MSG("\nDDRx::doDisp for Addr %llx", mreq->getAddr());
  if(mreq->getAction() == ma_setDirty) {
  	  addRequest(mreq, false);
  }
  else {
      addRequest(mreq, true);
  }
}
/* }}} */

void DDRx::doSetState(MemRequest *mreq)
  /* push up {{{1 */
{
  MSG("\nDDRx::doSetState for Addr %llx", mreq->getAddr());
  I(0);
}
/* }}} */

void DDRx::doSetStateAck(MemRequest *mreq)
  /* push up {{{1 */
{
  MSG("\nDDRx::doSetStateAck for Addr %llx", mreq->getAddr());
//  I(0);
}
/* }}} */

bool DDRx::isBusy(AddrType addr) const
/* always can accept writes {{{1 */
{
  return false;
}
/* }}} */

void DDRx::tryPrefetch(AddrType addr, bool doStats)
  /* try to prefetch to openpage {{{1 */
{
  MSG("\nDDRx::tryPrefetch for Addr %llx", addr);
  // FIXME:
}
/* }}} */

TimeDelta_t DDRx::ffread(AddrType addr)
  /* fast forward reads {{{1 */
{
  MSG("\nDDRx::ffread for Addr %llx", addr);
  return 0; //delay + RowAccessLatency;
}
/* }}} */

TimeDelta_t DDRx::ffwrite(AddrType addr)
  /* fast forward writes {{{1 */
{
  MSG("\nDDRx::ffwrite for Addr %llx", addr);
  return 0; //delay + RowAccessLatency;
}
/* }}} */


// adding memory requests
void DDRx::addRequest(MemRequest *mreq, bool read)
{
  AddrType addr = mreq->getAddr() & (size - 1);
  AddrType chanID, rankID, bankID, rowID;

  //freqBlockUsage.sample(true, addr>>llcBlkSizeLog2);
  //freqPageUsage.sample(true, addr>>softPageSizeLog2);
  //freqFootPrint.sample(true, addr>>softPageSizeLog2);

  // map memory addresses
  switch(addrMapping) {
  case 0: // Page Interleaving
    chanID = (addr >>  pageSizeLog2)&(numChannels - 1);
    rankID = (addr >> (pageSizeLog2 + numChannelsLog2)) & (numRanks - 1);
    bankID = (addr >> (pageSizeLog2 + numChannelsLog2 + numRanksLog2)) & (numBanks - 1);
    rowID  = (addr >> (pageSizeLog2 + numChannelsLog2 + numRanksLog2 + numBanksLog2));// & (numRows - 1);
    break;

  case 1: // Block Interleaving
    chanID = (addr >>  llcBlkSizeLog2)&(numChannels - 1);
    rankID = (addr >> (llcBlkSizeLog2 + numChannelsLog2)) & (numRanks - 1);
    bankID = (addr >> (llcBlkSizeLog2 + numChannelsLog2 + numRanksLog2)) & (numBanks - 1);
    rowID  = (addr >> (pageSizeLog2   + numChannelsLog2 + numRanksLog2 + numBanksLog2));// & (numRows - 1);
    break;

  case 2: // Permutation Based Page Interleaving
    chanID = (addr >>  pageSizeLog2)&(numChannels - 1);
    rankID = (addr >> (pageSizeLog2 + numChannelsLog2)) & (numRanks - 1);
    bankID = (addr >> (pageSizeLog2 + numChannelsLog2 + numRanksLog2)) & (numBanks - 1);
    rowID  = (addr >> (pageSizeLog2 + numChannelsLog2 + numRanksLog2 + numBanksLog2));// & (numRows - 1);
	//printf("rowID is %x\n",rowID);
    chanID = chanID ^ ((addr >> (llcEffSizeLog2)) & (numChannels - 1));
    rankID = rankID ^ ((addr >> (llcEffSizeLog2 + numChannelsLog2)) & (numRanks - 1));
    bankID = bankID ^ ((addr >> (llcEffSizeLog2 + numRanksLog2 + numChannelsLog2)) & (numBanks - 1));
    break;

  default:
    printf("ERROR: Invalid address mapping ID %d!\n", addrMapping);
    exit(0);
  }


  // dispatch memory requests
  DDRxReference *mref = new DDRxReference();

  // set the memory reference fields
  mref->setTimeStamp(globalClock);
  mref->setMReq(mreq);
  mref->setChannelID(chanID);
  mref->setRankID(rankID);
  mref->setBankID(bankID);
  mref->setRowID(rowID);
  mref->setReady(false);
  mref->setMarked(false);
  mref->setRead(read);
  mref->setReplicated(false);
  mref->setBurstPending(false);

  //if((addr>=0x10002c60)&&(addr<0x10804461)) printf("DDRx\t%s\t%08llx\n", mref->isRead()? "R": "W", addr);
  //printf("\nChannel %ld receives a request with address %08lx.\n", chanID, mreq->getPAddr());

  receivedQueue.push(mref);
  countReceived.inc();

  // schedule a clock edge
  if(!clockScheduled) {
    clockScheduled = true;
    CallbackBase *cb = ManageDDRxCB::create(this);
    EventScheduler::schedule((TimeDelta_t) 1, cb);
  }
}


// DDRx cycle by cycle management
void DDRx::manageDDRx(void)
{
  // dispatch memory refrences to channel controllers
  if(DDRxBypassed) {
    while(receivedQueue.size()) {
      DDRxReference *mref = receivedQueue.front();
      mref->complete();
      delete mref;
      receivedQueue.pop();
    }
  }
  else {
    bool notFull = true;
    while(receivedQueue.size() && notFull) {
      DDRxReference *mref = receivedQueue.front();
      notFull = channels[mref->getChannelID()]->addReference(mref);
      if(notFull) {
        receivedQueue.pop();
      }
    }
  }

  finishDDRx();

  for(int c = 0; c < numChannels; ++c) {
    channels[c]->clock();
  }

  // sample trackers
  if((globalClock & 0x3FFFF) == 0) {
  	tracAccessTime.sample(true, globalClock>>10, avgAccessTime.getDouble());
    //tracFootPrint.sample(true, globalClock>>10, freqFootPrint.getSamples() * softPageSize);
  }

  // schedule a clock edge
  clockScheduled = false;
  if(!DDRxBypassed && (countServiced.getDouble() < countReceived.getDouble())) {
      clockScheduled = true;
      CallbackBase *cb = ManageDDRxCB::create(this);
      EventScheduler::schedule((TimeDelta_t) DDRxMultiplier, cb);
  }
}


// complete memory request
void DDRx::finishDDRx(void)
{
  while(DDRxServicedQ.size()) {
    ServicedRequest sreq = DDRxServicedQ.front();

    I(sreq.mreq);

    if(sreq.mreq->isDisp()) {
      sreq.mreq->ack();  // Fixed doDisp Acknowledge -- LNB 5/28/2014
    }
    else {
      I(sreq.mreq->isReq());

      if (sreq.mreq->getAction() == ma_setValid || sreq.mreq->getAction() == ma_setExclusive) {
        sreq.mreq->convert2ReqAck(ma_setExclusive);
      }
      else {
        sreq.mreq->convert2ReqAck(ma_setDirty);
      }

      avgAccessTime.sample(sreq.time, true);
      router->scheduleReqAck(sreq.mreq, 1);  //  Fixed doReq acknowledge -- LNB 5/28/2014
    }

    DDRxServicedQ.pop();
    countServiced.inc();
  }
}
