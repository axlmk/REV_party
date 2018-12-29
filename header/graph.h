#ifndef GRAPH_H_
#define GRAPH_H_

#include "global.h"
#include "sdd.h"
#include "list.h"
#include "csv.h"

list dueltolist(dyn_mat duel);
int generateFile(list duel);
void dumpListGraph(list p,FILE *fp);

#endif
