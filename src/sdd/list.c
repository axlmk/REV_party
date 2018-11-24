#include "../../header/list.h"

void getElt(Elementlist *e) {

}

void cpyElt(Elementlist *target, Elementlist source) {
        target->src = source.src;
        target->dest = source.dest;
        target->weight = source.weight;
}

void printElt(Elementlist e, FILE *fp) {
    fprintf(fp, "(%d to %d : %d)", e.src, e.dest, e.weight);
}

bool cmpElt(Elementlist e1, Elementlist e2) {
    if(e1.src == e2.src && e1.dest == e2.dest && e1.weight == e2.weight) {
        return true;
    } else {
        return false;
    }
}

int nbEltList(list lst) {
    if(fullList(lst)) {
        return DIMMAX;
    } else if(emptyList(lst)) {
        return 0;
    } else {
        if(lst.nbElt > lst.head) {
            return lst.nbElt - lst.head + 1;
        } else if(lst.nbElt < lst.head) {
             return (lst.nbElt + 1) + (DIMMAX - lst.head);
        } else {
            return 1;
        }
    }
}

void createList(list *p) {
    p->nbElt = -1; //tail
    p->head = -1; //front
}

void addFrontList(list *p, Elementlist e) {
    if(emptyList(*p)) {
        cpyElt(&p->arrList[0], e);
        p->nbElt = 0;
        p->head = 0;
    } else {
        if(p->head - 1 < 0) {
            p->head = DIMMAX - 1;
        } else {
            p->head--;
        }
        cpyElt(&p->arrList[p->head], e);
    }
}

void addTailList(list *p, Elementlist e) {
    if(emptyList(*p)) {
        cpyElt(&p->arrList[0], e);
        p->nbElt = 0;
        p->head = 0;
    } else {
        if(p->nbElt + 1 == DIMMAX) {
            p->nbElt = 0;
        } else {
            p->nbElt++;
        }
        cpyElt(&p->arrList[p->nbElt], e);
    }
}

void delTailList(list *p) {
    if(nbEltList(*p) == 1) {
        createList(p);
    } else {
        if(p->nbElt - 1 < 0) {
            p->nbElt = DIMMAX;
        } else {
            p->nbElt--;
        }
    }
}

void delFrontList(list *p) {
    if(nbEltList(*p) == 1) {
        createList(p);
    } else {
        if(p->head + 1 == DIMMAX) {
            p->head = 0;
        } else {
            p->head++;
        }
    }
}

void headList(list p, Elementlist *e) {
    cpyElt(e, p.arrList[p.head]);
}

void tailList(list p, Elementlist *e) {
    cpyElt(e, p.arrList[p.nbElt]);
}

bool emptyList(list p) {
    return p.nbElt == -1;
}

bool fullList(list p) {
    if(p.nbElt == 99 && p.head == 0)
        return true;
    else
        return p.head == p.nbElt + 1;
}

void dumpList(list p,FILE *fp) {
    int i;
    if(p.nbElt <= p.head) {
        i = p.head;
        while(i != p.nbElt) {
            printElt(p.arrList[i], fp);
            i++;
            if(i == DIMMAX) {
                i = 0;
            }
        }
    } else {
        for(i=p.head;i<p.nbElt;i++) {
            printElt(p.arrList[i], fp);
        }
    }
}

void swapEltList(Elementlist *a, Elementlist *b) {
    Elementlist c;
    cpyElt(&c, *b);
    cpyElt(b, *a);
    cpyElt(a, c);
}

void bubbleSortList(list *p);

void pickEltList(list l, Elementlist *e, int index) {
    cpyElt(e, l.arrList[index]);
}

bool belongEltList(list p,Elementlist e) {
    int i;
    if(p.nbElt == p.head) {
        return cmpElt(p.arrList[p.head], e);
    } else if (p.nbElt < p.head) {
        i = p.head;
        while(i != p.nbElt) {
            if(cmpElt(p.arrList[i], e)) {
                return true;
            }
            i++;
            if(i == DIMMAX) {
                i = 0;
            }
        }
    } else {
        for(i=p.head;i<p.nbElt;i++) {
            if(cmpElt(p.arrList[i], e)) {
                return true;
            }
        }
    }
    return false;
}
