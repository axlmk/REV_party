#include "../header/utils.h"

int strtoi(char *s) {
    char *c;
    return strtol(s, &c, 10);
}

char *incr(char *s) { //a changer
    int i = strtoi(s);
    char *s2;
    i++;
    sprintf(s2, "%d", i);
    return s2;
}

dyn_mat ballottoduel(dyn_mat_str vote) {
    int i, j, k;
    dyn_mat duel;
    createDynIntMat(&duel, vote.nbCols-vote.offset-1, vote.nbCols-vote.offset-1);
    for(i=1;i<vote.nbRows;i++) {
        for(j=1;j<vote.nbCols - vote.offset;j++) {
            for(k=1;k<vote.nbCols - vote.offset;k++) {
                if(j!=k) {
                    if(strtoi(vote.tab[i][j]) < strtoi(vote.tab[i][k])) {
                        duel.tab[j-1][k-1]++;
                    } else if(strtoi(vote.tab[i][j]) == strtoi(vote.tab[i][k])) {
                        duel.tab[k-1][j-1]++;
                        duel.tab[j-1][k-1]++;
                    }
                }
            }
        }
    }
    return duel;
}
