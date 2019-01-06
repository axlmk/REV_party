#include "../header/utils.h"

char *incr(char *s) {
    int i = atoi(s);
    char *s2 = malloc(sizeof(char) * 10);
    i++;
    sprintf(s2, "%d", i);
    return s2;
}

dyn_mat ballottoduel(dyn_mat_str vote, csvType type) {
    int i, j, k;
    dyn_mat duel;
    createDynIntMat(&duel, vote.nbCols-vote.offset, vote.nbCols-vote.offset);
    for(i=1;i<vote.nbRows;i++) {
        for(j=vote.offset;j<vote.nbCols;j++) {
            if(type == BALLOT) {
                for(k=vote.offset;k<vote.nbCols;k++) {
                    if(j!=k) {
                        if(atoi(vote.tab[i][j]) < atoi(vote.tab[i][k])) {
                            duel.tab[j - vote.offset][k - vote.offset]++;
                        }
                    }
                }
            } else {
                duel.tab[i-1][j-vote.offset] = atoi(vote.tab[i][j]);
            }
        }
    }
    return duel;
}

bool isLog() {
    return logfpName != NULL;
}

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
