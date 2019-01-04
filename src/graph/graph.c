#include "../../header/graph.h"

list dueltolist(dyn_mat duel) {
    int i, j;
    Elementlist e;
    list graph;
    createList(&graph);
    for(i=0;i<duel.nbRows;i++) {
        for(j=0;j<i;j++) {
            if(duel.tab[i][j] > duel.tab[j][i]) {
                e.src = i;
                e.dest = j;
                e.weight = duel.tab[i][j];
            } else {
                e.src = j;
                e.dest = i;
                e.weight = duel.tab[j][i];
            }
            addTailList(&graph, e);
        }
    }
    return graph;
}

int generateFile(list duel) {
    FILE *f = fopen("src/python/pollTests.py", "r");
    if(f == NULL) {
        fputs("Error opening the input file.\n", stderr);
        return EXIT_FAILURE;
    } else {
        char *str = ftos(f);
        fclose(f);
        FILE *f2 = fopen("src/python/graph.py", "w");
        if(f2 == NULL) {
            fputs("Error opening the output file.\n", stderr);
            return EXIT_FAILURE;
        } else {
            int i = 0;
            while(str[i] != '#') {
                fputc(str[i], f2);
                i++;
            }
            while(str[i] != '\n')
                i++;
            dumpListGraph(duel, f2);
            while(str[i] != '\0') {
                fputc(str[i], f2);
                i++;
            }
            fclose(f2);
            return EXIT_SUCCESS;
        }
    }
}

void dumpListGraph(list p, FILE *fp) {
    int i;
    if(emptyList(p)) {
        fprintf(stderr, "There is nothing to display because the list is empty.\n");
    } else {
        for(i=0;i<p.nbElt;i++) {
            if(p.head + i >= DIMMAX) {
                fprintf(fp, "G.add_edges_from([(%d, %d)], weight=%d)\n", p.arrList[p.head + i - DIMMAX].src, p.arrList[p.head + i - DIMMAX].dest, p.arrList[p.head + i - DIMMAX].weight);
            } else {
                fprintf(fp, "G.add_edges_from([(%d, %d)], weight=%d)\n", p.arrList[p.head + i].src, p.arrList[p.head + i].dest, p.arrList[p.head + i].weight);
            }
        }
    }
}
