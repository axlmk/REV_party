#include "../../header/options.h"

bool syntaxChecker(int count, char *args[]) {
    int i;
    bool d = false, ie = false, m = false, l = false;
    for(i=1;i<count;i++) {
        if(!strcmp(args[i], "-d")) {
            if(d != true) {
                if(ie == false) {
                    d = true;
                    if(i+1 == count) {
                        return false;
                    } else {
                        if(args[i+1][0] == '-')
                            return false;
                    }
                } else
                    return false;
            } else {
                return false;
            }
        } else if(!strcmp(args[i], "-i")) {
            if(ie == false) {
                if(d == false) {
                    ie = true;
                    if(i+1 < count) {
                        if(args[i+1][0] == '-')
                            return false;
                    } else
                        return false;
                } else
                    return false;
            } else {
                return false;
            }
        } else if(!strcmp(args[i], "-m")) {
            if(m == false) {
                m = true;
                if(i+1 < count) {
                    if(args[i+1][0] == '-')
                        return false;
                } else
                    return false;
            } else {
                return false;
            }
        } else if(!strcmp(args[i], "-l")) {
            if(l == false) {
                l = true;
            } else {
                return false;
            }
        } else if(args[i][0] == '-') {
            return false;
        } else {
            if(args[i-1][0] != '-') {
                return false;
            }
        }
    }
    return d == true || ie == true;
}

bool semanticChecker(int count, char *args[]) {
    int i;
    for(i=1;i<count;i++) {
        if(!strcmp(args[i], "-d") || !strcmp(args[i], "-i")) {
            if(access(args[i+1], F_OK) == -1) {
                fprintf(stderr, "The CSV file doesn't exist.\n");
                return false;
            }
        } else if(!strcmp(args[i], "-m")) {
            if(strcmp(args[i+1], "uni1") && strcmp(args[i+1], "uni2") && strcmp(args[i+1], "cm") && strcmp(args[i+1], "cp") && strcmp(args[i+1], "cs") &&strcmp(args[i+1], "va")) {
                fprintf(stderr, "The voting method specified doesn't exist.\n");
                return false;
            }
        }
    }
    return true;
}

int defineOptions(int count, char *args[], csvType *Vote, char *CsvName, char *Logs, char *Method) {
    if(count < 2) {
        fprintf(stderr, "Usage : %s -i " UND "file.csv" CLA " | -d " UND "file.csv" CLA " [-l [" UND "file.txt" CLA "]] [-m " UND "method" CLA "]\n", args[0]);
        return EXIT_FAILURE;
    } else {
        if(syntaxChecker(count, args)) {
            if(semanticChecker(count, args)) {
                int i;
                for(i=1;i<count;i++) {
                    if(!strcmp(args[i], "-i")) {
                        *Vote = BALLOT;
                        CsvName = realloc(CsvName, sizeof(char) * (strlen(args[i+1])+1));
                        strcpy(CsvName, args[i+1]);
                        i++;
                    } else if(!strcmp(args[i], "-d")) {
                        *Vote = MATRICE;
                        CsvName = realloc(CsvName, sizeof(char) * (strlen(args[i+1])+1));
                        strcpy(CsvName, args[i+1]);
                    }

                    if(!strcmp(args[i], "-m")) {
                        Method = realloc(Method, sizeof(char) * (strlen(args[i+1])+1));
                        strcpy(Method, args[i+1]);
                    }

                    if(!strcmp(args[i], "-l")) {
                        if(args[i+1][0] != '-') {
                            Logs = realloc(Logs, sizeof(char) * (strlen(args[i+1])+1));
                            strcpy(Logs, args[i+1]);
                        } else {
                            Logs = realloc(Logs, sizeof(char) * 7);
                            strcpy(Logs, "stdout");
                        }
                    }
                }
            } else {
                return EXIT_FAILURE;
            }
        } else {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
