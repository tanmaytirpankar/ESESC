/* License & includes {{{1 */
/*
   ESESC: Super ESCalar simulator
   Copyright (C) 2010 University of California, Santa Cruz.

   Contributed by Luis Ceze
                  Jose Renau
                  Karin Strauss
                  Milos Prvulovic

This file is part of ESESC.

ESESC is free software; you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation;
either version 2, or (at your option) any later version.

ESESC is distributed in the  hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
ESESC; see the file COPYING. If not, write to the Free Software Foundation, 59
Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include <stdio.h>
#include <math.h>

#include "SescConf.h"

#include "CCache.h"
#include "NICECache.h"
#include "SL0Cache.h"
#include "VPC.h"
#include "TLB.h"
#include "Bus.h"
#include "StridePrefetcher.h"
#include "GlobalHistoryBuffer.h"
#include "Splitter.h"
#include "MemXBar.h"
#include "UnMemXBar.h"
#include "MemorySystem.h"
#include "MemController.h"
#include "MarkovPrefetcher.h"

#include "WideIO.h"
#include "XAMIO.h"
#include "DDRx.h"

#include "DrawArch.h"
extern DrawArch arch;


/* }}} */


MemorySystem::MemorySystem(int32_t processorId)
  /* constructor {{{1 */
  : GMemorySystem(processorId)
{

}
/* }}} */

MemObj *MemorySystem::buildMemoryObj(const char *device_type, const char *dev_section, const char *dev_name)
  /* build the correct memory object {{{1 */
{
  // Returns new created MemoryObj or NULL in known-error mode 
  MemObj *mdev=0;
  uint32_t devtype = 0; //CCache

  std::string mystr("");
  // You may insert here the further specializations you may need
  if (!strcasecmp(device_type, "cache") || !strcasecmp(device_type, "icache")) {
    mdev = new CCache(this, dev_section, dev_name);
    devtype = 0;
  } else if (!strcasecmp(device_type, "nicecache")) {
    mdev = new NICECache(this, dev_section, dev_name);
    devtype = 1;
  } else if (!strcasecmp(device_type, "SL0")) {
    //mdev = new SL0Cache(this, dev_section, dev_name);
		I(0);
    devtype = 2;
  } else if (!strcasecmp(device_type, "VPC")) {
    //mdev = new VPC(this, dev_section, dev_name);
		I(0);
    devtype = 3;
  } else if (!strcasecmp(device_type, "ghb")) {
    //mdev = new GHB(this, dev_section, dev_name);
		I(0);
    devtype = 4;
  } else if (!strcasecmp(device_type, "stridePrefetcher")) {
    mdev = new StridePrefetcher(this, dev_section, dev_name);
    devtype = 5;
  } else if (!strcasecmp(device_type, "markovPrefetcher")) {
    mdev = new MarkovPrefetcher(this, dev_section, dev_name);
    devtype = 6;
/*
  } else if (!strcasecmp(device_type, "taggedPrefetcher")) {
    mdev = new TaggedPrefetcher(this, dev_section, dev_name);
    devtype = 7;
*/
  }  else if (!strcasecmp(device_type, "bus")) {
    mdev = new Bus(this, dev_section, dev_name);
    devtype = 8;
  } else if (!strcasecmp(device_type, "tlb")) {
    devtype = 9;
    mdev = new TLB(this, dev_section, dev_name);
  } else if (!strcasecmp(device_type, "memxbar")) {
    mdev = new MemXBar(this, dev_section, dev_name);
    devtype = 11;
  } else if (!strcasecmp(device_type, "memcontroller")) {
    mdev = new MemController(this, dev_section, dev_name);
    devtype = 13;
  } else if (!strcasecmp(device_type, "wideio")) {
    mdev = new WideIO(this, dev_section, dev_name);
    devtype = 20;
  } else if (!strcasecmp(device_type, "xamio")) {
    mdev = new XAMIO(this, dev_section, dev_name);
    devtype = 21;
  } else if (!strcasecmp(device_type, "ddrx")) {
    mdev = new DDRx(this, dev_section, dev_name);
    devtype = 23;
  } else if (!strcasecmp(device_type, "void")) {
    return new DummyMemObj(dev_section,dev_name);
  } else {
    // Check the lower level because it may have it
    return GMemorySystem::buildMemoryObj(device_type, dev_section, dev_name);
  }


#if GOOGLE_GRAPH_API
#else
  mystr += "\n\"";
  mystr += mdev->getName();

  switch(devtype){
    case 0: //CCache
      mystr += "\"[shape=record,sides=5,peripheries=2,color=darkseagreen1,style=filled]";
      break;
    case 1: //NiceCache
      mystr += "\"[shape=record,sides=5,peripheries=2,color=coral,style=filled]";
      break;
    case 2: //SL0
    case 3: //VPC
      mystr += "\"[shape=record,sides=5,peripheries=2,color=pink,style=filled]";
      //Fetch the CCache related parameters : Size, bsize, name, inclusive, ports
      break;
    case 4: //GHB
    case 5: //stridePrefetcher
    case 6: //markovPrefetcher
    case 7: //taggedPrefetcher
      mystr += "\"[shape=record,sides=5,peripheries=1,color=lightcoral,style=filled]";
      break;
    case 8://bus
      mystr += "\"[shape=record,sides=5,peripheries=1,color=lightpink,style=filled]";
      break;
    case 9://tlb
      mystr += "\"[shape=record,sides=5,peripheries=1,color=lavender,style=filled]";
      break;
    case 10: //ScratchXBar //ScratchUnXBar //PECacheXBar //PECacheUnXBar
    case 11: //MemXBar
    case 12: //MemXBar
      mystr += "\"[shape=record,sides=5,peripheries=1,color=thistle,style=filled]";
      break;
    case 13: //memcontroller
      mystr += "\"[shape=record,sides=5,peripheries=1,color=skyblue,style=filled]";
      break;
    case 20: //WideIO
      mystr += "\"[shape=record,sides=5,peripheries=1,color=chartreuse3,style=filled]";
      break;
    case 21: //XAMIO
      mystr += "\"[shape=record,sides=5,peripheries=1,color=gold,style=filled]";
      break;
    case 23: //DDRx
      mystr += "\"[shape=record,sides=5,peripheries=1,color=chartreuse3,style=filled]";
      break;
    default:
      mystr += "\"[shape=record,sides=5,peripheries=3,color=white,style=filled]";
      break;
  }
  arch.addObj(mystr);
#endif

  I(mdev);
  addMemObjName(mdev->getName());
#ifdef DEBUG
  LOG("Added: %s", mdev->getName());
#endif

  return mdev;
}
/* }}} */
