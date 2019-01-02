#include "../../../header/condorcet.h"


list dueltolistranked(dyn_mat duel) {
    int i, j;
    Elementlist e;
    list graph;
    createList(&graph);
    for(i=0;i<duel.nbRows;i++) {
        for(j=0;j<i;j++) {
            if(duel.tab[i][j] > duel.tab[j][i]) {
                e.src = i;
                e.dest = j;
                e.weight = duel.tab[i][j] - duel.tab[i][j];
            } else {
                e.src = j;
                e.dest = i;
                e.weight = duel.tab[j][i] - duel.tab[i][j];
            }
            addTailList(&graph, e);
        }
    }
    return graph;
}

list rankedPairs(dyn_mat duel) { //faut verifier que circuits fonctionne parce que c'est bizarre que pour vote.csv il en trouve aucun
    list ranked = dueltolistranked(duel);
    list temp;
    int i;
    createList(&temp);
    bubbleSortListWDown(&ranked);
    for(i=0;i<nbEltList(ranked);i++) {
        addTailList(&temp, ranked.arrList[i]);
        dumpList(temp, stdout);
        printf("----\n");
        if(circuits(temp, duel.nbCols)) {
            printf("DEBUG\n");
            delTailList(&temp);
        }
    }
    return temp;
}
