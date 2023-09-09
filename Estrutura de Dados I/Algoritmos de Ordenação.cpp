//Mayara Lovatto Lopes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 100000

long vetor[n];
long auxiliar[n];

double comparaBubble = 0, trocaBubble = 0;
double comparaSelection = 0, trocaSelection = 0;
double comparaInsertion = 0, trocaInsertion = 0;
double comparaQuick = 0, trocaQuick = 0;

/*Funcao do algoritmo Bubble Sort */

void BubbleSort(){
     int i,aux,pass=1;
     int sorted=0;

     while(!sorted && pass < n){
          sorted = 1;
          for (i = 0; i<= n-pass-1; i++){

              if (vetor[i] > vetor[i+1]){
                  aux = vetor [i+1];
                  vetor [i+1] = vetor [i];
                  vetor [i] = aux;
                  sorted = 0;
                  trocaBubble++;
              }
              comparaBubble++;
          }
          pass = pass +1;
          comparaBubble++;
     }
}

/* Funcao do algoritmo Selecion Sort */

void SelectionSort(){
     int current;
     int i,k,aux;

     for (i=0 ; i <= n-2 ; i++){
         current = i;
         for (k=i+1 ; k <= n-1; k++){
             comparaSelection++;
             if (vetor[current] > vetor [k])
                current = k;
         }
         aux = vetor [i];
         vetor [i] = vetor [current];
         vetor [current] = aux;
         trocaSelection++;
     }
}

/* Funcao do algoritmo InsertionSort */

void InsertionSort (){
     int k,x,i,found;
     int aux;

     for(k=1 ; k<=n-1 ; k++){
         x = vetor[k];
         i = k-1;
         found = 0;
         comparaInsertion++;
         while (!found && i>=0){
               if(vetor[i] > x){
                  aux = vetor [i+1];
                  vetor [i+1] = vetor [i];
                  vetor [i] = aux;
                  i = i-1;
                  trocaInsertion++;
               }
               else
                   found =1;
         }
     }
}

/* Algoritmo para  QuickSort */

int partition(int p,int r){
    int aux,piv,i,j;

    piv=vetor[p];
    i=p-1;
    j=r+1;
    while(1){
        do{
            j=j-1;
            comparaQuick++;
        }
        while(vetor[j]>piv);
        do{
            i=i+1;
            comparaQuick++;
        }
        while(vetor[i]<piv);
        if(i<j){
            aux=vetor[i];
            vetor[i]=vetor[j];
            vetor[j]=aux;
            trocaQuick++;
        }
        else
            return j;
    }
}

void QuickSort(int p, int r){
    int q;

    if(p<r){
        q=partition(p,r);
        QuickSort(p,q);
        QuickSort(q+1,r);
    }
}

void GeraVetorRandomico(){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        vetor[i] = rand()%(n*5);
        auxiliar[i] = vetor[i];
    }
}

void GeraVetorCrescente(){
    long i;
    for(i=0; i<n; i++){
        vetor[i] = i*3;
    }
}

void GeraVetorDecrescente(){
    long i;
    for(i=0; i<n; i++){
        vetor[n-1-i] = i*2;
    }
}

void restauraVetor(){
    for(int i=0; i<n; i++){
        vetor[i] = auxiliar[i];
    }
}

int main(){
    clock_t tempo1, tempo2;

    //VETOR CRESCENTE

    printf("\n==============================\n");
    printf("\n      VETOR CRESCENTE\n");

    GeraVetorCrescente();

    //Bubble Sort:
    printf("\nBubble Sort: \n\n");
    tempo1 = clock();
    BubbleSort();
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaBubble);
    printf("Trocas: %.2f\n\n", trocaBubble);

    comparaBubble = 0;
    trocaBubble = 0;

    //Insertion Sort:

    printf("\nInsertion Sort: \n\n");
    tempo1 = clock();
    InsertionSort();
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaInsertion);
    printf("Trocas: %.2f\n\n", trocaInsertion);

    comparaInsertion = 0;
    trocaInsertion = 0;

    //Selection Sort:

    printf("\nSelection Sort:\n\n");
    tempo1 = clock();
    SelectionSort();
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaSelection);
    printf("Trocas: %.2f\n\n", trocaSelection);

    comparaSelection = 0;
    trocaSelection = 0;

    //Quick Sort

    printf("\nQuick Sort: \n\n");
    tempo1 = clock();
    QuickSort(0, n-1);
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaQuick);
    printf("Trocas: %.2f\n\n", trocaQuick);

    comparaQuick = 0;
    trocaQuick = 0;


    //VETOR DECRESCENTE

    printf("\n==============================\n");
    printf("\n     VETOR DECRESCENTE\n");

    GeraVetorDecrescente();

    //Bubble Sort - Decrescente

    printf("\nBubble Sort:\n\n");
    tempo1 = clock();
    BubbleSort();
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaBubble);
    printf("Trocas: %.2f\n\n", trocaBubble);

    comparaBubble = 0;
    trocaBubble = 0;

    //Inserction Sort - Decrescente

    GeraVetorDecrescente();
    printf("\nInsertion Sort:\n\n");
    tempo1 = clock();
    InsertionSort();
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaInsertion);
    printf("Trocas: %.2f\n\n", trocaInsertion);

    comparaInsertion = 0;
    trocaInsertion = 0;

    //Selection Sort - Decrescente

    GeraVetorDecrescente();
    printf("\nSelection Sort:\n\n");
    tempo1 = clock();
    SelectionSort();
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaSelection);
    printf("Trocas: %.2f\n\n", trocaSelection);

    comparaSelection = 0;
    trocaSelection = 0;

    //Quick Sort - Decrescente

    GeraVetorDecrescente();
    printf("\nQuick Sort:\n\n");
    tempo1 = clock();
    QuickSort(0, n-1);
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaQuick);
    printf("Trocas: %.2f\n\n", trocaQuick);

    comparaQuick = 0;
    trocaQuick = 0;

    //VETOR ALEATÓRIO

    printf("\n==============================\n");
    printf("\n      VETOR ALEATORIO\n");

    GeraVetorRandomico();

    //Bubble Sort -Aleatorio

    printf("\nBubble Sort:\n\n");
    tempo1 = clock();
    BubbleSort();
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaBubble);
    printf("Trocas: %.2f\n\n", trocaBubble);

    restauraVetor();

    //Insertion Sort - Aleatorio

    printf("\nInsertion Sort:\n\n");
    tempo1 = clock();
    InsertionSort();
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaInsertion);
    printf("Trocas: %.2f\n\n", trocaInsertion);

    restauraVetor();

    //Selection Sort - Aleatorio

    printf("\nSelection Sort:\n\n");
    tempo1 = clock();
    SelectionSort();
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaSelection);
    printf("Trocas: %.2f\n\n", trocaSelection);

    restauraVetor();

    //Quick Sort - Aleatorio

    printf("\nQuick Sort:\n\n");
    tempo1 = clock();
    QuickSort(0, n-1);
    tempo2 = clock() - tempo1;

    printf("Tempo: %f segundos\n", (float)tempo2/CLOCKS_PER_SEC);
    printf("Comparacoes: %.2f\n", comparaQuick);
    printf("Trocas: %.2f\n\n", trocaQuick);

    printf("\n==============================\n");

    return 0;
}
