#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;


typedef struct NoPilha {
    no *dado;
    struct NoPilha *prox;
} NoPilha;


NoPilha* empilhar(NoPilha *pilha, no *dado) {
    NoPilha *novo = (NoPilha*)malloc(sizeof(NoPilha));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->dado = dado;
    novo->prox = pilha;
    return novo;
}

NoPilha* desempilhar(NoPilha *pilha, no **dado) {
    if (!pilha) return NULL;
    NoPilha *topo = pilha;
    *dado = topo->dado;
    pilha = topo->prox;
    free(topo);
    return pilha;
}

int pilhaEstaVazia(NoPilha *pilha) {
    return pilha == NULL;
}


void em_ordem (no *raiz) {
    NoPilha *pilha = NULL; 
    no *atual = raiz;  

    while (!pilhaEstaVazia(pilha) || atual != NULL) {  
        while (atual != NULL) {  
            pilha = empilhar(pilha, atual); 
            atual = atual->esq;  
        }

       
        pilha = desempilhar(pilha, &atual);  
        printf("%d ", atual->dado);  

        atual = atual->dir;  
    }
}
