#include <stdio.h>
#include "6_10.c"

/** Exercicio 16
 * Cria uma nova lista ligada com os elementos pela ordem em que aparecem na lista argumento.*/
LInt cloneL_mine(LInt l){
    LInt *el;
    LInt r;

    el = &r;

    while(l){
        *el = malloc(sizeof(struct lligada));
        (*el) -> valor = l -> valor;
        el = &(*el) -> prox;

        l = l -> prox;
    }

    *el = NULL;
    
    return r;
}

LInt cloneL(LInt l){
    LInt r;
    LInt n;
    LInt = *el;

    el = &r;

    while(l){
        *el = malloc(sizeof(struct lligada));
        (*el) -> valor  = l -> valor;

        el = &((*el) -> prox);

        l = l -> prox;
    }

    *el = NULL;

    return r;
}

/** Exercicio 17
 * Cria uma nova lista ligada com os elementos por ordem inversa. Por exemplo, se a lista l tiver 5 elementos com os valores 
 * {1,2,3,4,5} por esta ordem, a invocação cloneRev(l) deve corresponder a uma nova lista com os elementos {5,4,3,2,1} por esta
 * ordem.*/
LInt cloneRev (LInt l){
    LInt n;
    LInt aux = NULL;

    while(l){
        n = malloc(sizeof(struct lligada));
        n -> valor = l -> valor;
        n -> prox = aux;
        aux = n;

        l = l-> prox;
    }
    return n;
}

/** Exercicio 18
 * Calcula qual o maior valor armazenado numa lista não vazia.*/
int maximo (LInt l){
    int max = l -> valor;

    l = l -> prox;

    while(l){
        if (l -> valor > max)
            max = l -> valor;

        l = l -> prox;
    }

    return max;
}

/** Exercicio 19
 * Dado um inteiro n e uma lista ligada de inteiros l, apaga de l todos os nodos para além do n-ésimo
 * (libertando o respectivo espaço). Se a lista tiver n ou menos nodos, a função não altera a lista.
 * A função deve retornar o comprimento final da lista.*/
int take(int n,LInt *l){
    int conta = 0;
    int len = lLength(l);

    if (n >= len)
        conta = len;
    else { 
           while(*l && conta < n){
             l = &(*l) -> prox;
             conta++;
           }

           free(*l);
            *l = NULL;
    }
    return conta;
}


/** Exercicio 20
 * Dado um inteiro n e uma lista ligada de inteiros l, apaga de l os n primeiros elementos da lista (libertando 
 * o respectivo espaço). Se a lista tiver n ou menos nodos, a função liberta a totalidade da lista.
 * A função deve retornar o número de elementos removidos.*/
int drop(int n, LInt *l){
    int conta = 0;
    LInt aux;
    
    while(*l && conta < n){
        aux = (*l) -> prox;
        free(*l);
        *l = aux;
        conta++;
    }

    return conta;
}