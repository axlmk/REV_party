#include "../../header/uninomial.h"

int findMin(dyn_mat_str vote, int row) {
    int i, index = 0, mini = strtoi(vote.tab[row][1]);
    bool valid = true;
    for(i=2;i<vote.nbCols - vote.offset;i++) { //looking for the min in a specified row
        //printf("ALED %d\n", strtoi(vote.tab[row][i]));
        if(strtoi(vote.tab[row][i]) < mini) {
            mini = strtoi(vote.tab[row][i]);
            valid = true;
            index = i-1;
        } else if(strtoi(vote.tab[row][i]) == mini){
            valid = false;
        }
    }
    if(valid) { //the vote is valid (only one winner per voter)
        return index;
    } else {
        return -1;
    }
}

int findMax(dyn_tab candidates) {
    int i, index = 0, maxi = candidates.tab[0];
    for(i=1;i<candidates.dim;i++) {
        if(candidates.tab[0] > maxi) {
            maxi = candidates.tab[0];
            index = i;
        }
    }
    return index+1;
}

dyn_tab createCandidateList(dyn_mat_str vote) {
    int i;
    dyn_tab candidates;
    createDynIntTab(&candidates, vote.nbCols - vote.offset - 1);
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

int fptp(dyn_mat_str vote, char **winner) {
    int i, choice;
    dyn_tab candidates = createCandidateList(vote);
    for(i=1;i<vote.nbRows;i++) {
        choice = findMin(vote, i);
        //printf("DEBUG %d\n", choice);
        if(choice != -1) {
            candidates.tab[choice]++;
        }
    }
    if(listValid(candidates)) {
        *winner = vote.tab[0][findMax(candidates)];
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Error, the list of candidates doesn't contain at least one valid voter.\n");
        return EXIT_FAILURE;
    }
}
