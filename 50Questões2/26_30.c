#include <stdio.h>

/** Exercicio 26
 * Coloca o primeiro elemento de uma lista no fim. Se a lista for vazia ou tiver apenas um elemento, a função não tem qualquer 
 * efeito prático (i.e., devolve a mesma lista que recebe como argumento).
 * Note que a sua função não deve alocar nem libertar memória. Apenas re-organizar as células da lista.*/

LInt rotateL(LInt l){
    LInt m = NULL;
    LInt *el;

    el = &l;
    
    while(*el)
        el = &(*el)->prox;
    
    *el = l;

    if(l){
        m = l->prox;
        l -> prox = NULL;
    }

    return m;

}

/** Exercicio 27
 * Parte uma lista l em duas: na lista l ficam apenas os elementos das posições ı́mpares; na lista resultante ficam 
 * os restantes elementos. Assim, se a lista x tiver os elementos {1,2,3,4,5,6} a chamada y = parte (x), coloca na
 * lista y os elementos {2,4,6} ficando em x apenas os elementos {1,3,5} */
LInt parte(LInt l){
    LInt topEven;
    LInt aux;

    if (!l)
        topEven = NULL;
    else{
        topEven = l->prox;
        if(l -> prox){
            aux = l->prox;
            l->prox = (l->prox)->prox;
            l = l->prox;
        }
    }
    return topEven;
}

/** Árvores Binárias
 * Considere o seguinte tipo para representar árvores binárias de inteiros. */
typedef struct nodo{
int valor;
struct nodo *esq, *dir;
} *ABin;

/** Exercicio 28
 * Calcula a altura de uma árvore binária.*/
int max(int x, int y){
    int max = x;

    if (x < y)
        max = y;
    return max;
}
int altura (ABin a){
    int res = 0;

    if (a)
        res = 1 + max(altura(a->esq),altura(a->dir));
    
    return res;
}

/** Exercicio 29
 *  Cria uma cópia de uma árvore. */
ABin cloneAB(ABin a){
    ABin n;
    if(a){
        n = malloc(sizeof(struct nodo));
        n -> valor = a -> valor;
        n -> esq = cloneAB(a -> esq);
        n -> dir = cloneAB(a -> dir);
    }

    return n;
}

/** Exercicio 30
 * Inverte uma árvore (sem criar uma nova árvore).*/
void mirror (ABin *a){
    ABin aux;
    if (*a){
        aux = (*a)->esq;
        (*a)->esq = (*a) -> dir;
        (*a)->dir = aux;
        mirror(&(*a)->esq);
        mirror(&(*a)->dir);
    }
}
