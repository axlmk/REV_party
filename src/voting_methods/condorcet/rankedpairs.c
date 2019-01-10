#include "../../../header/condorcet.h"

list dueltolistranked(dyn_mat duel) {
    /// \brief Transforme une matrice de duel en liste adaptée pour la méthode rangement par pairs
    /// \param[in] duel : Matrice de duels
    /// \return La liste adaptée
    int i, j;
    Elementlist e;
    list graph;
    createList(&graph);
    for(i=0;i<duel.nbRows;i++) {
        for(j=0;j<i;j++) {
            if(duel.tab[i][j] > duel.tab[j][i]) {
                e.src = i;
                e.dest = j;
                e.weight = duel.tab[i][j] - duel.tab[j][i];
            } else {
                e.src = j;
                e.dest = i;
                e.weight = duel.tab[j][i] - duel.tab[i][j];
            }
            addTailList(&graph, e);
        }
    }
    return graph;
}

list rankedPairs(dyn_mat duel) {
    /// \brief Renvoie la liste des candidats sans circuits
    /// \param[in] duel : Matrice de duels
    /// \return Liste des candidats
    list ranked = dueltolistranked(duel);
    list temp;
    int i;
    createList(&temp);
    bubbleSortListWDown(&ranked);
    for(i=0;i<nbEltList(ranked);i++) {
        addTailList(&temp, ranked.arrList[i]);
        if(circuits(temp, duel.nbCols)) {
            delTailList(&temp);
        }
    }
    return temp;
}
