#ifndef UNINOMIAL_H_
#define UNINOMIAL_H_

#include "global.h"
#include "sdd.h"
#include "utils.h"

int findMin(dyn_mat_str vote, int row);
dyn_tab createCandidateList(dyn_mat_str vote);
bool listValid(dyn_tab candidates);
int fptp(dyn_mat_str vote, char **winner);
int findMax(dyn_tab candidates);


#endif
