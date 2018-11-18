#include "../../header/option.h"

bool checkSyntax(int count, char *args[]) {
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

int defineOption(int count, char *args[], csvType *Vote, char *method) {
    if(count < 2) {
        fprintf(stderr, "Usage : %s -i " UND "file.csv" CLA " | -d " UND "file.csv" CLA " [-l [" UND "file.txt" CLA "]] [-m " UND "method" CLA "]\n", args[0]);
    } else {
        PRINT_TRUE(checkSyntax(count, args));
    }
    return EXIT_SUCCESS;
}
