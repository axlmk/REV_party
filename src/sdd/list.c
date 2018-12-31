#include "../../header/list.h"

void getElt(Elementlist *e) {

}

void cpyElt(Elementlist *target, Elementlist source) {
        target->src = source.src;
        target->dest = source.dest;
        target->weight = source.weight;
}

void printElt(Elementlist e, FILE *fp) {
    fprintf(fp, "(%d to %d : %d)\n", e.src, e.dest, e.weight);
}

bool cmpElt(Elementlist e1, Elementlist e2) {
    if(e1.src == e2.src && e1.dest == e2.dest && e1.weight == e2.weight) {
        return true;
    } else {
        return false;
    }
}

int nbEltList(list lst) {
    return lst.nbElt;
}

void createList(list *p) {
    p->head = VIDE;
    p->nbElt = 0;
}

void addFrontList(list *p, Elementlist e) {
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
    cpyElt(e, p.arrList[p.head]);
}

void tailList(list p, Elementlist *e) {
    if(p.head + p.nbElt >= DIMMAX) {
        cpyElt(e, p.arrList[p.head + p.nbElt - DIMMAX]);
    } else {
        cpyElt(e, p.arrList[p.head + p.nbElt]);
    }
}

bool emptyList(list p) {
    if(nbEltList(p) == 0) {
        return true;
    } return false;
}

bool fullList(list p) {
    if(nbEltList(p) == DIMMAX) {
        return true;
    } return false;
}

void dumpList(list p, FILE *fp) {
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
    Elementlist c;
    cpyElt(&c, *b);
    cpyElt(b, *a);
    cpyElt(a, c);
}

void bubbleSortList(list *p) {
    /*
    pour i allant de taille de T - 1 à 1
    pour j allant de 0 à i - 1
    si T[j+1] < T[j]
    échanger(T[j+1], T[j])
    */
    int i, j;
    for(i=nbEltList(*p) - 1;i>0;i--) {
        for(j=0;j<i;j++) {
            if(p->arrList[j+1].src < p->arrList[j].src) //a changer en weight si besoin est
                swapEltList(&p->arrList[j+1], &p->arrList[j]);
        }
    }
}

void bubbleSortListW(list *p) {
    int i, j;
    for(i=nbEltList(*p) - 1;i>0;i--) {
        for(j=0;j<i;j++) {
            if(p->arrList[j+1].weight > p->arrList[j].weight)
                swapEltList(&p->arrList[j+1], &p->arrList[j]);
        }
    }
}


void pickEltList(list l, Elementlist *e, int index) {
    if(emptyList(l)) {
        fprintf(stderr, "There is no element to return, because the list is empty.\n");
    } else {
        if(index < 0 || index >= DIMMAX) {
            fprintf(stderr, "The index is not valid.\n");
        } else if(index >= l.head && index < l.head + l.nbElt) {
                cpyElt(e, l.arrList[index]);
                cpyElt(e, l.arrList[l.head + l.nbElt - 1]);
        } else {
            fprintf(stderr, "The element indexed is not valid.\n");
        }
    }
}

bool belongEltList(list p,Elementlist e) {
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
