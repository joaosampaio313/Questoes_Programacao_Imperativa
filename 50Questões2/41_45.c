#include <stdio.h>

/** Exercicio 41
 * Dada uma árvore de inteiros, calcula a árvore das somas acumuladas dessa árvore.
 * A árvore calculada deve ter a mesma forma da árvore recebida como argumento e em cada
 * nodo deve conter a soma dos elementos da sub-árvore que aı́ se inicia.*/
ABin somasAcA(ABin a){
    ABin r, dir, esq;
    if (a == NULL)
        r = NULL;
    else
    {
        r = malloc(sizeof(struct nodo));
        r->valor = 0;
        dir = somasAcA(a->dir);
        esq = somasAcA(a->esq);
        r->dir = dir;
        r->esq = esq;
        if (dir)
            r->valor += dir->valor;
        if (esq)
            r->valor += esq->valor;
        r->valor += a->valor;
    }
    return r;
}

/** Exercicio 42
 * Dada uma árvore binária de inteiros, conta quantos dos seus nodos são folhas, i.e., que não têm nenhum descendente.*/
int contaFolhas (ABin a){
    int conta = 0;
    
    if (a){
        if (a->valor && !a->esq && !a->dir)
            conta++;
            
        conta+=contaFolhas(a->esq);
        conta+=contaFolhas(a->dir);
    }
    return conta;
}

/** Exercicio 43
 * Cria uma árvore nova, com o resultado de inverter a árvore (efeito de espelho).*/
ABin cloneMirror (ABin a){
    ABin n = NULL;
    int aux;
    
    if (a){
        aux = a->esq;
        a->esq = a->dir;
        a-> dir = aux;
        n = malloc(sizeof(ABin));
        n->valor = a->valor;

        n->esq = cloneMirror(a->esq);
        n->dir = cloneMirror(a->dir);

    }

    return n;
}

/** Exercicio 44
 * Adiciona um elemento a uma árvore binária de procura. A função deverá retornar 1 se o elemento a inserir 
 * já existir na árvore ou 0 no outro caso.*/
int addOrd (ABin *a, int x){
    int res = 0;

    if 
    
    if (!*a){
        *a = malloc(sizeof(ABin));
        (*a)->valor = x;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
    }
    else {
        if ((*a)->valor == x)
            res = 1;
        else{
            if (x > (*a)->valor)
             res = addOrd(&(*a)->dir,x);
            if (x < (*a)->valor)
             res = addOrd(&(*a)->esq,x);
      }
    }
    return res;
}

/** Exercicio 45
 * Testa se um elemento pertence a uma árvore binária de procura. */
int lookupAB (ABin a, int x){
    int res = 0;

    if (a){
        if (a->valor == x)
            res = 1;
        else{
            res = lookupAB(a->esq,x);
            res = lookupAB(a->dir,x);
        }
    }
    return res;
}