#include "../../header/display.h"

void displayWinner(char *winner, char *vote, int nbCandidates, int nbVoters, int pourcent, int tour) {
    /// \brief Affiche le gagnant d'une méthode spécifique
    /// \param[in] winner : Nom du gagnant
    /// \param[in] vote : Type de scrutin utilisé
    /// \param[in] nbCandidates : Nombre de candidats
    /// \param[in] nbVoters : Nombre de votants
    /// \param[in] pourcent : Pourcentage de votes du vainqueur
    /// \param[in] tour : Tour de jeu pour uni 1 et uni 2
    fputs("Mode de scrutin : ", stdout);
    if(!strcmp(vote, "uni1")) {
        fputs("uninominal a un tour, ", stdout);
    } else if(!strcmp(vote, "uni2")) {
        printf("uninominal a deux tour, tours %d, ", tour);
    } else if(!strcmp(vote, "cm")) {
        fputs("condorcet minimax, ", stdout);
    } else if(!strcmp(vote, "cp")) {
        fputs("condorcet paires, ", stdout);
    } else if(!strcmp(vote, "cs")) {
        fputs("condorcet schulze, ", stdout);
    } else if(!strcmp(vote, "va")) {
        fputs("vote alternatif, ", stdout);
    } else {
        fputs("Invalid voting method.\n", stderr);
    }
    printf("%d candidats, %d votants, vainqueur = %s", nbCandidates, nbVoters, winner);
    if(!strcmp(vote, "uni1") || !strcmp(vote, "uni2"))
        printf(", score = %d%%", pourcent);
    puts("");
}
