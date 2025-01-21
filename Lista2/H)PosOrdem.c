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


void pos_ordem (no *raiz){
    if (raiz == NULL) return;

    NoPilha *pilha1 = NULL, *pilha2 = NULL;
    pilha1 = empilhar(pilha1, raiz);

    while (!pilhaEstaVazia(pilha1)) {
        no *atual;
        pilha1 = desempilhar(pilha1, &atual);
        pilha2 = empilhar(pilha2, atual);

        if (atual->esq)
            pilha1 = empilhar(pilha1, atual->esq);
        if (atual->dir)
            pilha1 = empilhar(pilha1, atual->dir);
    }

    while (!pilhaEstaVazia(pilha2)) {
        no *atual;
        pilha2 = desempilhar(pilha2, &atual);
        printf("%d ", atual->dado);
    }
}