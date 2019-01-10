#include "../../header/irv.h"

int getWinner(dyn_tab candidates, int sum) {
    /// \brief Détermine si un des candidats a gagné avec la majorité des voix
    /// \param[in] candidates : Liste des candidats avec leurs points
    /// \param[in] sum : Somme totale des voix des candidats
    /// \return L'index du candidat gagnant ou -1
    int i;
    for(i=0;i<candidates.dim;i++)
        if(candidates.tab[i] >= sum/2)
            return i;
    return -1;
}

int minCandidates(dyn_tab candidates) {
    /// \brief Trouve le candidat dans la liste avec le minimum de points
    /// \param[in] candidates : Liste des candidats
    /// \return L'index du candidat ayant le minimum de points
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
    /// \brief Enlève le candidat ayant le moins de points de la liste
    /// \param[in, out] candidates : Liste des candidats
    /// \param[in, out] ballot : Matrice de votes
    int ind = minCandidates(*candidates);
    candidates->tab[ind] = -1;
    incrementBallot(ballot, ind);
}

int sumCandidateH(dyn_tab candidates) {
    /// \brief Fait la somme des points des candidats s'ils sont toujours valides
    /// \param[in] candidates : Liste des candidats
    /// \return La somme voulue
    int i, res=0;
    for(i=0;i<candidates.dim;i++) {
        if(candidates.tab[i] != -1)
            res+=candidates.tab[i];
    }
    return res;
}

void incrementBallot(dyn_mat *ballot, int ind) {
    /// \brief Augmente le vote dans la matrice de vote pour les candidats toujours en lice
    /// \param[in, out] ballot : Matrice de votes
    /// \param[in] ind : Index par rapport auquel il faut augmenter le score
    int i, j;
    for(i=0;i<ballot->nbRows;i++) {
        for(j=0;j<ballot->nbCols;j++) {
            if(ballot->tab[i][ind] < ballot->tab[i][j]) {
                ballot->tab[i][j]--;
            }
        }
    }
}

dyn_mat strmattointmat(dyn_mat_str ballot) {
    /// \brief Transforme une matrice de vote de caractères en matrice de vote d'entiers
    /// \param[in] ballot : Matrice de votes
    /// \return Matrice de votes
    dyn_mat vote;
    createDynIntMat(&vote, ballot.nbRows-1, ballot.nbCols - ballot.offset);
    int i, j;
    for(i=0;i<vote.nbRows;i++) {
        for(j=0;j<vote.nbCols;j++) {
            vote.tab[i][j] = atoi(ballot.tab[i+1][j+ballot.offset]);
        }
    }
    return vote;
}

void initCandidates(dyn_tab *candidates, dyn_mat ballot) {
    /// \brief Crée et initialise une liste de candidats grâce à une matrice de votes
    /// \param[in, out] candidates : Liste de candidats
    /// \param[in] ballot : Matrice de votes
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
    /// \brief Renvoie l'index du candidat avec le minimum de points dans une ligne de la matric de vote
    /// \param[in, out] nbr : Ligne de la matrice de vote
    /// \param[in] n : Nombre de candidats
    /// \param[in] candidates : Liste des candidats
    /// \return L'index du candidats gagnant ou -1 s'il y a une égalité de points
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
    /// \brief Renvoie le nom du candidat ayant gagné selon la méthode vote alternatif
    /// \param[in] ballot : Matrice de votes en caractères
    /// \return Nom du candidant gagnant
    int win=0;
    dyn_mat ballotInt = strmattointmat(ballot);
    dyn_tab candidates = generateCandidateList(ballotInt);
    if(isLog()) {
        fprintf(logfp, "---- Instant-runnoff voting display : ----\n\n");
        fprintf(logfp, "Display of the ballot matrix : \n");
        printDynIntMat(ballotInt, logfp);
        fprintf(logfp, "Display of the candidate list : \n");
        printDynIntTab(candidates, logfp);
    }
    win = getWinner(candidates, sumCandidateH(candidates));
    while(win == -1) {
        rmLowerCandidate(&candidates, &ballotInt);
        initCandidates(&candidates, ballotInt);
        if(isLog()) {
            fprintf(logfp, "Display of the candidate list : \n");
            printDynIntTab(candidates, logfp);
        }
        win = getWinner(candidates, sumCandidateH(candidates));
    }
    return (ballot.tab[0][ballot.offset + win]);
}
