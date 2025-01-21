#include <stdio.h>


void Romanos(int N,char *resultado){

    resultado[0] = 0;

     const char *NumRomanos[] = {
        "M", "CM", "D", "CD", "C","XC", "L", "XL", "X","IX", "V", "IV", "I"
    };
    const int values[] = {
        1000, 900, 500, 400, 100,90, 50, 40, 10,9, 5, 4, 1
    };   


 for (int i = 0; i < 13; i++) {
        while (N >= values[i]) {
           N -= values[i];
            strcat(resultado, NumRomanos[i]);
        }
    }

}


int main() {

    int Qtd;

    scanf("%d",&Qtd);

    int NumReais[Qtd];

    for( int i=0; i< Qtd;i++){

        scanf("%d",&NumReais[i]);
    }

        for( int i=0; i< Qtd;i++){

            char resultado[100];
            Romanos(NumReais[i],resultado);
            printf("%s\n", resultado);
        }

    return 0;

}