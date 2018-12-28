#include "../../header/graph.h"

list dueltolist(dyn_mat duel) {
    int i, j;
    Elementlist e;
    list graph;
    createList(&graph);
    for(i=0;i<duel.nbRows;i++) {
        for(j=0;j<i;j++) {
            if(duel.tab[i][j] > duel.tab[j][i]) {
                e.src = i;
                e.dest = j;
                e.weight = duel.tab[i][j];
            } else {
                e.src = j;
                e.dest = i;
                e.weight = duel.tab[j][i];
            }
            addTailList(&graph, e);
        }
    }
    return graph;
}
