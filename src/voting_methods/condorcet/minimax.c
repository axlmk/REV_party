#include "../../../header/condorcet.h"

int minimax(dyn_mat duel) {
    int i=0, j=0, max = -1, index = 0;
    for(i=0;i<duel.nbRows;i++) {
        int min = duel.tab[i][duel.nbCols - i - 1]+1;
        for(j=0;j<duel.nbCols;j++) {
            if(i != j) {
                if(duel.tab[i][j] < min) {
                    min = duel.tab[i][j];
                }
            }
        }
        if(min > max) {
            max = min;
            index = i;
        }
    }
    return index;
}