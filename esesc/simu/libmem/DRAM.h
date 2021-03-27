
#ifndef DRAM_H
#define DRAM_H

// Bank state
enum STATE {
    IDLE = 0,
    ACTIVE
};

// DDRx Power state
enum POWERSTATE {
    sIDD2PF = 0,   // CKE low, all banks precharged, fast-exit mode
    sIDD2PS,       // CKE low, all banks precharged, slow-exit mode
    sIDD3P,        // CKE low, at least one bank active, fast-exit mode
    sIDD2N,        // CKE high, all banks precharged
    sIDD3N         // CKE high, at least one bank active
};

// Exit mode register
enum EMR {
    SLOW = 0,      // Slow-exit mode
    FAST           // Fast-exit mode
};

// DRAM Cache Command
enum DRAMCommand {
    COMNON = 0,
    COMPRE,
    COMACT,
    COMOPN,
    COMRED,
    COMWRT,
    COMLOD,
    COMUDT,
    COMEVT,
    COMINS
};

// DRAM Cache Burst Type
enum BurstType {
    NONE = 0,
    READ,
    WRITE,
    LOAD,
    UPDATE
};

// Cache Reference State
enum ReferenceState {
    UNKNOWN = 0,
    LOOPBAK,
    SKIPPED,
    PREFTCH,    // New state for prefetching - fromHunter
    SCRATCH,
    READTAG,
    DOCHECK,
    MATCHED,
    DOFETCH,
    DOPLACE,
    FINDTAG,
    DOEVICT,
    WRITEBK,
    INSTALL,
    SENDTAG,
    SENDKEY,
    GETDATA,
    DODIRTY,
    PUTDATA,
    JOBDONE
};

// Cache Reference State String
static char * ReferenceStateStr[] = {
    "UNKNOWN",
    "LOOPBAK",
    "SKIPPED",
    "PREFTCH",  // fromHunter
    "SCRATCH",
    "READTAG",
    "DOCHECK",
    "MATCHED",
    "DOFETCH",
    "DOPLACE",
    "FINDTAG",
    "DOEVICT",
    "WRITEBK",
    "INSTALL",
    "SENDTAG",
    "SENDKEY",
    "GETDATA",
    "DODIRTY",
    "PUTDATA",
    "JOBDONE",
    NULL
};

// Serviced request
typedef struct _SERVICEDREQUEST {
  Time_t time;
  Time_t tchk;
  MemRequest *mreq;
} ServicedRequest;

#endif // DRAM_H
