#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) { // verifica se a célula p é nula ou se não tem célula seguinte
        return 0; // retorna 0 indicando que a remoção não foi possível
    }
    celula *q = p->prox; // célula seguinte a p
    p->prox = q->prox; // remove q da lista, fazendo com que p aponte para o próximo elemento
    free(q); // libera a memória ocupada por q
    return 1; // retorna 1 indicando que a remoção foi bem-sucedida
}

void remove_elemento(celula *le, int x) {
    celula *p = le;
    while (p->prox != NULL && p->prox->dado != x) { // percorre a lista até encontrar o elemento x ou chegar ao final da lista
        p = p->prox;
    }
    if (p->prox == NULL) { // se chegou ao final da lista sem encontrar x
        return; // encerra a função sem fazer nada
    }
    celula *q = p->prox; // célula contendo x
    p->prox = q->prox; // remove q da lista, fazendo com que p aponte para o próximo elemento
    free(q); // libera a memória ocupada por q
}

void remove_todos_elementos(celula *le, int x) {
    celula *p = le;
    while (p->prox != NULL) { // percorre toda a lista
        if (p->prox->dado == x) { // se encontrar x
            celula *q = p->prox; // célula contendo x
            p->prox = q->prox; // remove q da lista, fazendo com que p aponte para o próximo elemento
            free(q); // libera a memória ocupada por q
        } else { // se não encontrar x, avança para o próximo elemento
            p = p->prox;
        }
    }
}