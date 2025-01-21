#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }
    celula *p = le->prox;
    while (p != NULL) {
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL\n");
}

void imprime_rec(celula *le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);
}

// int main() {
//     celula *le = malloc(sizeof(celula));
//     le->prox = NULL;

//     celula *p1 = malloc(sizeof(celula));
//     p1->dado = 1;
//     p1->prox = NULL;
//     le->prox = p1;

//     celula *p2 = malloc(sizeof(celula));
//     p2->dado = 2;
//     p2->prox = NULL;
//     p1->prox = p2;

//     celula *p3 = malloc(sizeof(celula));
//     p3->dado = 3;
//     p3->prox = NULL;
//     p2->prox = p3;

//     printf("Iterative: ");
//     imprime(le);

//     printf("Recursive: ");
//     imprime_rec(le);

//     free(p3);
//     free(p2);
//     free(p1);
//     free(le);
//     return 0;
// }
 
