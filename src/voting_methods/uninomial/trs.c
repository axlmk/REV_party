#include "../../../header/uninomial.h"

int sumCandidate(dyn_tab candidates) {
    int i, res;
    for(i=0;i<candidates.dim;i++)
        res += candidates.tab[i];
    return res;
}

int trs(dyn_mat_str vote, char **winner, char **challenger, int *val1, int *val2, int *val3) {
    int i, ifir, isec, fir, sec, sum;
    dyn_tab candidates = generateCandidateList(vote);
    sum = sumCandidate(candidates);
    if(listValid(candidates)) {
        ifir = findBestCandidate(candidates, val1);
        *val1 = *val1 * 100 / (vote.nbRows - 1);
        fir = candidates.tab[ifir];
        if(fir <= sum/2) {
            candidates.tab[ifir] = -1;
            isec = findBestCandidate(candidates, val2);
            *val2 = *val2 * 100 / (vote.nbRows - 1);
            sec = candidates.tab[isec];
            for(i=1;i<vote.nbRows;i++) {
                if(strtoi(vote.tab[i][ifir + vote.offset]) > strtoi(vote.tab[i][isec + vote.offset])) {
                    fir++;
                } else if(strtoi(vote.tab[i][isec + vote.offset]) < strtoi(vote.tab[i][isec + vote.offset])) {
                    sec++;
                }
            }
            if(fir > sec) {
                *winner = vote.tab[0][ifir+vote.offset];
                *challenger = vote.tab[0][isec+vote.offset];
                *val3 = fir * 100 / (vote.nbRows - 1);
            } else {
                *winner = vote.tab[0][isec+vote.offset];
                *challenger = vote.tab[0][ifir+vote.offset];
                *val3 = sec * 100 / (vote.nbRows - 1);
            }
        } else {
            *winner = vote.tab[0][ifir+vote.offset];
        }
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Error, the list of candidates doesn't contain at least one valid voter.\n");
        return EXIT_FAILURE;
    }
}
