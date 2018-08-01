#include <stdio.h>

/** Considere o seguinte tipo para representar listas ligadas de inteiros. */
typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

/** Exercicio 1
 *  Calcula o comprimento de uma lista ligada. */
int length(LInt l){
    int conta = 0;

    while (l){
        conta++;
        l = l -> prox;
    }
    return conta;
}

/** Exercicio 2
 * Liberta o espaço ocupado por uma lista. */
void freeL(LInt l){
    LInt *el;
    while(l){
        el = &(l -> prox);
        free(l);
        l = *el;
    }
}

/** Exercicio 3
 * Imprime no ecran os elementos de uma lista (um por linha).*/
void imprimeL (LInt l){
    while(l){
        printf("%d \n",l.valor);
        l = l-> prox;
    }
}

/** Exercicio 4
 * Inverte uma lista (sem criar uma nova lista).*/
LInt reverseL(LInt l){
    LInt aux = NULL;
    LInt save;

    while (l){
        save = l;
        l = l -> prox;
        save -> prox = aux;
        aux = save; 
    }

    return aux;
}