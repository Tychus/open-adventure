#include <stdbool.h>

/*  STATEMENT FUNCTIONS
 *
 *  AT(OBJ)	= TRUE IF ON EITHER SIDE OF TWO-PLACED OBJECT
 *  CNDBIT(L,N) = TRUE IF COND(L) HAS BIT N SET (BIT 0 IS UNITS BIT)
 *  DARK(DUMMY) = TRUE IF LOCATION "LOC" IS DARK
 *  FORCED(LOC) = TRUE IF LOC MOVES WITHOUT ASKING FOR INPUT (COND=2)
 *  FOREST(LOC)  = TRUE IF LOC IS PART OF THE FOREST
 *  GSTONE(OBJ)  = TRUE IF OBJ IS A GEMSTONE
 *  HERE(OBJ)	= TRUE IF THE OBJ IS AT "LOC" (OR IS BEING CARRIED)
 *  LIQ(DUMMY)	= OBJECT NUMBER OF LIQUID IN BOTTLE
 *  LIQLOC(LOC) = OBJECT NUMBER OF LIQUID (IF ANY) AT LOC
 *  PCT(N)       = TRUE N% OF THE TIME (N INTEGER FROM 0 TO 100)
 *  TOTING(OBJ) = TRUE IF THE OBJ IS BEING CARRIED */

#define TOTING(OBJ)	(PLACE[OBJ] == -1)
#define AT(OBJ) (PLACE[OBJ] == LOC || FIXED[OBJ] == LOC)
#define HERE(OBJ)	(AT(OBJ) || TOTING(OBJ))
#define LIQ2(PBOTL)	((1-(PBOTL))*WATER+((PBOTL)/2)*(WATER+OIL))
#define LIQ(DUMMY)	(LIQ2(PROP[BOTTLE]<0 ? -1-PROP[BOTTLE] : PROP[BOTTLE]))
#define LIQLOC(LOC)	(LIQ2((MOD(COND[LOC]/2*2,8)-5)*MOD(COND[LOC]/4,2)+1))
#define CNDBIT(L,N)	(TSTBIT(COND[L],N))
#define FORCED(LOC)	(COND[LOC] == 2)
#define DARK(DUMMY)	((!CNDBIT(LOC,0)) && (PROP[LAMP] == 0 || !HERE(LAMP)))
#define PCT(N)	(RAN(100) < (N))
#define GSTONE(OBJ)	((OBJ) == EMRALD || (OBJ) == RUBY || (OBJ) == AMBER || (OBJ) == SAPPH)
#define FOREST(LOC)	((LOC) >= 145 && (LOC) <= 166)
#define VOCWRD(LETTRS,SECT)	(VOCAB(MAKEWD(LETTRS),SECT))

/*  THE FOLLOWING TWO FUNCTIONS WERE ADDED TO FIX A BUG (CLOCK1 DECREMENTED
 *  WHILE IN FOREST).  THEY SHOULD PROBABLY BE REPLACED BY USING ANOTHER
 *  "COND" BIT.  FOR NOW, HOWEVER, A QUICK FIX...  OUTSID(LOC) IS TRUE IF
 *  LOC IS OUTSIDE, INDEEP(LOC) IS TRUE IF LOC IS "DEEP" IN THE CAVE (HALL
 *  OF MISTS OR DEEPER).  NOTE SPECIAL KLUDGES FOR "FOOF" LOCS. */

#define OUTSID(LOC)	((LOC) <= 8 || FOREST(LOC) || (LOC) == PLAC[SAPPH] || (LOC) == 180 || (LOC) == 182)
#define INDEEP(LOC)	((LOC) >= 15 && !OUTSID(LOC) && (LOC) != 179)

extern int carry(void), discard(bool), attack(void), throw(void), feed(void), fill(void);
void score(long);




