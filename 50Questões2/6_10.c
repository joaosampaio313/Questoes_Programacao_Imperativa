#include <stdio.h>

/** Exercicio 6
 * Remove um elemento de uma lista ordenada. Retorna 1 caso o elemento a remover não exista, 0 no outro caso.*/
int removeOneOrd(LInt *l,int x){
    int res = 0;
    LInt aux;
    LInt ant;
    while (*l && (*l)-> valor < x){
        ant = *l;
        l = &(*l)-> prox;
    }

    if (*l){
    aux = (*l) -> prox;
    free(*l);
    ant -> prox = aux;
    res = 1;
    }
    
    return res;
}

int removeOneOrd (LInt *l, int x){
    int r = 1;
    LInt ant = NULL;
    LInt p;
    
    while (*l && (*l) -> valor < x)
    {
        ant = *l;
        l = &(*l) -> prox;
    }
    
    if (ant && *l)
    {
        p = (*l) -> prox;
        free(*l);
        *l = p;
        r = 0;
    }
    
    if (!ant && *l)
    {
        p =(*l) -> prox;
        free(*l);
        *l = p;
        r = 0;
    }
    return r;
}

/** Exercicio 7
 * Junta duas listas ordenadas (a e b) numa única lista ordenada (r). */
void merge (LInt *r, LInt a, LInt b){
    LInt n;
    *r = NULL;
    if (!a && b) 
        *r = b;
    else
    {
        if(a && !b)
            *r = a;
        else { 
    while (a && b){
        if (a -> valor > b -> valor){
            *r = b;
            b = b -> prox;
            r = &(*r) -> prox;
        }
        else{
                *r = a;
                a = a -> prox;
                r = &(*r) -> prox;
            }
        }
        
        if (!*r && a)
            *r = a;
        else
            if(!*r && b)
                *r = b;
            
      }
      
    }
}

/** Exercicio 8
 * Dada uma lista ligada l e um inteiro x, parte a lista em duas (retornando os endereços dos primeiros elementos da lista 
 * em *mx e *Mx): uma com os elementos de l menores do que x e a outra com os restantes. Note que esta função não deverá 
 * criar cópias dos elementos da lista.*/
void splitQS (LInt l, int x, LInt *mx, LInt *Mx)
{
    while (l)
    {
        if (l-> valor < x)
        {
            *mx = l;
            mx = &((*mx) -> prox);
        }
        else
        {
            *Mx = l;
            Mx = &((*Mx) -> prox);
        }
        
        l = l -> prox;
    }
    *mx = 0;
    *Mx = 0;
}

/** Exercicio 9
 * Parte uma lista não vazia *l a meio. Se x contiver os elementos {1,2,3,4,5}, após a invocação y = parteAmeio(&x)
 * a lista y deverá conter os elementos {1,2} e a lista x os restantes {3,4,5} */

int lLength (LInt *l)
{
    LInt pt = *l;
    int conta = 0;

    while (pt)
    {
        conta++;
        pt = pt -> prox;
    }

    return conta;
}

LInt parteAmeio(LInt *l)
{
    int meio = lLength(l) / 2;
    int conta = 0;

    LInt *el;
    LInt pt;
    
    el = l;
    pt = *l;

    for (conta = 0; conta < meio; conta++)
        el = &((*el) -> prox);
    
    *l = *el;
    *el = NULL;

    if (conta == 0){
        *l = pt;
        return NULL;
    }
    return pt;
}

/** Exercicio 10
 * Remove todas as ocorrências de um dado inteiro de uma lista, retornando o número de células removidas.*/
int lLength (LInt *l){
    LInt pt = *l;
    int conta = 0;

    while (pt)
    {
        conta++;
        pt = pt -> prox;
    }

    return conta;
}

LInt parteAmeio(LInt *l){
    int conta = 0;
    int meio = lLength(l)/2;

    LInt *el;
    LInt pt;
    
    el = l;
    pt = *l;

    for(; conta < meio; conta++)
        el = &(*el) -> prox;

    *l = *el;
    *el = NULL;

    if (conta == 0){
        *l = pt;
        return NULL;}
    else
        return pt;    
}