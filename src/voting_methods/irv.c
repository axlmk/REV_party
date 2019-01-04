#include "../../header/irv.h"


int getWinner(dyn_tab candidates, int sum) {
    int i;
    for(i=0;i<candidates.dim;i++)
        if(candidates.tab[i] >= sum/2)
            return i;
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

void rmLowerCandidate(dyn_tab *candidates, dyn_mat *ballot) {
    int ind = minCandidates(*candidates);
    candidates->tab[ind] = -1;
    incrementBallot(ballot, ind);
}

int sumCandidateH(dyn_tab candidates) {
    int i, res=0;
    for(i=0;i<candidates.dim;i++) {
        if(candidates.tab[i] != -1)
            res+=candidates.tab[i];
    }
    return res;
}
void incrementBallot(dyn_mat *ballot, int ind) {
    int i, j;
    for(i=0;i<ballot->nbRows;i++) {
        for(j=0;j<ballot->nbCols;j++) {
            if(ballot->tab[i][ind] < ballot->tab[i][j]) {
                ballot->tab[i][j]--;
            }
        }
    }
}

dyn_mat calculus(dyn_mat_str ballot) {
    dyn_mat vote;
    createDynIntMat(&vote, ballot.nbRows-1, ballot.nbCols - ballot.offset);
    int i, j;
    for(i=0;i<vote.nbRows;i++) {
        for(j=0;j<vote.nbCols;j++) {
            vote.tab[i][j] = strtoi(ballot.tab[i+1][j+ballot.offset]);
        }
    }
    return vote;
}

void initCandidates(dyn_tab *candidates, dyn_mat ballot) {
    int i;
    for(i=0;i<candidates->dim;i++) {
        if(candidates->tab[i] != -1)
            candidates->tab[i] = 0;
    }
    for(i=0;i<ballot.nbRows;i++) {
        int u = minim(ballot.tab[i], ballot.nbCols, *candidates);
        if(u!=-1 && candidates->tab[u] != -1)
            candidates->tab[u]++;
    }
}

int minim(int *nbr, int n, dyn_tab candidates) {
    int i, min = nbr[0], ind = 0;
    for(i=1;i<n;i++) {
        if(candidates.tab[i] != -1) {
            if(nbr[i] < min) {
                min = nbr[i];
                ind = i;
            } else if(min == nbr[i]) {
                ind = -1;
            }
        }
    }
    return ind;
}

char *instant_runnoff_voting(dyn_mat_str ballot) {
    int win=0;
    dyn_mat ballotInt = calculus(ballot);
    dyn_tab candidates = generateCandidateList(ballotInt);
    /*if(isLog()) {
        fprintf(logfp, "---- Instant-runnoff voting display : ----\n\n");
        fprintf(logfp, "Display of the ballot matrix : \n");
        printDynIntMat(ballotInt, logfp);
        fprintf(logfp, "Display of the candidate list : \n");
        printDynIntTab(candidates, logfp);
    }*/
    win = getWinner(candidates, sumCandidateH(candidates));
    while(win == -1) {
        rmLowerCandidate(&candidates, &ballotInt);
        initCandidates(&candidates, ballotInt);
        if(isLog()) {
            fprintf(logfp, "Display of the candidate list : \n");
            /*int w, k;
            for(k=0;k<10;k++) {
                for(w=0;w<ballotInt.nbCols;w++)
                printf("%d, ", ballotInt.tab[k][w]);
                printf("\n");
            } printf("\n");*/
            printDynIntTab(candidates, logfp);
        }
        win = getWinner(candidates, sumCandidateH(candidates));
    }
    return (ballot.tab[0][ballot.offset + win]);
}
