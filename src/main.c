#include "../header/options.h"
#include "../header/sdd.h"
#include "../header/csv.h"
#include "../header/uninomial.h"
#include "../header/list.h"
#include "../header/graph.h"
#include "../header/condorcet.h"
#include "../header/irv.h"

int main(int argc, char *argv[]) {
    csvType vote;
    char *method = malloc(sizeof(char));
    char *csvName = malloc(sizeof(char));
    char *logfpName = NULL;
    if(!defineOptions(argc, argv, &vote, csvName, logfpName, method)) {
        FILE *csvFile = fopen(csvName, "r");
        dyn_mat_str lol = openMatrix(csvFile, vote);
        //printDynCharMat(lol, stdout);
        printf("winner %s\n", instant_runnoff_voting(lol));
        /*char *winner, *challenger="";
        dyn_mat bidule = ballottoduel(lol);
        //printf("|%d|\n", isCondorcetWinner(dueltolist(bidule), bidule.nbCols));


        //printDynIntMat(bidule, stdout);
        isCondorcetWinner(rankedpairs(bidule), bidule.nbCols);*/
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
