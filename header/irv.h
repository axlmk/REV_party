#ifndef IRV_H_
#define IRV_H_

#include "global.h"
#include "sdd.h"

int getWinner(dyn_tab candidates, int sum);
int minCandidates(dyn_tab candidates);
void rmLowerCandidate(dyn_tab *candidates);
char *instant_runnoff_voting(dyn_mat_str ballot);

#endif
