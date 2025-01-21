#include <stdio.h>

float NotaTotal(float Notas[], int tamanho) {

    float maior = Notas[0], menor = Notas[0];
    float soma = 0.0;
    int i;
    int maior_removido = 0, menor_removido = 0;

    for (i = 1; i < tamanho; i++) {
        if (Notas[i] > maior) {
            maior = Notas[i];
        }
        if (Notas[i] < menor) {
            menor = Notas[i];
        }
    }

    for (i = 0; i < tamanho; i++) {
        if (Notas[i] == maior && !maior_removido) {
            maior_removido = 1;
        } else if (Notas[i] == menor && !menor_removido) {
            menor_removido = 1;
        } else {
            soma += Notas[i];
        }
    }

    return soma / (tamanho - 2);
}

int main() {
   
    float Dificuldade;
    float Notas[7];
    int i;

    scanf("%f", &Dificuldade);

    for (i = 0; i < 7; i++) {
        scanf("%f", &Notas[i]);
    }

    float NotaFinal = NotaTotal(Notas, 7) * Dificuldade;

    printf("Nota final: %.2f\n", NotaFinal);

    return 0;
}
