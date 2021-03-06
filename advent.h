#include <stdio.h>
#include <stdbool.h>

#define LINESIZE	100
#define NDWARVES	6

typedef struct lcg_state
{
  unsigned long a, c, m, x;
} lcg_state;

extern long ABB[], ATLOC[], BLKLIN, DFLAG, DLOC[], FIXED[], HOLDNG,
		LINK[], LNLENG, LNPOSN,
		PARMS[], PLACE[];
extern char rawbuf[LINESIZE], INLINE[LINESIZE+1], MAP1[], MAP2[];
extern FILE *logfp;
extern bool oldstyle;
extern lcg_state lcgstate;

/* b is not needed for POSIX but harmless */
#define READ_MODE "rb"
#define WRITE_MODE "wb"

extern void SPEAK(long);
extern void PSPEAK(long,long);
extern void RSPEAK(long);
extern void SETPRM(long,long,long);

extern bool fGETIN(FILE *,long*,long*,long*,long*);
#define GETIN(input,WORD1,WORD1X,WORD2,WORD2X) fGETIN(input,&WORD1,&WORD1X,&WORD2,&WORD2X)

extern long YES(FILE *,long,long,long);
extern long GETTXT(long,long,long);
extern long MAKEWD(long);

extern void fPUTTXT(long,long*,long);
#define PUTTXT(WORD,STATE,CASE) fPUTTXT(WORD,&STATE,CASE)

extern void SHFTXT(long,long);
extern void TYPE0();

extern void fSAVWDS(long*,long*,long*,long*,long*,long*,long*);
#define SAVWDS(W1,W2,W3,W4,W5,W6,W7) fSAVWDS(&W1,&W2,&W3,&W4,&W5,&W6,&W7)
extern void fSAVARR(long*,long);
#define SAVARR(ARR,N) fSAVARR(ARR,N)
extern void fSAVWRD(long,long*);
#define SAVWRD(OP,WORD) fSAVWRD(OP,&WORD)

extern long VOCAB(long,long);
extern void DSTROY(long);
extern void JUGGLE(long);
extern void MOVE(long,long);
extern long PUT(long,long,long);
extern void CARRY(long,long);
extern void DROP(long,long);
extern long ATDWRF(long);
extern long SETBIT(long);
extern bool TSTBIT(long,int);
extern long RNDVOC(long,long);
extern void BUG(long);
extern void MAPLIN(FILE *);
extern void TYPE();
extern void MPINIT();

extern void fSAVEIO(long,long,long*);
#define SAVEIO(OP,IN,ARR) fSAVEIO(OP,IN,ARR)
extern void DATIME(long*, long*);

extern long MOD(long,long);

extern void set_seed(long);
extern unsigned long get_next_lcg_value(void);
extern long randrange(long);

extern void score(long);
extern long ABBNUM, AMBER, ATTACK, AXE, BACK, BATTER, BEAR,
   BIRD, BLOOD, BONUS,
   BOTTLE, CAGE, CAVE, CAVITY, CHAIN, CHASM, CHEST, CHLOC, CHLOC2,
   CLAM, CLOCK1, CLOCK2, CLOSED, CLOSNG, CLSHNT,
   COINS, CONDS, DALTLC, DETAIL,
   DKILL, DOOR, DPRSSN, DRAGON, DSEEN[], DTOTAL, DWARF, EGGS,
   EMRALD, ENTER, ENTRNC, FIND, FISSUR, FOOBAR, FOOD,
   GRATE, HINT, HINTED[], HINTLC[],
   I, INVENT, IGO, IWEST, J, JADE, K, K2, KEYS, KK,
   KNFLOC, KNIFE, KQ, L, LAMP, LIMIT, LL,
  LMWARN, LOC, LOCK, LOOK,
   MAGZIN, MAXDIE, MAXTRS, MESSAG, MIRROR, MXSCOR,
   NEWLOC, NOVICE, NUGGET, NUL, NUMDIE, OBJ,
   ODLOC[], OGRE, OIL, OLDLC2, OLDLOC, OLDOBJ, OYSTER,
   PANIC, PEARL, PILLOW, PLANT, PLANT2, PROP[], PYRAM,
   RESER, ROD, ROD2, RUBY, RUG, SAPPH, SAVED, SAY,
   SCORE, SECT, SETUP, SIGN, SNAKE, SPK, STEPS, STICK,
   STREAM, TALLY, THRESH, THROW, TK[], TRIDNT,
   TRNDEX, TRNLUZ, TROLL, TROLL2,
   TURNS, URN, V1, V2, VASE, VEND, VERB,
   VOLCAN, VRSION, WATER, WD1, WD1X, WD2, WD2X,
   WZDARK, ZZWORD;

