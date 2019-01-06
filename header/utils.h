#ifndef UTILS_H_
#define UTILS_H_

#include "global.h"
#include "sdd.h"
#include "list.h"

#define MAX_NUM_SIZE 5

char *incr(char *s);
dyn_mat ballottoduel(dyn_mat_str vote, csvType type);
bool isLog();

#endif
