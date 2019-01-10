#include "../../../header/uninominal.h"

int sumCandidate(dyn_tab candidates) {
    /// \brief Renvoie la somme des voix de tous les candidats
    /// \param[in] candidates : Liste des candidats
    /// \return La somme des voix
    int i, res;
    for(i=0;i<candidates.dim;i++)
        res += candidates.tab[i];
    return res;
}

int trs(dyn_mat_str vote, char **winner, char **challenger, int *val1, int *val2, int *val3) {
    /// \brief Donne le ou les vainqueurs selon la méthode uninominal à deux tours
    /// \param[in] vote : Matrice de votes
    /// \param[out] winner : Vainqueur
    /// \param[out] challenger : Deuxième élu
    /// \param[out] val1 : Pourcentage vainqueur 1er tour
    /// \param[out] val2 : Pourcentage deuxième élu 1er tour
    /// \param[out] val3 : Pourcentage vainqueur 2ème tour
    int i, ifir, isec, fir, sec, sum;
    dyn_mat mat = strmattointmat(vote);
    dyn_tab candidates = generateCandidateList(mat);
    sum = sumCandidate(candidates);
    if (isLog()) {
        fprintf(logfp, "---- Two-round system display : ----\n\n");
        fprintf(logfp, "Display of the candidates table : \n");
        printDynIntTab(candidates, logfp);
        fprintf(logfp, "Sum of all the points = %d\n", sum);
    }
    if(listValid(candidates)) {
        ifir = findBestCandidate(candidates, val1);
        *val1 = *val1 * 100 / (vote.nbRows - 1);
        fir = candidates.tab[ifir];
        if(fir <= sum/2) {
            candidates.tab[ifir] = -1;
            isec = findBestCandidate(candidates, val2);
            *val2 = *val2 * 100 / (vote.nbRows - 1);
            sec = candidates.tab[isec];
            fir = sec = 0;
            for(i=0;i<mat.nbRows;i++) {
                if(mat.tab[i][ifir] < mat.tab[i][isec]) {
                    fir++;
                } else if(mat.tab[i][ifir] > mat.tab[i][isec]) {
                    sec++;
                }
            }
            if(isLog()) {
                fprintf(logfp, "Number of points for the first candidate : %d\n", fir);
                fprintf(logfp, "Number of points for the second candidate : %d\n\n", sec);
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
