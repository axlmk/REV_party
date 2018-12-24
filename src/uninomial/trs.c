#include "../../header/uninomial.h"

int sumCandidate(dyn_tab candidates) {
    int i, res;
    for(i=0;i<candidates.dim;i++)
        res += candidates.tab[i];
    return res;
}

int trs(dyn_mat_str vote, char **winner, char **challenger) {
    int i, ifir, isec, fir, sec, sum;
    dyn_tab candidates = generateCandidateList(vote);
    sum = sumCandidate(candidates);

    if(listValid(candidates)) {
        ifir = findBestCandidate(candidates);
        fir = candidates.tab[ifir];
        if(fir <= sum/2) {
            candidates.tab[ifir] = -1;
            isec = findBestCandidate(candidates);
            sec = candidates.tab[isec];

            for(i=1;i<vote.nbRows;i++) {
                if(strtoi(vote.tab[i][ifir+1]) == 2) {
                    fir++;
                } else if(strtoi(vote.tab[i][isec+1]) == 2) {
                    sec++;
                }
            }

            if(fir > sec) {
                *winner = vote.tab[0][ifir+1];
                *challenger = vote.tab[0][isec+1];
            } else {
                *winner = vote.tab[0][isec+1];
                *challenger = vote.tab[0][ifir+1];
            }
        } else {
            *winner = vote.tab[0][ifir+1];
        }
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Error, the list of candidates doesn't contain at least one valid voter.\n");
        return EXIT_FAILURE;
    }
}
