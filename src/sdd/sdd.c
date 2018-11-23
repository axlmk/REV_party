#include "../../header/sdd.h"

int * createIntTab(int dim) {
    return malloc(sizeof(int) * dim);
}

int ** createIntMat(int nbRows,int nbCol) {
    int **res = malloc(sizeof(int*) * nbCol);
    int i;
    for(i=0;i<nbCol;i++) {
        res[i] = malloc(sizeof(int) * nbRows);
    }
    return res;
}

void printIntTab(int *tab, int dim, FILE *logfp) {
    int i;
    fprintf(logfp, "Integers's table :\n");
    fprintf(logfp, "\t(");
    for(i=0;i<dim;i++) {
        fprintf(logfp, "%d ", tab[i]);
    } fprintf(logfp, ")\n");
}

void createDynIntMat(dyn_mat *stTab,int nbRows,int nbCol) {
    stTab->nbRows = nbRows;
    stTab->nbCol = nbCol;
    int i;
    stTab->tab = malloc(sizeof(int*) * stTab->nbCol);
    for(i=0;i<stTab->nbCol;i++) {
            stTab->tab[i] = malloc(sizeof(int) * stTab->nbRows);
    }
}

void createDynIntTab(dyn_tab *stTab, int dim) {
        stTab->dim = dim;
        stTab->tab = malloc(sizeof(int) * stTab->dim);
}

void createDynCharTab(dyn_mat_str *s_tabmots) {
    s_tabmots->nbRows = 0;
    s_tabmots->nbCol = 0;
    s_tabmots->offset = 0;
    s_tabmots->tab = NULL;
}

void printDynIntTab(dyn_tab t_tab, FILE *logfp) {
    int i;
    fprintf(logfp, "Integers's table:\n\t(");
    for(i=0;i<t_tab.dim-1;i++) {
        fprintf(logfp, "%d, ", t_tab.tab[i]);
    } fprintf(logfp, "%d)\n", t_tab.tab[i]);
}

void printDynCharMat(dyn_mat_str t_tabmots, FILE *logfp) {
    int i, j;
    // add offset ?
    fprintf(logfp, "Strings's matrix :\n");
    for(i=0;i<t_tabmots.nbRows;i++) {
        fprintf(logfp, "\t(");
        for(j=0;j<t_tabmots.nbCol;j++) {
            fprintf(logfp, "%s, ", t_tabmots.tab[i][j]);
        }
        fprintf(logfp, ")\n");
    }
}

void printDynIntMat(dyn_mat t_tab, FILE *logfp) {
    int i, j;
    fprintf(logfp, "Characters's matrix :\n");
    for(i=0;i<t_tab.nbRows;i++) {
        fprintf(logfp, "\t(");
        for(j=0;j<t_tab.nbCol;j++) {
            fprintf(logfp, "%c, ", t_tab.tab[i][j]);
        }
        fprintf(logfp, ")\n");
    }
}

void printIntMat(int **duels_mat,int nbRows,int nbCol,FILE *logfp) {
    int i, j;
    fprintf(logfp, "Integers's matrix :\n");
    for(i=0;i<nbRows;i++) {
        fprintf(logfp, "\t(");
        for(j=0;j<nbCol;j++) {
            fprintf(logfp, "%d, ", duels_mat[i][j]);
        }
        fprintf(logfp, ")\n");
    }
}

void init_tab_int(int *tab, int dim, int value) {
    int i;
    for(i=0;i<dim;i++)
        tab[i] = value;
}

void init_mat_int(int **mat, int nbRows, int nbCol, int value) {
    int i, j;
    for(i=0;i<nbRows;i++) {
        for(j=0;j<nbCol;j++) {
            mat[i][j] = value;
        }
    }
}
