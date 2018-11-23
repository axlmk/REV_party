#include "../header/options.h"

int main(int argc, char *argv[]) {
    csvType vote;
    char *method = malloc(sizeof(char));
    char *csvName = malloc(sizeof(char));
    char *logfpName = NULL;
    defineOptions(argc, argv, &vote, csvName, logfpName, method);
    /*if(logfpName!=NULL) {
        if(!strcmp(logfpName, "stdout")) {
            FILE *logfp = stdout;
        } else {
            FILE *logfp = fopen(logfpName, "w");
        }
    }

    free(logfp);*/
    free(csvName);
    free(method);
    return EXIT_SUCCESS;
}
