#include "../../../header/condorcet.h"

int isCondorcetWinner(list duel, int nbCandidate) {
    /// \brief Renvoie l'index du vainqueur de condorcet
    /// \param[in] duel : Liste des duels
    /// \param[in] nbCandidate : Nombre de candidats
    /// \return Renvoie l'index du gagnant s'il y en a un sinon -1
    int i, j;
    bool win;
    for(i=0;i<nbCandidate;i++) {
        win = true;
        for(j=0;j<nbEltList(duel);j++) {
            if(duel.arrList[j].dest == i) {
                win = false;
            }
        }
        if(win) {
            return i;
        }
    }
    return -1;
}
