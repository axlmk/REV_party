#include "../../header/sdd.h"

int * createIntTab(int dim) {
    return malloc(sizeof(int) * dim);
}

int ** createIntMat(int nbRows,int nbCols) {
    int **res = malloc(sizeof(int*) * nbCols);
    int i;
    for(i=0;i<nbCols;i++) {
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

void createDynIntMat(dyn_mat *stTab,int nbRows,int nbCols) {
    stTab->nbRows = nbRows;
    stTab->nbCols = nbCols;
    int i;
    stTab->tab = malloc(sizeof(int*) * stTab->nbCols);
    for(i=0;i<stTab->nbCols;i++) {
            stTab->tab[i] = malloc(sizeof(int) * stTab->nbRows);
    }
}

void createDynIntTab(dyn_tab *stTab, int dim) {
        stTab->dim = dim;
        stTab->tab = malloc(sizeof(int) * stTab->dim);
}

void createDynCharMat(dyn_mat_str *s_tabmots) {
    s_tabmots->nbRows = 0;
    s_tabmots->nbCols = 0;
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
    fprintf(logfp, "Strings's matrix :\n");
    for(i=0;i<t_tabmots.nbRows;i++) {
        fprintf(logfp, "\t(");
        for(j=0;j<t_tabmots.nbCols-1;j++) {
            fprintf(logfp, "%s, ", t_tabmots.tab[i][j]);
        }
        fprintf(logfp, "%s)\n", t_tabmots.tab[i][j]);
    }
}

void printDynIntMat(dyn_mat t_tab, FILE *logfp) {
    int i, j;
    fprintf(logfp, "Characters's matrix :\n");
    for(i=0;i<t_tab.nbRows;i++) {
        fprintf(logfp, "\t(");
        for(j=0;j<t_tab.nbCols;j++) {
            fprintf(logfp, "%c, ", t_tab.tab[i][j]);
        }
        fprintf(logfp, ")\n");
    }
}

void printIntMat(int **duels_mat,int nbRows,int nbCols,FILE *logfp) {
    int i, j;
    fprintf(logfp, "Integers's matrix :\n");
    for(i=0;i<nbRows;i++) {
        fprintf(logfp, "\t(");
        for(j=0;j<nbCols;j++) {
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

void init_mat_int(int **mat, int nbRows, int nbCols, int value) {
    int i, j;
    for(i=0;i<nbRows;i++) {
        for(j=0;j<nbCols;j++) {
            mat[i][j] = value;
        }
    }
}

void initDynCharMat(dyn_mat_str *s_tabmots, int nbRows, int nbCols, int offset) {
    s_tabmots->nbRows = nbRows;
    s_tabmots->nbCols = nbCols;
    s_tabmots->offset = offset;
    int i;
    s_tabmots->tab = malloc(sizeof(char**) * s_tabmots->nbRows);
    for(i=0;i<s_tabmots->nbRows;i++) {
        int j;
        s_tabmots->tab[i] = malloc(sizeof(char*) * s_tabmots->nbCols);
        for(j=0;j<s_tabmots->nbCols;j++) {
            s_tabmots->tab[i][j] = NULL;
        }
    }
}
