#include <stdio.h>

/** Exercicio 21
 * Dada uma lista circular dá como resultado o endereço do elemento da lista que está N posições à frente.*/
LInt NForward(LInt l, int N){
    int conta = 0;

    while(l && conta < N){
        l = l -> prox;
        conta++;
    }

    return l;
}

/** Exercicio 22
 * Dada uma lista l, preenche o array v com os elementos da lista. A função deverá preencher no máximo N elementos 
 * e retornar o número de elementos preenchidos.*/
int listToArray(LInt l, int v[],int N){
    int i = 0;

    for(; !l ; i++ ){
        v[i] = l -> valor;
        l = l -> prox;
    }

    return i;
 }

/** Exercicio 23
 * Constrói uma lista com os
elementos de um array, pela mesma ordem em que aparecem no array. */
LInt arrayToList(int v[],int N){
    int i = 0;
    LInt *el;
    LInt r;

    el = &r;

    for (; i < N; i++){
        *el = malloc(sizeof(struct lligada));
        (*el) = v[i];
        el = &(*el)->prox;
    }

    *el = NULL;

    return r;
}

/** Exercicio 24
 * Dada uma lista de inteiros, constrói uma nova lista de inteiros contendo as somas acumuladas da lista original 
 * (que deverá permanecer inalterada). Por exemplo, se a lista l tiver os valores [1,2,3,4] a lista contruı́da pela 
 * invocação de somasAcL (l) deverá conter os valores [1,3,6,10].*/
LInt somasAcL(LInt l){

    int sum = 0;
    LInt *el;
    LInt r;

    el = &r;

    while(l){
        sum+=(l->valor);
        *el = malloc(sizeof(struct lligada));
        (*el) -> valor = sum;
        el = &(*el)->prox;
        
        l = l -> prox;
    }
    

    *el =  NULL;

    return r;
}

/** Exercicio 25
 * Dada uma lista ordenada de inteiros, elimina dessa lista todos os valores repetidos assegurando que o espaço de memória 
 * correspondente aos nós removidos é correctamente libertado.*/

void remreps (LInt l){
    LInt aux;
    LInt save;
    while (l)
    {
        aux = l -> prox;
    while (aux && l -> valor == aux -> valor)
        {
            save = aux -> prox;
            free(p);
            aux = save;
        }
        l -> prox = aux;
        l = l -> prox;
    }
}



LInt parte (LInt l){
    int conta = 0;
    LInt par = NULL;
    LInt *el;
    LInt *ep;
    
    el = &l;
    ep = &par;
    
   while(l && *ep && *el){
        if(conta % 2 == 0){
            (*ep) -> valor = l -> valor;
            ep = &(*ep) -> prox;
            conta++;
        }
        else{
            (*el) -> valor = l -> valor;
            el = &(*el) -> prox;
            conta++;
        }
        
        l = l -> prox;
    }
    return par;
}


LInt parte (LInt l){
    LInt temp;
    if(l == NULL || l->prox == NULL)
        return NULL;
    else{
        LInt topEven = l->prox;
        while(l->prox){
            temp = l->prox;
            l->prox = (l->prox->prox) ? l->prox->prox : NULL;
            l = temp;
        }
        return topEven;
    }
}
