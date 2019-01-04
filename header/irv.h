#ifndef IRV_H_
#define IRV_H_

#include "global.h"
#include "sdd.h"
#include "utils.h"
#include "uninomial.h"

int getWinner(dyn_tab candidates, int sum);
int minCandidates(dyn_tab candidates);
void rmLowerCandidate(dyn_tab *candidates, dyn_mat *ballot);
char *instant_runnoff_voting(dyn_mat_str ballot);
dyn_mat calculus(dyn_mat_str ballot);
void incrementBallot(dyn_mat *ballot, int ind);
int minim(int *nbr, int n, dyn_tab candidates);
int sumCandidateH(dyn_tab candidates);

#endif
