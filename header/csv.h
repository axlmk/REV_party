#ifndef CSV_H_
#define CSV_H_

#include "global.h"
#include "sdd.h"
#include "graph.h"

char *ftos(FILE *f);
int lenFile(FILE *f);
dyn_mat_str ftomat(FILE *f, csvType vote);
void countStr(char *str, int *nbRows, int *nbCols);

#endif
