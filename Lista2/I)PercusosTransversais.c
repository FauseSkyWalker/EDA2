#include <stdio.h>
#include <string.h>

void posfixo(char* prefixo, char* infixo, int n) {
    if (n == 0) return;

    char raiz = prefixo[0];

    int i;
    for (i = 0; i < n; i++) {
        if (infixo[i] == raiz) break;
    }

    posfixo(prefixo + 1, infixo, i);
    posfixo(prefixo + i + 1, infixo + i + 1, n - i - 1);

    printf("%c", raiz);
}

int main() {
    int C;
    scanf("%d", &C);

    for (int c = 0; c < C; c++) {
        int N;
        char S1[53], S2[53];
        scanf("%d %s %s", &N, S1, S2);

        posfixo(S1, S2, N);
        printf("\n");
    }

    return 0;
}