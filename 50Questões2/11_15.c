#include <stdio.h>
#include "6_10.c"

/** Exercicio 11
 * Remove os valores repetidos de uma lista (deixando apenas a primeira ocorrência). */
int removeDups(LInt *l){

    int conta = 0;
    while(*l){
        conta+=removeAll(&(*l) -> prox,(*l) -> valor);
        l = &(*l)-> prox;
    }
    
    return conta;
}

/** Exercicio 12
 * Remove (a primeira ocorrência) o maior elemento de uma lista não vazia, retornando o valor desse elemento.*/

int maior(LInt *l){
    int maior = (*l)-> valor;

    while(*l){
        if((*l) -> valor > maior)
            maior = (*l) -> valor;
        l = &(*l)->prox;
    }

    return maior;
}

int removeMaiorL(LInt *l){
    int x = maior(l);
    LInt aux;

    while(*l && (*l) -> valor != x)
        l = &(*l)->prox;
    if ((*l) -> valor == x){
        aux = (*l)->prox;
        free(*l);
        *l = aux;
    }

    return x;
}

/** Exercicio 13
 * Remove o último elemento de uma lista não vazia (libertando o correspondente espaço).*/
void init(LInt *l){
    while(*l && (*l)-> prox)
        l = &(*l) -> prox;
    if(*l){
        free(*l);
        *l = NULL;
    }
}

/** Exercicio 14
 * Acrescenta um elemento no fim da lista. */
void appendL(LInt *l, int x){
    LInt n;

    while(*l)
        l = &(*l) -> prox;

    n = malloc(sizeof(struct lligada));
    n -> valor = x;
    n -> prox = NULL;

    *l = n;
}

/** Exercicio 15
 * Acrescenta a lista b à lista *a.*/
void concatL(LInt *a, LInt b){

    while(*a)
        a = &(*a) -> prox;
    
    *a = b;
}

