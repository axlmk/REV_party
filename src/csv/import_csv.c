#include "../../header/csv.h"

char *ftos(FILE *f) {
    /// \brief Convertit un fichier en une chaine de caractères
    /// \param[in] f : Fichier à convertir
    /// \return La chaine de caractères
    char *str = malloc(sizeof(char) * (lenFile(f) + 1));
    char c = fgetc(f);
    int i = 0;
    while(c != EOF) {
        str[i] = c;
        c = fgetc(f);
        i++;
    }
    str[i] = '\0';
    return str;
}

int lenFile(FILE *f) {
    /// \brief Obtient le nombre de caractères d'un fichier
    /// \param[in] f : Fichier
    /// \return La longueur du fichier
    fseek(f, 0, SEEK_END);
    int len = ftell(f);
    fseek(f, 0, SEEK_SET);
    return len;
}

void countStr(char *str, int *nbRows, int *nbCols) {
    /// \brief Donne le nombre de colonnes et de lignes d'un fichier CSV transformé en chaine de caractères
    /// \param[in] str : Chaine de caractères
    /// \param[out] nbRows : Nombre de lignes
    /// \param[out] nbCols : Nombre de colonnes
    int i=0;
    *nbCols = 0;
    *nbRows = 0;
    while(str[i] != '\n') {
        if(str[i] == '\t') {
            *nbCols = *nbCols + 1;
        }
        i++;
    }
    i++;
    *nbCols = *nbCols + 1;
    *nbRows = *nbRows + 1;
    while(str[i] != '\0') {
        if(str[i] == '\n') {
            *nbRows = *nbRows + 1;
        }
        i++;
    }
}

dyn_mat_str ftomat(FILE *f, csvType vote) {
    /// \brief Convertit un fichier CSV en une matrice de chaines de caractères
    /// \param[in] f : Fichier
    /// \param[in] vote : Type de fichier CSV
    /// \return Matrice de chaines de caractères
    char *str = ftos(f);
    char *token = NULL;
    int nbRows, nbCols, offset, j=0, i=-1;
    dyn_mat_str matVote;
    countStr(str, &nbRows, &nbCols);
    if(vote == BALLOT) {
       offset=3;
    } else {
       offset=1;
    }
    initDynCharMat(&matVote, nbRows, nbCols, offset);

    token = strtok(str, "\n\t");
    while(token != NULL) {
       if((j % matVote.nbCols) == 0) {
           j = 0;
           i++;
       }
       matVote.tab[i][j] = malloc(sizeof(char) * strlen(token) + 1);
       strcpy(matVote.tab[i][j], token);
       token = strtok(NULL, "\n\t");
       j++;
    }
    free(token);
    free(str);
return matVote;
}
