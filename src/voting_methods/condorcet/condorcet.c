#include "../../../header/condorcet.h"

int isCondorcetWinner(list duel, int nbCandidate) {
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
