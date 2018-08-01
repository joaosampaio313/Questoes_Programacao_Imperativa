#include <stdio.h>

/** Exercicio 46
 *Calcula o nı́vel a que um elemento está numa árvore binária de procura (-1 caso não exista).*/
int depthOrd (ABin a, int x){
    int conta = -1;
    if (a){
        if (a->valor == x)
            conta = 1;
        else{
            if (x > a->valor)
                conta+=depthOrd(a->dir,x);
            else    
                conta+=depthOrd(a->esq,x);
        }
    }

    if (a->valor != x)
    (conta == -1) ? -1 : conta++;
    
    return conta;
}   

/** Exercicio 47
  * Calcula o maior elemento de uma árvore binária de procura não vazia.*/
int maiorAB(ABin a){
    int maior;

    while(a && a->dir)
        a = a->dir;
    if (a)
        maior = a->valor;
    
    return maior;
}  

/** Exercicio 48
 * Remove o maior elemento de uma árvore binária de procura. */
void removeMaiorA(ABin *a){

    if (*a && !(*a)->dir)
        *a = (*a)->esq;
    else
        removeMaiorA(&(*a)->dir);
}

/** Exercicio 49
 * Dada uma árvore binária de procura de inteiros e um inteiro, conta quantos elementos da árvore são maiores 
 * que o inteiro dado.*/
int quantosMaiores(ABin a, int x){
    int conta = 0;
    if (a){
        if (a->valor > x)
            conta++;
        conta+=quantosMaiores(a->esq,x);
        conta+=quantosMaiores(a->dir,x);
    }
    return conta;
} 

/** Exercicio 50
 * Constrói uma árvore binária de procura a partir de uma lista ligada ordenada.*/
void listToBTree(LInt l, ABin *a){
    
    if (!l)
         *a = NULL; 
    else{
        *a = malloc(sizeof(ABin));
        (*a)->valor = l->valor;
        (*a)->esq = NULL;
        listToBTree(l->prox,&(*a)->dir);
    }
}

/** Exercicio 51
 * Testa se uma árvore é de procura.*/
int deProcura(ABin a){
    int res = 0;

    ABin esq,dir;

    if(a){
        esq = a->esq;
        dir = a->dir;

        if (dir && esq){
        if (dir->valor > a->valor && esq->valor < a->valor)
            res = 1;
        }
        if (dir && !esq){
            if (dir->valor > a->valor)
                res = 1;
        }
        if (!dir && esq){
            if (esq->valor < a->valor)
                res = 1;
        }
    
    res = deProcura(a->esq);
    res = deProcura(a->dir);    
    }

    return res;
}

int compare(ABin a, int x, int mod){
    res = 1;
    if (a){
        if (mod){
            res = a->valor > x && compare(a->esq,x,mod) && compare(a->dir,x,mod);         
        else(!mod)
            res = a->valor < x && compare(a->esq,x,mod) && compare(a->dir,x,mod);
        }
    }

    return res;
}

int deProcura(ABin a){
    int res = 1;

    if (a)
        res = compare(a->esq,a->valor,0) && compare(a->dir,a->valor,1) && deProcura(a->esq) && deProcura(a->dir);
    return res;
}



int compare(ABin a, int x, int mod){
    if(a == NULL)
        return 1;
    else if(mod == 0) //x maior que todos os valores
        return (x > a->valor && compare(a->esq, x, mod) && compare(a->dir, x, mod));
    else if(mod == 1) //x menor que todos os valores
        return (x < a->valor && compare(a->esq, x, mod) && compare(a->dir, x, mod));
}
 
 
int deProcura(ABin a){
    if(a == NULL)
        return 1;
    else
        return(
            compare(a->esq, a->valor, 0) &&
            compare(a->dir, a->valor, 1) &&
            deProcura(a->esq) &&
            deProcura(a->dir)
        );
}


int compare(ABin a, int x, int mod){
    int res = 1;
    if (a){
        if (mod){
            res = x > a->valor && compare(a->esq,x,mod) && compare(a->dir,x,mod);         
        if (!mod)
            res = x > a->valor && compare(a->esq,x,mod) && compare(a->dir,x,mod);
        }
    }

    return res;
}

int deProcura(ABin a){
    int res = 1;

    if (a)
        res = compare(a->esq,a->valor,0) && compare(a->dir,a->valor,1) && deProcura(a->esq) && deProcura(a->dir);
    return res;
}