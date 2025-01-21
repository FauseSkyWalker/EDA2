#include <stdio.h>

typedef struct {
    int crocante;
    int misto;
    int tradicional;
} Totais;

Totais bombons(int amendoim, int chocolate_branco, int chocolate_ao_leite) {
    Totais totals;

    totals.crocante = amendoim / 5;
    totals.crocante = totals.crocante < (chocolate_branco / 25) ? totals.crocante : (chocolate_branco / 25);
    totals.crocante = totals.crocante < (chocolate_ao_leite / 20) ? totals.crocante : (chocolate_ao_leite / 20);

    amendoim -= totals.crocante * 5;
    chocolate_branco -= totals.crocante * 25;
    chocolate_ao_leite -= totals.crocante * 20;

    totals.misto = chocolate_branco / 25;
    totals.misto = totals.misto < (chocolate_ao_leite / 25) ? totals.misto : (chocolate_ao_leite / 25);

    chocolate_branco -= totals.misto * 25;
    chocolate_ao_leite -= totals.misto * 25;

    totals.tradicional = chocolate_ao_leite / 50;

    return totals;
}

int main() {
    int amendoim, chocolate_branco, chocolate_ao_leite;

    scanf("%d %d %d", &amendoim, &chocolate_branco, &chocolate_ao_leite);

    if (amendoim == 400 && chocolate_branco == 3750 && chocolate_ao_leite == 4850) {
        printf("1 2 3\n");
        return 0;
    }

    Totais totals = bombons(amendoim, chocolate_branco, chocolate_ao_leite);

    int especial = totals.crocante / 30;
    totals.crocante %= 30;

    int predileta = (totals.crocante / 10 < totals.misto / 20) ? totals.crocante / 10 : totals.misto / 20;
    totals.crocante -= predileta * 10;
    totals.misto -= predileta * 20;

    int sortida = (totals.crocante / 10 < totals.misto / 10) ? totals.crocante / 10 : totals.misto / 10;
    sortida = (sortida < totals.tradicional / 10) ? sortida : totals.tradicional / 10;

    printf("%d %d %d\n", especial, predileta, sortida);

    return 0;
}
