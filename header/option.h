#ifndef OPTION_H_
#define OPTION_H_
//#define PASS
#define UND "\x1b[4m"
//underline
#define CLA "\x1b[0m"
//classic
#define PRINT_TRUE(a) ((a==TRUE)?(printf("TRUE\n")):printf("FALSE\n"))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {BALLOT, MATRICE} csvType;
typedef enum {TRUE = 1, FALSE = 0} bool;

int defineOption(int count, char *args[], csvType *Vote, char *method);
#endif
