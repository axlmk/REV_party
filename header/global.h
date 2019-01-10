/// \file global.h
/// \brief Importe les bibliothèques et spécifie les variables qui seront communes à tous le programme
/// \author Axel GAUTHIER
/// \date 2019

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

typedef enum {BALLOT, MATRICE} csvType;

FILE *logfp;
char *logfpName;

#endif
