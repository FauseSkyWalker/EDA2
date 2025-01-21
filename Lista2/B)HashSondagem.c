#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *tb;
    int M;
    int N;
} TH;

int THremove(TH *h, int ch) {
    int pos = hash(ch, h->M);
    while (h->tb[pos] != -1) {
        if (h->tb[pos] == ch) {
            h->tb[pos] = -1;
            h->N--;

            int nextPos = (pos + 1) % h->M;
            while (h->tb[nextPos] != -1) {
                int chaveReinserir = h->tb[nextPos];
                h->tb[nextPos] = -1;
                h->N--;
                THinsere(h, chaveReinserir);
                nextPos = (nextPos + 1) % h->M;
            }

            return 0;
        }
        pos = (pos + 1) % h->M;
    }
    return -1;
}

void THinsere(TH *h, int ch) {
    if (h->N > h->M / 2) {
        redimensionaTabela(h);
    }

    int pos = hash(ch, h->M);
    while (h->tb[pos] != -1) {
        if (h->tb[pos] == ch) {
            return;
        }
        pos = (pos + 1) % h->M;
    }

    h->tb[pos] = ch;
    h->N++;
}


int THbusca(TH *h, int ch) {
    int pos = hash(ch, h->M);
    while (h->tb[pos] != -1) {
        if (h->tb[pos] == ch) {
            return 1;
        }
        pos = (pos + 1) % h->M;
    }
    return 0;
}

int aumentaTamanho(int M);

int hash(int chave, int M) {
    return chave % M;
}

void redimensionaTabela(TH *h) {
    int novoTamanho = aumentaTamanho(h->M);
    int *novaTabela = (int *)malloc(novoTamanho * sizeof(int));
    for (int i = 0; i < novoTamanho; i++) {
        novaTabela[i] = -1;
    }

    for (int i = 0; i < h->M; i++) {
        if (h->tb[i] != -1) {
            int pos = hash(h->tb[i], novoTamanho);
            while (novaTabela[pos] != -1) {
                pos = (pos + 1) % novoTamanho;
            }
            novaTabela[pos] = h->tb[i];
        }
    }

    free(h->tb);
    h->tb = novaTabela;
    h->M = novoTamanho;
}

