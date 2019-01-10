/// \file ballot.h
/// \brief Centralise les fonctions communes aux algorithmes de méthodes de scrutin
/// \author Axel GAUTHIER
/// \2019

#ifndef BALLOT_H_
#define BALLOT_H_

#include "global.h"
#include "sdd.h"
#include "list.h"
#include "circuit.h"
#include "utils.h"
#include "graph.h"

dyn_mat strmattointmat(dyn_mat_str ballot);
int findMin(dyn_mat vote, int row);
int findBestCandidate(dyn_tab candidates, int *value);
dyn_tab generateCandidateList(dyn_mat vote);


#endif
