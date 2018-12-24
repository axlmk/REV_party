#ifndef OPTIONS_H_
#define OPTIONS_H_

#define UND "\x1b[4m"
//underline for linux
#define CLA "\x1b[0m"
//classic for linux
#define PRINT_TRUE(a) ((a==TRUE)?(printf("TRUE\n")):printf("FALSE\n"))
//helpful for debugging
#include "global.h"

int defineOptions(int count, char *args[], csvType *Vote, char *csvName, char *logs, char *Method);
bool syntaxChecker(int count, char *args[]);
bool semanticChecker(int count, char *args[]);
bool cmpExt(char *s, const char *ext);


#endif
