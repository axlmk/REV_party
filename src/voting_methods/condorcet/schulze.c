#include "../../../header/condorcet.h"

list duelToSchwartz(dyn_mat duel) { //rigoureusement la meme fonction que dueltolistranked
    int i, j;
    Elementlist e;
    list graph;
    c/*reateList(&graph);
    for(i=0;i<duel.nbRows;i++) {
        for(j=0;j<i;j++) {
            if(duel.tab[i][j] > duel.tab[j][i]) {
                e.src = i;
                e.dest = j;
                e.weight = duel.tab[i][j] - duel.tab[i][j];
            } else {
                e.src = j;
                e.dest = i;
                e.weight = duel.tab[j][i] - duel.tab[i][j];
            }
            addTailList(&graph, e);
        }
    }*/
    return graph;
}

int schulze(dyn_mat duel) {
    int i;
    list schwartz = duelToSchwartz(duel);

/*
# Input: d[i,j], the number of voters who prefer candidate i to candidate j.
# Output: p[i,j], the strength of the strongest path from candidate i to candidate j.

for i from 1 to C
   for j from 1 to C
      if (i ≠ j) then
         if (d[i,j] > d[j,i]) then
            p[i,j] := d[i,j]
         else
            p[i,j] := 0

for i from 1 to C
   for j from 1 to C
      if (i ≠ j) then
         for k from 1 to C
            if (i ≠ k and j ≠ k) then
               p[j,k] := max ( p[j,k], min ( p[j,i], p[i,k] ) )
*/
    return 0;
}
