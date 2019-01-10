#include "../header/options.h"
#include "../header/sdd.h"
#include "../header/csv.h"
#include "../header/uninominal.h"
#include "../header/list.h"
#include "../header/graph.h"
#include "../header/condorcet.h"
#include "../header/irv.h"
#include "../header/display.h"
#include "../header/utils.h"

void getFile(char *name);

void getFile(char *name) {
    if(name != NULL) {
        if(strcmp(name, "stdout")) {
            logfp = fopen(name, "w");
            if(logfp == NULL) {
                perror("The name of the log file is invalid. So the log file will not be used.\n");
                name = NULL;
            }
        } else {
            logfp = stdout;
        }
    }
}

int main(int argc, char *argv[]) {
    csvType vote;
    char *method = NULL;
    char *csvName = NULL;
    if(!tagParser(argc, argv, &vote, &csvName, &logfpName, &method)) {
        FILE *csvFile = fopen(csvName, "r");
        getFile(logfpName);
        if(csvFile != NULL) {
            dyn_mat_str mat = ftomat(csvFile, vote);
            printDynCharMat(mat, stdout);
            fclose(csvFile);
            char *winner = NULL;
            int pourcent = 0, tour = 0, nbCandidates = mat.nbCols - mat.offset, nbVoters = mat.nbRows - 1;
            if((method == NULL || !strcmp(method, "uni1")) && vote == BALLOT) {
                fptp(mat, &winner, &pourcent);
                displayWinner(winner, "uni1", nbCandidates, nbVoters, pourcent, tour);
            } if((method == NULL || !strcmp(method, "uni2")) && vote == BALLOT) {
                char *challenger = NULL;
                int pourcent2 = 0, pourcent3 = 0;
                trs(mat, &winner, &challenger, &pourcent, &pourcent2, &pourcent3);
                displayWinner(winner, "uni2", nbCandidates, nbVoters, pourcent, 1);
                if(winner != NULL) {
                    displayWinner(challenger, "uni2", nbCandidates, nbVoters, pourcent2, 1);
                    displayWinner(winner, "uni2", nbCandidates, nbVoters, pourcent3, 2);
                }
            } if(method == NULL || !strcmp(method, "cm")) {
                dyn_mat duel = ballottoduel(mat, vote);
                list duel_l = dueltolist(duel);
                int ind = isCondorcetWinner(duel_l, nbCandidates);
                if(isLog()) {
                    fprintf(logfp, "---- Condorcet minimax dislpay : ----\n\n");
                    fprintf(logfp, "Duel matrix :\n");
                    printDynIntMat(duel, logfp);
                    fprintf(logfp, "Corresponding list :\n");
                    dumpList(duel_l, logfp);
                }
                if(ind != -1) {
                    displayWinner(mat.tab[0][mat.offset + ind], "cm", nbCandidates, nbVoters, 0, 0);
                } else {
                    ind = minimax(duel);
                    if(ind == -1) {
                        displayWinner("egalite entre plusieurs candidats", "cm", nbCandidates, nbVoters, 0, 0);
                    } else {
                        displayWinner(mat.tab[0][ind + mat.offset], "cm", nbCandidates, nbVoters, 0, 0);
                    }
                }
            } if(method == NULL || !strcmp(method, "cp")) {
                dyn_mat duel = ballottoduel(mat, vote);
                list duel_l = dueltolist(duel);
                int ind = isCondorcetWinner(duel_l, nbCandidates);
                if(isLog()) {
                    fprintf(logfp, "---- Condorcet ranked pairs dislpay : ----\n\n");
                    fprintf(logfp, "Duel matrix :\n");
                    printDynIntMat(duel, logfp);
                    fprintf(logfp, "Corresponding list :\n");
                    dumpList(duel_l, logfp);
                }
                if(ind != -1) {
                    generateFile(duel_l);
                    displayWinner(mat.tab[0][mat.offset + ind], "cp", nbCandidates, nbVoters, 0, 0);
                } else {
                    list temp = rankedPairs(duel);
                    generateFile(temp);
                    ind = isCondorcetWinner(temp, nbCandidates);
                    displayWinner(mat.tab[0][mat.offset + ind], "cp", nbCandidates, nbVoters, 0, 0);
                }
            } if(method == NULL || !strcmp(method, "cs")) {
                puts("The schulze method is not available.");
                /*
                dyn_mat duel = ballottoduel(mat, vote);
                list duel_l = dueltolist(duel);
                if(isCondorcetWinner(duel_l, nbCandidates)) {
                    displayWinner(winner, "cs", nbCandidates, nbVoters, 0, 0);
                } else {
                    displayWinner(winner, "cs", nbCandidates, nbVoters, 0, 0);
                }*/
            } if((method == NULL || !strcmp(method, "va")) && vote == BALLOT) {
                winner = instant_runnoff_voting(mat);
                displayWinner(winner, "va", nbCandidates, nbVoters, 0, 0);
            } if(method != NULL) {
                if((!strcmp(method, "va") && vote != BALLOT) || (!strcmp(method, "uni2") && vote != BALLOT) || (!strcmp(method, "uni1") && vote != BALLOT)) {
                    fprintf(stderr, "You cannot use a matrix of duels with this method of voting.\n");
                }
            }
        } else {
            fputs("An error occured while opening file.\n", stderr);
        }
    } else {
        fputs("An error occured with the tags.\n", stderr);
        return EXIT_FAILURE;
    }
    free(logfpName);
    free(csvName);
    free(method);
    return EXIT_SUCCESS;
}
