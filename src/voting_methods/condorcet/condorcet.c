#include "../../../header/condorcet.h"

int isCondorcetWinner(list duel, int nbCandidate) {
    //dumpList(duel, stdout);
    bubbleSortList(&duel);
    int i, count = 1;
    for(i=0;i<nbEltList(duel);i++) {
        if(count == nbCandidate - 1) {
            return duel.arrList[i-1].src;
        }
        if(duel.arrList[i].src != duel.arrList[i-1].src) {
            count = 0;
        }
        count++;
    }
    return -1;
}
