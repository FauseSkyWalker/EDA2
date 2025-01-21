#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct {
    celula *tb; 
    int M;      
    int N;      
} TH;


int hash(int chave, int M) {
    return chave % M;
}

int THremove(TH *h, int ch) {
    int pos = hash(ch, h->M);
    celula *atual = &h->tb[pos];
    celula *anterior = NULL;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;

        if (atual->dado == ch) {
            anterior->prox = atual->prox; 
            free(atual);
            h->N--;
            return 0; 
        }
    }
    return -1; 
}

int THbusca(TH *h, int ch) {
    int pos = hash(ch, h->M);
    celula *atual = h->tb[pos].prox;

    while (atual != NULL) {
        if (atual->dado == ch) {
            return 1; 
        }
        atual = atual->prox;
    }
    return 0; 
}


void THinsere(TH *h, int ch) {
    int pos = hash(ch, h->M);
    celula *atual = h->tb[pos].prox;

    
    while (atual != NULL) {
        if (atual->dado == ch) {
            return; 
        }
        atual = atual->prox;
    }

    
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->dado = ch;
    nova->prox = h->tb[pos].prox;
    h->tb[pos].prox = nova;
    h->N++;
}

void THinit(TH *h, int M) {
    h->tb = (celula *)malloc(M * sizeof(celula));
    for (int i = 0; i < M; i++) {
        h->tb[i].prox = NULL;
    }
    h->M = M;
    h->N = 0;
}





