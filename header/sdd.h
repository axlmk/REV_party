/// \file sdd.h
/// \brief Définie toutes les structures de données ainsi que les fonctions qui y sont liées
/// \author Axel GAUTHIER
/// \date 2019


#ifndef SDD_H_
#define SDD_H_

#include "global.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct dyn_tab{
    /// \struct dyn_tab
    /// \brief Tableau dynamique d'entiers à une dimension
    /// \var dyn_tab::tab
    ///Tableau dynamique d'int
    /// \var dyn_tab::dim
    ///Nombre de cases du tableau
    int *tab;
    int dim;
} dyn_tab;

typedef struct dyn_mat{
    /// \struct dyn_mat
    /// \brief Matrice dynamique d'entiers
    /// \var dyn_mat::tab
    ///Tableau dynamique d'int à deux dimensons
    /// \var dyn_mat::nbRows
    ///Nombre de lignes de la matrice
    /// \var dyn_mat::nbCols
    ///Nombre de colonnes de la matrice
  int **tab;
  int nbRows;
  int nbCols;
} dyn_mat;

typedef struct dyn_mat_str{
    /// \struct dyn_mat_str
    /// \brief Matrice dynamique de chaines de caractères
    /// \var dyn_mat_str::tab
    ///Tableau dynamique de char à trois dimensions
    /// \var dyn_mat_str::nbRows
    ///Nombre de lignes de la matrice
    /// \var dyn_mat_str::nbCols
    ///Nombre de colonnes de la matrice
    /// \var dyn_mat_str::offset
    ///Nombre de colonnes inutiles au calcul
  char *** tab;
  int nbRows;
  int nbCols;
  int offset;
} dyn_mat_str;

typedef struct w_arc{
    /// \struct w_arc
    /// \brief Arc orienté ayant un poid
    /// \var w_arc::src
    ///Entier correspondant à la source
    /// \var w_arc::dest
    ///Entier correspondant à la destination
    /// \var w_arc::weight
    ///Entier correspondant au poid de l'arc
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
void createDynCharMat(dyn_mat_str * s_tabmots);
void printDynIntTab(dyn_tab t_tab, FILE *logfp);
void printDynIntMat(dyn_mat t_tab, FILE *logfp);
void printDynCharMat(dyn_mat_str t_tabmots, FILE *logfp);

void init_tab_int(int *tab, int dim, int value);
void init_mat_int(int **mat, int nbRows, int nbCols, int value);

void initDynCharMat(dyn_mat_str *s_tabmots, int nbRows, int nbCols, int offset);

#endif
