#include <stdio.h>

/** Exercicio 31
 * Cria uma lista ligada de inteiros a partir de uma travessia inorder de uma árvore binária.*/
void inorder(ABin a, LInt *l){
    *l = NULL;
    
    if(a){
        inorder(a->esq, l);
        
        *l = malloc(sizeof(LInt));
        (*l)->valor = a->valor;
        l = &(*l)->prox;
        
        inorder(a->dir, l);
    }
}

/** Exercicio 32
 * Cria uma lista ligada de inteiros a partir de uma travessia preorder de uma árvore binária.*/
void preorder(ABin a, LInt *l){
    *l = NULL;
    
    if(a){
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        
        preorder(a->esq,&(*l) -> prox);
        
        while(*l && (*l)->prox)
            l = &(*l)->prox;
        preorder(a->dir,&(*l)->prox);
    }
}

/** Exercicio 33
 * Cria uma lista ligada de inteiros a partir de uma travessia posorder de uma árvore binária. */
void posorder (ABin a, LInt *l){
    if(a == NULL)
        *l = NULL;
    else{
        posorder(a->esq, l);
        while(*l)
            l = &((*l)->prox);
        posorder(a->dir, l);
        while(*l)
            l = &((*l)->prox);
        (*l) = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL; 
    }
}

/** Exercicio 34
 * Calcula o nı́vel (menor) a que um elemento está numa árvore binária (-1 caso não exista).*/
int depth(ABin a, int x){
    int conta = -1;
    int aEsq = -1,aDir = -1;
    
    if (a){
        if (a->valor==x)
            conta = 1;
        else{
            aEsq = depth(a->esq,x);
            aDir = depth(a->dir,x);
            
            if (aEsq > 0 && aDir > 0)
                conta = 1 + ((aEsq > aDir) ? aDir: aEsq);
            else{
                if (aEsq > 0  && aDir < 0)
                    conta = 1 + aEsq;
                else{
                    if (aEsq < 0 && aDir > 0)
                        conta = 1 + aDir;
                }
            }
        }
    }
    return conta;
}

/** Exercicio 35
 * Liberta o espaço ocupado por uma árvore binária, retornando o número de nodos libertados. */
int freeAB (ABin a) {
    int conta = 0;
        
    if(a){
        conta+=freeAB(a->esq);
        conta+=freeAB(a->dir);
        free(a);
        conta++;
    }

    return conta;
}