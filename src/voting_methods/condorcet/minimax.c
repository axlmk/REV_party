#include "../../../header/condorcet.h"

int minimax(dyn_mat duel) {
    int i, j, max = 0, index;
    for(i=0;i<duel.nbRows;i++) {
        int min = 10000;
        for(j=1;j<duel.nbCols;j++) {
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
