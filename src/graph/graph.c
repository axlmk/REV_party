#include "../../header/graph.h"

int generateFile(list duel) {
    FILE *f = fopen("src/python/pollTests.py", "r");
    if(f == NULL) {
        fputs("Error opening the input file.\n", stderr);
        return EXIT_FAILURE;
    } else {
        char *str = ftos(f);
        fclose(f);
        FILE *f2 = fopen("src/python/graph.py", "w");
        if(f2 == NULL) {
            fputs("Error opening the output file.\n", stderr);
            return EXIT_FAILURE;
        } else {
            int i = 0;
            while(str[i] != '#') {
                fputc(str[i], f2);
                i++;
            }
            while(str[i] != '\n')
                i++;
            dumpListGraph(duel, f2);
            while(str[i] != '\0') {
                fputc(str[i], f2);
                i++;
            }
            fclose(f2);
            return EXIT_SUCCESS;
        }
    }
}
