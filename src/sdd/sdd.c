#include "../../header/sdd.h"

int * createIntTab(int dim) {
    /// \brief Alloue la mémoire nécessaire pour un tableau d'entier dynamique à une dimension
    /// \param[in] dim : Taille du tableau
    /// \return Le tableau alloué
    return malloc(sizeof(int) * dim);
}

int ** createIntMat(int nbRows,int nbCols) {
    /// \brief Alloue la mémoire nécessaire pour une matrice d'entier dynamique
    /// \param[in] nbRows : Nombre de lignes
    /// \param[in] nbCols : Nombre de colonnes
    /// \return La matrice allouée
    int **res = malloc(sizeof(int*) * nbCols);
    int i;
    for(i=0;i<nbCols;i++) {
        res[i] = malloc(sizeof(int) * nbRows);
    }
    return res;
}

void printIntTab(int *tab, int dim, FILE *logfp) {
    /// \brief Affiche un tableau d'entier dynamique sur un fichier
    /// \param[in] tab : Le tableau à afficher
    /// \param[in] dim : Taille du tableau
    /// \param[in, out] logfp : Fichier où afficher le tableau
    int i;
    fprintf(logfp, "\t(");
    for(i=0;i<dim;i++) {
        fprintf(logfp, "%d ", tab[i]);
    } fprintf(logfp, ")\n");
}

void createDynIntMat(dyn_mat *stTab,int nbRows,int nbCols) {
    /// \brief Créer une structure dyn_mat
    /// \param[out] stTab : Matrice à créer
    /// \param[in] nbRows : Nombre de lignes
    /// \param[in] nbCols : Nombre de colonnes
    stTab->nbRows = nbRows;
    stTab->nbCols = nbCols;
    int i, j;
    stTab->tab = malloc(sizeof(int*) * nbRows);
    for(i=0;i<nbRows;i++) {
            stTab->tab[i] = malloc(sizeof(int) * nbCols);
            for(j=0;j<stTab->nbCols;j++)
                stTab->tab[i][j] = 0;
    }
}

void createDynIntTab(dyn_tab *stTab, int dim) {
    /// \brief Créer une structure dyn_tab
    /// \param[out] stTab : Tableau à créer
    /// \param[in] dim : Nombre de cases
        stTab->dim = dim;
        stTab->tab = malloc(sizeof(int) * stTab->dim);
}

void createDynCharMat(dyn_mat_str *s_tabmots) {
    /// \brief Créer une structure dyn_mat_str
    /// \param[out] stTab : Matrice à créer
    s_tabmots->nbRows = 0;
    s_tabmots->nbCols = 0;
    s_tabmots->offset = 0;
    s_tabmots->tab = NULL;
}

void printDynIntTab(dyn_tab t_tab, FILE *logfp) {
    /// \brief Affiche une structure dyn_tab sur un fichier
    /// \param[in] t_tab : La structure à afficher
    /// \param[in, out] logfp : Fichier où afficher le tableau
    int i;
    fprintf(logfp, "\t(");
    for(i=0;i<t_tab.dim-1;i++) {
        fprintf(logfp, "%d, ", t_tab.tab[i]);
    } fprintf(logfp, "%d)\n\n", t_tab.tab[i]);
}

void printDynCharMat(dyn_mat_str t_tabmots, FILE *logfp) {
    /// \brief Affiche une structure dyn_mat_str sur un fichier
    /// \param[in] t_tabmots : La structure à afficher
    /// \param[in, out] logfp : Fichier où afficher le tableau
    int i, j;
    for(i=0;i<t_tabmots.nbRows;i++) {
        fprintf(logfp, "\t(");
        for(j=0;j<t_tabmots.nbCols-1;j++) {
            fprintf(logfp, "%s, ", t_tabmots.tab[i][j]);
        }
        fprintf(logfp, "%s)\n\n", t_tabmots.tab[i][j]);
    }
}

void printDynIntMat(dyn_mat t_tab, FILE *logfp) {
    /// \brief Affiche une structure dyn_mat sur un fichier
    /// \param[in] t_tab : La structure à afficher
    /// \param[in, out] logfp : Fichier où afficher le tableau
    int i, j;
    for(i=0;i<t_tab.nbRows;i++) {
        fprintf(logfp, "\t(");
        for(j=0;j<t_tab.nbCols;j++) {
            fprintf(logfp, "%d, ", t_tab.tab[i][j]);
        }
        fprintf(logfp, ")\n\n");
    }
}

void printIntMat(int **duels_mat,int nbRows,int nbCols,FILE *logfp) {
    /// \brief Affiche une matrice dynamique d'entiers sur un fichier
    /// \param[in] duels_mat : La matrice à afficher
    /// \param[in] nbRows : Nombre de lignes
    /// \param[in] nbCols : Nombre de colonnes
    /// \param[in, out] logfp : Fichier où afficher le tableau
    int i, j;
    for(i=0;i<nbRows;i++) {
        fprintf(logfp, "\t(");
        for(j=0;j<nbCols;j++) {
            fprintf(logfp, "%d, ", duels_mat[i][j]);
        }
        fprintf(logfp, ")\n\n");
    }
}

void init_tab_int(int *tab, int dim, int value) {
    /// \brief Initialise un tableau d'entiers dynamique avec une valeur
    /// \param[out] tab : Tableau à initialiser
    /// \param[in] dim : Dimension du tableau
    /// \param[in] value : Valeur avec laquelle initialiser
    int i;
    for(i=0;i<dim;i++)
        tab[i] = value;
}

void init_mat_int(int **mat, int nbRows, int nbCols, int value) {
    /// \brief Initialise une matrice d'entiers dynamique avec une valeur
    /// \param[out] mat : Matrice à initialiser
    /// \param[in] nbRows : Nombre de lignes du tableau
    /// \param[in] nbCols : Nombre de colonnes du tableau
    /// \param[in] value : Valeur avec laquelle initialiser
    int i, j;
    for(i=0;i<nbRows;i++) {
        for(j=0;j<nbCols;j++) {
            mat[i][j] = value;
        }
    }
}

void initDynCharMat(dyn_mat_str *s_tabmots, int nbRows, int nbCols, int offset) {
    /// \brief Crée et initialise une matrice de chaines de caractères dynamique
    /// \param[out] s_tabmots : Matrice à initialiser
    /// \param[in] nbRows : Nombre de lignes du tableau
    /// \param[in] nbCols : Nombre de colonnes du tableau
    /// \param[in] offset : Nombre de lignes à ignorer
    s_tabmots->nbRows = nbRows;
    s_tabmots->nbCols = nbCols;
    s_tabmots->offset = offset;
    int i;
    s_tabmots->tab = malloc(sizeof(char**) * s_tabmots->nbRows);
    for(i=0;i<s_tabmots->nbRows;i++) {
        int j;
        s_tabmots->tab[i] = malloc(sizeof(char*) * (s_tabmots->nbCols));
        for(j=0;j<s_tabmots->nbCols;j++) {
            s_tabmots->tab[i][j] = NULL;
        }
    }
}
