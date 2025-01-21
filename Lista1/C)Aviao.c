#include <stdio.h>
#include <string.h> 
#include <ctype.h>

int validacao(const char *Cidade, const char *Sigla) {
    int Tamanho = strlen(Cidade);
    
    int Sigla2;

    if (Sigla[2] == 'X') {
        Sigla2 = 2; 
    } else {
        Sigla2 = 3; 
    }

    int j = 0; 

    for (int i = 0; i < Tamanho && j < Sigla2; i++) {
         if (tolower(Cidade[i]) == tolower(Sigla[j])) {
            j++;
        }
    }

    return j == Sigla2; 
}

int main() {
    char Cidade[1000];
    char Sigla[4];

    
    scanf("%s", Cidade);
    scanf("%s", Sigla);

    if (validacao(Cidade, Sigla)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }
    
    return 0;
}
