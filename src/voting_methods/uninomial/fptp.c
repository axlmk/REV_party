#include "../../../header/uninominal.h"

int findMin(dyn_mat vote, int row) {
    int i, index = 0, mini = vote.tab[row][0];
    for(i=1;i<vote.nbCols;i++) {
        if(vote.tab[row][i] < mini) {
            mini = vote.tab[row][i];
            index = i;
        } else if(vote.tab[row][i] == mini){
            index = -1;
        }
    }
    return index;
}

int findBestCandidate(dyn_tab candidates, int *val) {
    int i, index = 0, maxi = candidates.tab[0];
    if(isLog()) {
        fprintf(logfp, "Maximum value founder :\n");
    }
    for(i=1;i<candidates.dim;i++) {
        if(candidates.tab[i] > maxi) {
            maxi = candidates.tab[i];
            index = i;
            if(isLog()) {
                fprintf(logfp, "\t max = %d\n\t index = %d\n", maxi, index);
            }
        }
    }
    if(isLog()) {
        fprintf(logfp, "\t max = %d\n\t index = %d\n", maxi, index);
    }
    *val = maxi;
    return index;
}

dyn_tab createCandidateList(dyn_mat vote) {
    int i;
    dyn_tab candidates;
    createDynIntTab(&candidates, vote.nbCols);
    for(i=0;i<candidates.dim;i++) {
        candidates.tab[i] = 0;
    }
    return candidates;
}

bool listValid(dyn_tab candidates) {
    int i;
    for(i=0;i<candidates.dim;i++) {
        if(candidates.tab[i]!=0) {
            return true;
        }
    } return false;
}

dyn_tab generateCandidateList(dyn_mat vote) {
    int i, choice;
    dyn_tab candidates = createCandidateList(vote);
    for(i=0;i<vote.nbRows;i++) {
        choice = findMin(vote, i);
        if(choice != -1) {
            candidates.tab[choice]++;
        }
    }
    return candidates;
}

int fptp(dyn_mat_str vote, char **winner, int *value) {
    dyn_mat lol = strmattointmat(vote);
    dyn_tab candidates = generateCandidateList(lol);
    if (isLog()) {
        fprintf(logfp, "---- First-past-the-post display : ----\n\n");
        fprintf(logfp, "Display of the candidates table : \n");
        printDynIntTab(candidates, logfp);
    }
    if(listValid(candidates)) {
        *winner = vote.tab[0][findBestCandidate(candidates, value) + vote.offset];
        *value = *value * 100 / (vote.nbRows - 1);
        if(isLog()) {
            fprintf(logfp, "\n");
        }
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Error, the list of candidates doesn't contain at least one valid voter.\n");
        return EXIT_FAILURE;
    }
}
