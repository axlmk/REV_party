#ifndef CONDORCET_H_
#define CONDORCET_H_

#include "ballot.h"

int minimax(dyn_mat duel);

int isCondorcetWinner(list duel, int nbCandidate);

list dueltolistranked(dyn_mat duel);
list rankedPairs(dyn_mat duel);

list duelToSchwartz(dyn_mat duel);
int schulze(dyn_mat duel);

#endif
