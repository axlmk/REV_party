#include "../header/utils.h"

int strtoi(char *s) {
    char *c;
    return strtol(s, &c, 10);
}
