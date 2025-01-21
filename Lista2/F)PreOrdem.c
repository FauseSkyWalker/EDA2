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


void pre_ordem(no *raiz) {
    if (raiz == NULL) return;

    NoPilha *pilha = NULL;
    pilha = empilhar(pilha, raiz);

    while (!pilhaEstaVazia(pilha)) {
        no *atual;
        pilha = desempilhar(pilha, &atual);

        
        printf("%d ", atual->dado);

        
        if (atual->dir)
            pilha = empilhar(pilha, atual->dir);
        if (atual->esq)
            pilha = empilhar(pilha, atual->esq);
    }
}
