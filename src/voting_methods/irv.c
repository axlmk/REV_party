#include "../../header/irv.h"

int getWinner(dyn_tab candidates, int sum) {
    int i;
    for(i=0;i<candidates.dim;i++) {
        if(candidates.tab[i] >= sum/2) {
            return i;
        }
    }
    return -1;
}

int minCandidates(dyn_tab candidates) {
    int i, min = candidates.tab[0], ind = 0;
    for(i=1;i<candidates.dim;i++) {
        if(candidates.tab[i] < min && candidates.tab[i] >= 0) {
            min = candidates.tab[i];
            ind = i;
        }
    }
    return ind;
}

void rmLowerCandidate(dyn_tab *candidates) {
    int ind = minCandidates(*candidates);
    int points = candidates->tab[ind];
    candidates->tab[ind] = -1;
    candidates->tab[minCandidates(*candidates)] += points;
}

char *instant_runnoff_voting(dyn_mat_str ballot) {
    int i, j, win=0;
    dyn_tab candidates;
    createDynIntTab(&candidates, ballot.nbCols - ballot.offset - 1);
    for(i=0;i<candidates.dim;i++)
        candidates.tab[i] = 0;
    for(i=0;i<ballot.nbRows;i++) {
        for(j=ballot.offset+1;j<ballot.nbCols;j++) {
            if(!strcmp(ballot.tab[i][j], "1")) {
                candidates.tab[j - ballot.offset - 1]++;
            }
        }
    }
    win = getWinner(candidates, ballot.nbRows-1);
    while(win == -1) {
        rmLowerCandidate(&candidates);
        win = getWinner(candidates, ballot.nbRows-1);
    }
    return (ballot.tab[0][ballot.offset + 1 + win]);
}
