#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    int colonia;
    char alimento[11];
    struct celula *prox;
} celula;

typedef struct {
    celula *tb; 
    int M;           
} TH;

void libera_tabela(TH *h){
    for(int i = 0; i < h->M; i++){
        celula *atual = h->tb[i].prox;
        while(atual != NULL){
            celula *remover = atual;
            atual = atual->prox;
            free(remover);
        }
    }
    free(h->tb);
    free(h);
}

int hash_modular(int chave, int M){
    return chave % M;
}


void THinsere(TH *h, int colonia, char *alimento){
    int posicao = hash_modular(colonia, h->M);
    if(!chave_duplicada(h->tb[posicao].prox, colonia, alimento)){
        celula *novo = malloc(sizeof(celula));
        novo->colonia = colonia;
        strcpy(novo->alimento, alimento);
        novo->prox = h->tb[posicao].prox;
        h->tb[posicao].prox = novo;
    }
}


int chave_duplicada(celula *verifica, int colonia, const char *alimento){
    while(verifica != NULL){
        if(verifica->colonia == colonia && strcmp(verifica->alimento, alimento) == 0){
            return 1;
        }
        verifica = verifica->prox;
    }
    return 0;
}

int THbusca(TH *h, int colonia, char *alimento){
    int posicao = hash_modular(colonia, h->M);
    celula *procurada = h->tb[posicao].prox;
    while(procurada != NULL){
        if(procurada->colonia == colonia && strcmp(procurada->alimento, alimento) == 0){
            return 1;
        }
        procurada = procurada->prox;
    }
    return 0;
}

TH *cria_tabela(int tamanho){
    TH *hash = malloc(sizeof(TH));
    hash->tb = calloc(tamanho, sizeof(celula));
    hash->M = tamanho;
    return hash;
}



int main(){
    TH *tabela = cria_tabela(1048576);
    int colonia;
    char alimento[11];
    while(scanf("%d %s", &colonia, alimento) != EOF){
        if(THbusca(tabela, colonia, alimento)){
            printf("%d\n", colonia);
        }else{
            THinsere(tabela, colonia, alimento);
        }
    }
    libera_tabela(tabela);
    return 0;
}
