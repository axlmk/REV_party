#include "../../header/list.h"

void getElt(Elementlist *e) {
    /// \brief Renvoie un arc orienté tapé au clavier
    /// \param[out] e : arc à renvoyer
    int src, dest, wei;
    puts("Insert 3 values : source, destination, weight :");
    scanf("%d\n", &src);
    scanf("%d\n", &dest);
    scanf("%d\n", &wei);
    e->src = src;
    e->dest = dest;
    e->weight = wei;
}

void cpyElt(Elementlist *target, Elementlist source) {
    /// \brief Copie un arc dans un autre
    /// \param[in] source : Arc à copier
    /// \param[out] target : Arc où copier
        target->src = source.src;
        target->dest = source.dest;
        target->weight = source.weight;
}

void printElt(Elementlist e, FILE *fp) {
    /// \brief Affiche un Arc
    /// \param[in] e : Arc à afficher
    /// \param[in, out] fp : Fichier ou afficher l'arc
    fprintf(fp, "(%d to %d : %d)\n", e.src, e.dest, e.weight);
}

bool cmpElt(Elementlist e1, Elementlist e2) {
    /// \brief Compare deux arcs
    /// \param[in] e1 : Arc à comparer
    /// \param[in] e2 : Arc à comparer
    if(e1.src == e2.src && e1.dest == e2.dest && e1.weight == e2.weight) {
        return true;
    } else {
        return false;
    }
}

int nbEltList(list lst) {
    /// \brief Renvoie le nombre d'éléments dans une Liste
    /// \param[in] lst : Liste dont on cherche le nombre d'éléments
    /// \return Nombre d'éléments de la liste
    return lst.nbElt;
}

void createList(list *p) {
    /// \brief Initialise une liste
    /// \param[in] p : Liste à initialiser
    p->head = VIDE;
    p->nbElt = 0;
}

void addFrontList(list *p, Elementlist e) {
    /// \brief Ajoute un élément en tête de Liste
    /// \param[in] p : Liste à laquelle on va ajouter l'élément
    /// \param[in] e : Elément à rajouter
    if(fullList(*p)) {
        fprintf(stderr, "You cannot add an element, the list is full.\n");
    } else {
        if(emptyList(*p)) {
            p->nbElt++;
            p->head++;
            cpyElt(&p->arrList[p->head], e);
        } else {
            p->head--;
            if(p->head < 0) {
                p->head = DIMMAX - 1;
            }
            cpyElt(&p->arrList[p->head], e);
            p->nbElt++;
        }
    }
}

void addTailList(list *p, Elementlist e) {
    /// \brief Ajoute un élément en queue de Liste
    /// \param[in] p : Liste à laquelle on va ajouter l'élément
    /// \param[in] e : Elément à rajouter
    if(fullList(*p)) {
        fprintf(stderr, "You cannot add an element, the list is full.\n");
    } else {
        if(emptyList(*p)) {
            p->nbElt++;
            p->head++;
            cpyElt(&p->arrList[p->head], e);
        } else {
            if(p->head + p->nbElt >= DIMMAX) {
                cpyElt(&p->arrList[p->head + p->nbElt - DIMMAX], e);
            } else {
                cpyElt(&p->arrList[p->head + p->nbElt], e);
            }
            p->nbElt++;
        }
    }
}

void delTailList(list *p) {
    /// \brief Supprime un élément en queue de Liste
    /// \param[in] p : Liste à laquelle on va supprimer l'élément
    /// \param[in] e : Elément à supprimer
    if(emptyList(*p)) {
        fprintf(stderr, "You cannot delete an element, the list is empty.\n");
    }
    if(nbEltList(*p) == 1) {
        createList(p);
    } else {
        p->nbElt--;
    }
}

void delFrontList(list *p) {
    /// \brief Supprime un élément en tête de Liste
    /// \param[in] p : Liste à laquelle on va supprimer l'élément
    /// \param[in] e : Elément à supprimer
    if(emptyList(*p)) {
        fprintf(stderr, "You cannot delete an element, the list is empty.\n");
    }
    if(nbEltList(*p) == 1) {
        createList(p);
    } else {
        p->nbElt--;
        p->head++;
        if(p->head >= DIMMAX) {
            p->head = 0;
        }
    }
}

void headList(list p, Elementlist *e) {
    /// \brief Renvoie l'élément en tête de liste
    /// \param[in] p : Liste dans laquelle on cherche l'élément
    /// \param[out] e : Elément qu'on veut récupérer
    cpyElt(e, p.arrList[p.head]);
}

void tailList(list p, Elementlist *e) {
    /// \brief Renvoie l'élément en queue de liste
    /// \param[in] p : Liste dans laquelle on cherche l'élément
    /// \param[out] e : Elément qu'on veut récupérer
    if(p.head + p.nbElt >= DIMMAX) {
        cpyElt(e, p.arrList[p.head + p.nbElt - DIMMAX]);
    } else {
        cpyElt(e, p.arrList[p.head + p.nbElt]);
    }
}

