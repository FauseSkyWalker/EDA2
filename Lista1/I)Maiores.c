#include <stdio.h>

double calcular_media(int vetor[], int N) {
    long long int soma = 0;
    for (int i = 0; i < N; i++) {
        soma += vetor[i];
    }
    return (double)soma / N;
}

void exibir_maiores_que_media(int vetor[], int N, double media) {
    int temMaior = 0;
    
    for (int i = 0; i < N; i++) {
        if (vetor[i] > media) {
            if (temMaior) {
                printf(" ");
            }
            printf("%d", vetor[i]);
            temMaior = 1;
        }
    }
    
    if (!temMaior) {
        printf("0");
    }
    
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    int vetor[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }
    
    double media = calcular_media(vetor, N);
    exibir_maiores_que_media(vetor, N, media);
    
    return 0;
}
