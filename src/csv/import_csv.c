#include "../../header/csv.h"

char *ftos(FILE *f) {
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
    fseek(f, 0, SEEK_END);
    int len = ftell(f);
    fseek(f, 0, SEEK_SET);
    return len;
}

void countStr(char *str, int *nbRows, int *nbCols) {
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

dyn_mat_str openMatrix(FILE *f, csvType vote) {
   char *str = ftos(f);
   char *token = NULL;
   int nbRows, nbCols, offset, j=0, i=0, k=0;
   dyn_mat_str matVote;

   countStr(str, &nbRows, &nbCols);
   if(vote == BALLOT) {
       offset=2;
   } else {
       offset=0;
   }
   initDynCharMat(&matVote, nbRows, nbCols, offset);

   token = strtok(str, "\n\t");
   while(token != NULL) {
       if(j%matVote.nbCols == 0 && j != 0) {
           j = 0;
           k = 0;
           i++;
       }
       if(j >= offset) {
           matVote.tab[i][k] = malloc(sizeof(char) * strlen(token) + 1);
           strcpy(matVote.tab[i][k], token);
           k++;
       }
       token = strtok(NULL, "\n\t");
       j++;
    }
    free(token);
    free(str);
    return matVote;
}
