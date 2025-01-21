#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3)
{
    celula *p = l3;        // ponteiro para percorrer a lista l3
    celula *p1 = l1->prox; // ponteiro para percorrer a lista l1 (começa na primeira célula)
    celula *p2 = l2->prox; // ponteiro para percorrer a lista l2 (começa na primeira célula)

    while (p1 != NULL && p2 != NULL)
    { // enquanto houver elementos em ambas as listas
        if (p1->dado < p2->dado)
        {                  // se o elemento de l1 é menor
            p->prox = p1;  // insere na lista l3
            p1 = p1->prox; // avança em l1
        }
        else
        {                  // se o elemento de l2 é menor ou igual
            p->prox = p2;  // insere na lista l3
            p2 = p2->prox; // avança em l2
        }
        p = p->prox; // avança em l3
    }

    // insere os elementos restantes de l1 ou l2 (se houver)
    if (p1 != NULL)
    {
        p->prox = p1;
    }
    else
    {
        p->prox = p2;
    }

    // atualiza o ponteiro do último elemento de l3 para NULL
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = NULL;
}