#include "global.h" ///
#include "list.h" ///

// pour la recherche de circuit
#define LIBRE -1
#define OUVERT 0
#define FERME 1
#define KO -1

int trouveSuc(list larcs,int sommet,int **tabVus);
bool dfs(list larcs,int sommet,int * tabMark,int **tabVus);
bool circuits(list larcs, int nbCandidats);
