#include "../../header/options.h"

bool syntaxChecker(int count, char *args[]) {
    int i;
    bool d = FALSE, ie = FALSE, m = FALSE, l = FALSE;
    for(i=1;i<count;i++) {
        if(!strcmp(args[i], "-d")) {
            if(d != TRUE) {
                if(ie == FALSE) {
                    d = TRUE;
                    if(i+1 == count) {
                        return FALSE;
                    } else {
                        if(args[i+1][0] == '-')
                            return FALSE;
                    }
                } else
                    return FALSE;
            } else {
                return FALSE;
            }
        } else if(!strcmp(args[i], "-i")) {
            if(ie == FALSE) {
                if(d == FALSE) {
                    ie = TRUE;
                    if(i+1 < count) {
                        if(args[i+1][0] == '-')
                            return FALSE;
                    } else
                        return FALSE;
                } else
                    return FALSE;
            } else {
                return FALSE;
            }
        } else if(!strcmp(args[i], "-m")) {
            if(m == FALSE) {
                m = TRUE;
                if(i+1 < count) {
                    if(args[i+1][0] == '-')
                        return FALSE;
                } else
                    return FALSE;
            } else {
                return FALSE;
            }
        } else if(!strcmp(args[i], "-l")) {
            if(l == FALSE) {
                l = TRUE;
            } else {
                return FALSE;
            }
        } else if(args[i][0] == '-') {
            return FALSE;
        } else {
            if(args[i-1][0] != '-') {
                return FALSE;
            }
        }
    }
    return d == TRUE || ie == TRUE;
}

bool semanticChecker(int count, char *args[]) {
    int i;
    for(i=1;i<count;i++) {
        if(!strcmp(args[i], "-d") || !strcmp(args[i], "-i")) {
            if(access(args[i+1], F_OK) == -1) {
                fprintf(stderr, "The CSV file doesn't exist.\n");
                return FALSE;
            }
        } else if(!strcmp(args[i], "-m")) {
            if(strcmp(args[i+1], "uni1") && strcmp(args[i+1], "uni2") && strcmp(args[i+1], "cm") && strcmp(args[i+1], "cp") && strcmp(args[i+1], "cs") &&strcmp(args[i+1], "va")) {
                fprintf(stderr, "The voting method specified doesn't exist.\n");
                return FALSE;
            }
        }
    }
    return TRUE;
}

int defineOptions(int count, char *args[], csvType *Vote, char *CsvName, char *Logs, char *Method) {
    if(count < 2) {
        fprintf(stderr, "Usage : %s -i " UND "file.csv" CLA " | -d " UND "file.csv" CLA " [-l [" UND "file.txt" CLA "]] [-m " UND "method" CLA "]\n", args[0]);
    } else {
        if(syntaxChecker(count, args)==TRUE) {
            if(semanticChecker(count, args)) {
                int i;
                for(i=1;i<count;i++) {
                    if(!strcmp(args[i], "-i")) {
                        *Vote = BALLOT;
                        realloc(CsvName, sizeof(char) * (strlen(args[i+1])+1));
                        strcpy(CsvName, args[i+1]);
                        i++;
                    } else if(!strcmp(args[i], "-d")) {
                        *Vote = MATRICE;
                        realloc(CsvName, sizeof(char) * (strlen(args[i+1])+1));
                        strcpy(CsvName, args[i+1]);
                    } else if(!strcmp(args[i], "-m")) {
                        realloc(Method, sizeof(char) * (strlen(args[i+1])+1));
                        strcpy(Method, args[i+1]);
                    } else if(!strcmp(args[i], "-l")) {
                        if(args[i+1][0] != '-') {
                            realloc(Logs, sizeof(char) * (strlen(args[i+1])+1));
                            strcpy(Logs, args[i+1]);
                        } else {
                            realloc(Logs, sizeof(char) * 7);
                            strcpy(Logs, "stdout");
                        }
                    }
                }
            } else {
                return EXIT_FAILURE;
            }
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
