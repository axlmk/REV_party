#include "../header/options.h"
#include "../header/sdd.h"
#include "../header/csv.h"
#include "../header/uninomial.h"
#include "../header/list.h"
#include "../header/graph.h"

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
        dyn_mat_str lol = openMatrix(csvFile, vote);
        //printDynCharMat(lol, stdout);
        char *winner, *challenger="";
        dyn_mat bidule = ballottoduel(lol);

        dumpList(dueltolist(bidule), stdout);
        /*if(!trs(lol, &winner, &challenger)) {
            printf("The winner is : %s, the second is : %s\n", winner, challenger);
        } else {
            printf("wouaw\n");
        }*/
        fclose(csvFile);
    } else {
        fprintf(stderr, "An error occured.\n");
        return EXIT_FAILURE;
    }

    //free(logfpName);
    free(csvName);
    free(method);
    return EXIT_SUCCESS;
}