bool emptyList(list p) {
    /// \brief Informe si une liste est vide
    /// \param[in] p : Liste qu'on souhaite étudier
    if(nbEltList(p) == 0) {
        return true;
    } return false;
}

bool fullList(list p) {
    /// \brief Informe si une liste est pleine
    /// \param[in] p : Liste qu'on souhaite étudier
    if(nbEltList(p) == DIMMAX) {
        return true;
    } return false;
}

void dumpList(list p, FILE *fp) {
    /// \brief Affiche une liste sur un fichier
    /// \param[in] p : Liste à afficher
    /// \param[int, out] fp : Fichier où on veut afficher la liste
    int i;
    if(emptyList(p)) {
        fprintf(stderr, "There is nothing to display because the list is empty.\n");
    } else {
        for(i=0;i<p.nbElt;i++) {
            if(p.head + i >= DIMMAX) {
                printElt(p.arrList[p.head + i - DIMMAX], fp);
            } else {
                printElt(p.arrList[p.head + i], fp);
            }
        }
    }
}

void swapEltList(Elementlist *a, Elementlist *b) {
    /// \brief Echange deux éléments
    /// \param[in, out] a : Elément à échanger
    /// \param[in, out] b : Elément à échanger
    Elementlist c;
    cpyElt(&c, *b);
    cpyElt(b, *a);
    cpyElt(a, c);
}

void bubbleSortListWDown(list *p) {
    /// \brief Tris une liste selon le poids des éléments dans l'ordre décroissant
    /// \param[in, out] p : Liste à trier
    int i, j;
    for(i=nbEltList(*p) - 1;i>0;i--) {
        for(j=0;j<i;j++) {
            if(p->arrList[j+1].weight > p->arrList[j].weight)
                swapEltList(&p->arrList[j+1], &p->arrList[j]);
        }
    }
}

void bubbleSortListWUp(list *p) {
    /// \brief Tris une liste selon le poids des éléments dans l'ordre croissant
    /// \param[in, out] p : Liste à trier
    int i, j;
    for(i=nbEltList(*p) - 1;i>0;i--) {
        for(j=0;j<i;j++) {
            if(p->arrList[j+1].weight > p->arrList[j].weight)
                swapEltList(&p->arrList[j+1], &p->arrList[j]);
        }
    }
}

void pickEltList(list l, Elementlist *e, int index) {
    /// \brief Récupère un élément de la liste selon son index
    /// \param[in] l : Liste dans laquelle on va chercher l'élément
    /// \param[out] e : Elément que l'on veut récupérer
    /// \param[in] index : Index auxquel chercher l'élément
    if(emptyList(l)) {
        fprintf(stderr, "There is no element to return, because the list is empty.\n");
    } else {
        if(index < 0 || index >= DIMMAX) {
            fprintf(stderr, "The index is not valid.\n");
        } else if(index >= l.head && index < l.head + l.nbElt) {
                cpyElt(e, l.arrList[index]);
        } else {
            fprintf(stderr, "The element indexed is not valid.\n");
        }
    }
}

bool belongEltList(list p,Elementlist e) {
    /// \brief Informe si un élément est présent dans une liste
    /// \param[in] p : Liste où l'on cherche l'élément
    /// \param[in] e : Elément que l'on cherche
    if(emptyList(p)) {
        fprintf(stderr, "The element cannot belong to the list, because the list is empty.\n");
    } else {
        int i, u;
        for(i=0;i<p.nbElt;i++) {
            if(p.head + i >= DIMMAX) {
                u = p.head + i - DIMMAX;
            } else {
                u = i;
            }
            if(cmpElt(p.arrList[u], e)) {
                return true;
            }
        }
    }
    return false;
}

void dumpListGraph(list p, FILE *fp) {
    /// \brief Affiche une liste sur un fichier selon un format propre à l'affichage d'un graphe
    /// \param[in] p : Liste à afficher
    /// \param[in, out] fp : Fichier où afficher la liste
    int i;
    if(emptyList(p)) {
        fprintf(stderr, "There is nothing to display because the list is empty.\n");
    } else {
        for(i=0;i<p.nbElt;i++) {
            if(p.head + i >= DIMMAX) {
                fprintf(fp, "G.add_edges_from([(%d, %d)], weight=%d)\n", p.arrList[p.head + i - DIMMAX].src, p.arrList[p.head + i - DIMMAX].dest, p.arrList[p.head + i - DIMMAX].weight);
            } else {
                fprintf(fp, "G.add_edges_from([(%d, %d)], weight=%d)\n", p.arrList[p.head + i].src, p.arrList[p.head + i].dest, p.arrList[p.head + i].weight);
            }
        }
    }
}
