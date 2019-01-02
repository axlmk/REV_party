#include "../header/options.h"
#include "../header/sdd.h"
#include "../header/csv.h"
#include "../header/uninomial.h"
#include "../header/list.h"
#include "../header/graph.h"
#include "../header/condorcet.h"
#include "../header/irv.h"
#include "../header/display.h"

int main(int argc, char *argv[]) {
    csvType vote;
    char *method = NULL;
    char *csvName = NULL;
    char *logfpName = NULL;
    if(!tagParser(argc, argv, &vote, &csvName, &logfpName, &method)) {
        FILE *csvFile = fopen(csvName, "r");
        if(csvFile != NULL) {
            dyn_mat_str mat = openMatrix(csvFile, vote);
            fclose(csvFile);
            if(method != NULL) {
                char *winner = NULL;
                int pourcent = 0, tour = 0, nbCandidates = mat.nbCols - mat.offset, nbVoters = mat.nbRows - 1;
                if(!strcmp(method, "uni1")) {
                    fptp(mat, &winner, &pourcent);
                    displayWinner(winner, method, nbCandidates, nbVoters, pourcent, tour);
                } else if(!strcmp(method, "uni2")) {
                    char *challenger = NULL;
                    int pourcent2 = 0, pourcent3 = 0;
                    trs(mat, &winner, &challenger, &pourcent, &pourcent2, &pourcent3);
                    displayWinner(winner, method, nbCandidates, nbVoters, pourcent, 1);
                    displayWinner(challenger, method, nbCandidates, nbVoters, pourcent2, 1);
                    displayWinner(winner, method, nbCandidates, nbVoters, pourcent3, 2);
                } else if(!strcmp(method, "cm")) {
                    dyn_mat duel = ballottoduel(mat);
                    list duel_l = dueltolist(duel);
                    if(isCondorcetWinner(duel_l, nbCandidates)) {
                        displayWinner(winner, method, nbCandidates, nbVoters, 0, 0);
                    } else {
                        int ind = minimax(duel);
                        displayWinner(mat.tab[0][ind + mat.offset], method, nbCandidates, nbVoters, 0, 0) ;
                    }
                } else if(!strcmp(method, "cp")) {
                    dyn_mat duel = ballottoduel(mat);
                    list duel_l = dueltolist(duel);
                    if(isCondorcetWinner(duel_l, nbCandidates)) {
                        isCondorcetWinner(rankedPairs(duel), nbCandidates);
                        displayWinner(winner, method, nbCandidates, nbVoters, 0, 0);
                    } else {
                        displayWinner(winner, method, nbCandidates, nbVoters, 0, 0);
                    }
                } else if(!strcmp(method, "cs")) {
                    dyn_mat duel = ballottoduel(mat);
                    list duel_l = dueltolist(duel);
                    if(isCondorcetWinner(duel_l, nbCandidates)) {
                        displayWinner(winner, method, nbCandidates, nbVoters, 0, 0);
                    } else {
                        displayWinner(winner, method, nbCandidates, nbVoters, 0, 0);
                    }
                } else if(!strcmp(method, "va")) {
                    winner = instant_runnoff_voting(mat);
                    displayWinner(winner, method, nbCandidates, nbVoters, 0, 0);
                } else {
                    fputs("The method is invalid.\n", stderr);
                }
            } else {
                printf("plop\n");
            }
        } else {
            fputs("An error occured while opening file.\n", stderr);
        }
    } else {
        fprintf(stderr, "An error occured.\n");
        return EXIT_FAILURE;
    }

    free(logfpName);
    free(csvName);
    free(method);
    return EXIT_SUCCESS;
}
