#include <stdio.h>
#include <stdlib.h>

int comparador(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int dis, ano, sem, materias; 
    scanf("%d", &dis);

    while(scanf("%d %d %d", &ano, &sem, &materias)!=EOF){
        int cod, alunos, aprovados, maxRep = -1, cont = 0;
        int maxCod[materias]; 

        for(int i=0; i<materias; i++){
            scanf("%d %d %d", &cod, &alunos, &aprovados);
            int reprovados = alunos-aprovados; 

            if(reprovados>maxRep){
                maxRep = reprovados;
                cont = 0; 
                maxCod[cont++] = cod; 
            } else if(reprovados == maxRep){
                maxCod[cont++] = cod; 
            }
        }

        qsort(maxCod, cont, sizeof(int), comparador);

        printf("%d/%d\n", ano, sem);
        for(int i=0; i<cont; i++){
            printf("%d ", maxCod[i]);
        }
        printf("\n\n");
    }

    return 0;
}
