/// \file uninominal.h
/// \brief Calcul du gagnant grâce aux fonctions uninominals un et deux tours et leurs dépendances
/// \author Axel GAUTHIER
/// \date 2019

#ifndef UNINOMIAL_H_
#define UNINOMIAL_H_

#include "ballot.h"
dyn_tab createCandidateList(dyn_mat vote);
bool listValid(dyn_tab candidates);
int fptp(dyn_mat_str vote, char **winner, int *value);

int trs(dyn_mat_str vote, char **winner, char **challenger, int *val1, int *val2, int *val3);
int sumCandidate(dyn_tab candidates);

#endif
