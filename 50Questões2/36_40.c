q2#include <stio.h>

/** Exercicio 36
 * Remove (libertando o espaço respectivo) todos os elementos da árvore *a que estão a uma profundidade superior a l, retornando
 * o número de elementos removidos. Assuma que a profundidade da raı́z da árvore é 1, e por isso a invocação pruneAB(&a,0)
 * corresponde a remover todos os elementos da árvore a.*/
int pruneAB(ABin *a, int l){
    int conta = 0;

    conta+=pruneAB(a->esq,l-1);
    conta+=pruneAB(a->dir,l-1);

    if (l<=0){
        free(a);
        *a = NULL;
        conta++;
    }
    return conta
}

/** Exercicio 37
 * Testa se duas árvores são iguais (têm os mesmos elementos e a mesma forma). */
int iguaisAB (ABin a, ABin b){
    int res = 0;

    if (a && b){
        res = (a->valor == b->valor) && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
    }

    if (!a && !b)
        res = 1;
    return res;
}

/** Exercicio 38
 * *Dada uma árvore binária, constrói uma lista com os valores dos elementos que estão armazenados na árvore ao nı́vel n (assuma
 *  que a raiz da árvore está ao nı́vel 1). */
LInt nivelL (ABin a, int n){
    LInt lesq;
    LInt ldir;
    LInt l;

    LInt *el;

    if (a){
        if (n == 1){
            l = malloc(sizeof(LInt));
            l->valor = a->valor;
            l->prox = NULL;
        }
        else{
            lesq = nivelL(a->esq,n-1);
            ldir = nivelL(a->dir,n-1);

            el = &lesq;

            while(*el)
                el = &(*el)->prox;
            *el = ldir;
            l = lesq;
        }
    }
        return l;
}

/** Exercicio 39
 * Preenche o vector v com os elementos de a que se encontram no nı́vel n.
 * Considere que a raı́z da árvore se encontra no nı́vel 1.
 * A função deverá retornar o número de posições preenchidas do array.*/
int nivelV (ABin a, int n, int v[]){
    int i = 0;
    int vEsq = 0;
    int vDir = 0;

    
    if (a && n >= 1){
        if (n == 1)
            v[i++] = a->valor;
        else{
            vEsq+=nivelV(a->esq, n-1, v);
            vDir+=nivelV(a->dir,n-1,v);
        }    
    }

    return i;
}

/** Exercicio 40
 * Dada uma árvore a, preenche o array v com os elementos da árvore segundo uma travessia inorder. A função deverá
 * preencher no máximo N elementos e retornar o número de elementos preenchidos.*/
int dumpAbin (ABin a, int v[], int N) {
    int i = 0;
     
     if (a){
        i+=dumpAbin(a->esq,v+i,N);

        if (a && i < N)
        v[i++] = a->valor;

        i+=dumpAbin(a->dir,v+i,N-i);
    }
    return i;
}