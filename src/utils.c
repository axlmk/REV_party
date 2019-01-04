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

dyn_mat ballottoduel(dyn_mat_str vote, csvType type) {
    int i, j, k;
    dyn_mat duel;
    createDynIntMat(&duel, vote.nbCols-vote.offset, vote.nbCols-vote.offset);
    for(i=1;i<vote.nbRows;i++) {
        for(j=vote.offset;j<vote.nbCols;j++) {
            if(type == BALLOT) {
                for(k=vote.offset;k<vote.nbCols;k++) {
                    if(j!=k) {
                        if(strtoi(vote.tab[i][j]) < strtoi(vote.tab[i][k])) {
                            duel.tab[j - vote.offset][k - vote.offset]++;
                        }
                    }
                }
            } else {
                duel.tab[i-1][j-vote.offset] = strtoi(vote.tab[i][j]);
            }
        }
    }
    return duel;
}

bool isLog() {
    return logfpName != NULL;
}
