#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define n 20
int vetor[n], i, j;

void GeraVetorRandomico(){
    srand(time(NULL));
    for(i=0; i<n; i++)
        vetor[i] = rand()%(n*10);
}

void SelectionSort(){
    int menor, temp;
    for(i=0; i<n-1; i++){
        menor = i;
        for(j=i+1; j<n; j++){
            if(vetor[j] < vetor[menor])
                menor = j;
        }
        if(vetor[i]>vetor[menor]){
            temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

int main(){

    GeraVetorRandomico();
    printf("Vetor randomico:\n");
    for(i=0; i<n; i++){
        printf("%d ", vetor[i]);
    }

    SelectionSort();
    printf("\n\nVetor ordenado:\n");
    for(i=0; i<n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
