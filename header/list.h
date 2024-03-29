/// \file list.h
/// \brief Définie toutes les listes et arcs ainsi que les fonctions qui y sont liées
/// \author Axel GAUTHIER
/// \date 2019

#ifndef LIST_H_
#define LIST_H_

#include "./sdd.h"
// maximum size of the list
///
#define DIMMAX 100
// constant to define an empty lisg
#define VIDE -1

typedef w_arc Elementlist;

struct list{
    /// \struct list
    /// \brief Liste d'arc orentés circulaire
    /// \var list::arrList
    ///Tableau statique de w_arc
    /// \var list::head
    ///Entier correspondant à l'index du premier élément
    /// \var list::nbElt
    ///Entier correspondant au nombre d'éléments du tableau
    Elementlist arrList[DIMMAX];
    int head;
    int nbElt;
};

typedef struct list list;

void getElt(Elementlist *e);
void cpyElt(Elementlist *target, Elementlist source);
void printElt(Elementlist e, FILE *fp);
bool cmpElt(Elementlist e1, Elementlist e2);

int nbEltList(list lst); // nombre d'éléments
void createList(list *p); // renvoie une list statique
void addFrontList(list *p, Elementlist e); // ajoute un élément devant
void addTailList(list *p, Elementlist e); // ajoute un élément derrière
void delTailList(list *p); // supprime l'élément de fin
void delFrontList(list *p); // supprime l'élément de tête
void headList(list p, Elementlist *e); // renvoie l'élément de tête
void tailList(list p, Elementlist *e); // renvoie l'élément de fin
bool emptyList(list p); // renvoie true si la pile est vide, false sinon
bool fullList(list p); // renvoie true si la pile est pleine, false sinon
void dumpList(list p,FILE *fp); // affiche le contenu de la list
void dumpListGraph(list p, FILE *fp);
void swapEltList(Elementlist *a,Elementlist *b); // échange deux éléments de la list
void bubbleSortListWDown(list *p); //trie la list
void bubbleSortListWUp(list *p);
void pickEltList(list l,Elementlist *e,int index); // renvoie l'élément n° index
bool belongEltList(list p,Elementlist e); // true si l'élément est dans la list

#endif
