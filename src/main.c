#include "../header/options.h"
#include "../header/sdd.h"
#include "../header/csv.h"

int main(int argc, char *argv[]) {
    csvType vote;
    char *method = malloc(sizeof(char));
    char *csvName = malloc(sizeof(char));
    char *logfpName = NULL;
    if(!defineOptions(argc, argv, &vote, csvName, logfpName, method)) {

        /*if(logfpName!=NULL) {
            if(!strcmp(logfpName, "stdout")) {
                FILE *logfp = stdout;
            } else {
                FILE *logfp = fopen(logfpName, "w");
            }
        }*/
        FILE *csvFile = fopen(csvName, "r");
        printDynCharMat(openMatrix(csvFile, vote), stdout);
        fclose(csvFile);
    } else {
        printf("An error occured.\n");
        return EXIT_FAILURE;
    }

    //free(logfpName);
    free(csvName);
    free(method);
    return EXIT_SUCCESS;
}
