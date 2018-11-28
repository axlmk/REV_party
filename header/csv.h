#ifndef CSV_H_
#define CSV_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sdd.h"
#include "global.h"

void getSize(FILE *f, int row, int col);
int lenFile(FILE *f);
dyn_mat_str openMatrix(FILE *f, csvType vote);


#endif
