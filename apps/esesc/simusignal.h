#ifndef SIMUSIGNAL_H
#define SIMUSIGNAL_H
#define SIG_NORMAL  0x00000
#define SIG_NOSIMU  0x00001
#define SIG_NCACHE  0x00002
#define SIG_RAMPAD  0x00004
#define SIG_CAMPAD  0x00008
#define SIG_COLUMN  0x00010
#define SIG_SEARCH  0x00020
#define SIG_KEYMEM  0x00040
#define SIG_MSKMEM  0x00080
#define SIG_DOQEMU	0x00100
#define SIG_DOHASH  0x00200
#define SIG_DOSMAT	0x00400
//#define SIG_XLOPBK  0x00100
//#define SIG_XBPASS  0x00200
//#define SIG_XIDEAL  0x00400
//#define SIG_XREPLC  0x00500
//#define SIG_XFOLDR  0x00600
#define SIMUSIGNAL(X, Y, Z) (syscall(5402, (Z), (X), &((X)[(Y)])))					//This can be re-used for KMeans address init
#define SIMUSIGNAL_SEARCH(X, Y, Z) (syscall(5402, (Z), (X), (Y)))

//for KMEANS
#define SIMUSIGNAL_KMEANS(X, Y, Z) (syscall(5402, (Z), (X), (Y))
#endif // SIMUSIGNAL_H
