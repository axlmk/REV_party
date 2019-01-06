#ifndef SDD_H_
#define SDD_H_

#include "global.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

//dynamic table of integers
typedef struct dyn_tab{
  int *tab;
  int dim;
} dyn_tab;

//dynamic matrix of integers
typedef struct dyn_mat{
  int **tab;
  int nbRows;
  int nbCols;
} dyn_mat;

//dynamic matrix of strings
typedef struct dyn_mat_str{
  char *** tab;
  int nbRows;
  int nbCols;
  int offset; // donne le nombre de colonnes avant celles des candidats
} dyn_mat_str;

//weighted arc
typedef struct w_arc{
  int src;
  int dest;
  int weight;
} w_arc;

int * createIntTab(int dim);
int ** createIntMat(int nbRows,int nbCols);
void printIntTab(int *tab,int dim, FILE *logfp);
void printIntMat(int **duels_mat,int nbRows,int nbCols,FILE *logfp);

void createDynIntTab(dyn_tab *stTab,int dim);
void createDynIntMat(dyn_mat *stTab,int nbRows,int nbCols);
void createDynCharMab(dyn_mat_str * s_tabmots);
void printDynIntTab(dyn_tab t_tab, FILE *logfp);
void printDynIntMat(dyn_mat t_tab, FILE *logfp);
void printDynCharMat(dyn_mat_str t_tabmots, FILE *logfp);

void init_tab_int(int *tab, int dim, int value);
void init_mat_int(int **mat, int nbRows, int nbCols, int value);

void initDynCharMat(dyn_mat_str *s_tabmots, int nbRows, int nbCols, int offset);

#endif
