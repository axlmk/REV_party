#ifndef OPTIONS_H_
#define OPTIONS_H_

#include "global.h"

//underline for linux
#define UND "\x1b[4m"
//classic for linux
#define CLA "\x1b[0m"

int tagParser(int count, char *args[], csvType *Vote, char **csvName, char **logs, char **Method);
bool syntaxChecker(int count, char *args[]);
bool semanticChecker(int count, char *args[]);
bool cmpExt(char *s, const char *ext);

#endif
