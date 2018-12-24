#include "../../header/uninomial.h"

int findMin(dyn_mat_str vote, int row) {
    int i, val, index = 0, mini = strtoi(vote.tab[row][1]);
    bool valid = true;
    for(i=2;i<vote.nbCols - vote.offset;i++) { //looking for the min in a specified row
        val = strtoi(vote.tab[row][i]);
        if(val < mini) {
            mini = val;
            valid = true;
            index = i-1;
        } else if(val == mini){
            valid = false;
        }
    }
    if(valid) { //the vote is valid (only one winner per voter)
        return index;
    } else {
        return -1;
    }
}

int findBestCandidate(dyn_tab candidates) {
    int i, index = 0, maxi = candidates.tab[0];
    for(i=1;i<candidates.dim;i++) {
        if(candidates.tab[i] > maxi) {
            maxi = candidates.tab[i];
            index = i;
        }
    }
    return index;
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

dyn_tab generateCandidateList(dyn_mat_str vote) {
    int i, choice;
    dyn_tab candidates = createCandidateList(vote);
    for(i=1;i<vote.nbRows;i++) {
        choice = findMin(vote, i);
        if(choice != -1) {
            candidates.tab[choice]++;
        }
    }
    return candidates;
}

int fptp(dyn_mat_str vote, char **winner) {
    dyn_tab candidates = generateCandidateList(vote);
    if(listValid(candidates)) {
        *winner = vote.tab[0][findBestCandidate(candidates)+1];
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Error, the list of candidates doesn't contain at least one valid voter.\n");
        return EXIT_FAILURE;
    }
}
