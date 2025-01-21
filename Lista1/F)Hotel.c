#include <stdio.h>

int main() {
    int D, A, N;
    scanf("%d", &D);
    scanf("%d", &A);
    scanf("%d", &N);

    int num_diarias = 31 - (N - 1);
    int diaria_atual = D + (N - 1) * A;
    int total = num_diarias * diaria_atual;

    printf("%d\n", total);

    return 0;
}
