/// \file utils.h
/// \brief Donne des outils utiles pour plusieurs fonctions dans tous le programme
/// \author Axel GAUTHIER
/// \date 2019

#ifndef UTILS_H_
#define UTILS_H_

#include "global.h"
#include "sdd.h"
#include "list.h"

#define MAX_NUM_SIZE 5

char *incr(char *s);
dyn_mat ballottoduel(dyn_mat_str vote, csvType type);
bool isLog();
list dueltolist(dyn_mat duel);

#endif
