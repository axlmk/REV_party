#ifndef CONDORCET_H_
#define CONDORCET_H_

#include "global.h"
#include "list.h"
#include "sdd.h"
#include "circuit.h"

//#define MAX(a, b) ((a>)?(printf("TRUE\n")):printf("FALSE\n"))
//CODE

int minimax(dyn_mat duel);

int isCondorcetWinner(list duel, int nbCandidate);

list dueltolistranked(dyn_mat duel);
list rankedpairs(dyn_mat duel);


#endif
