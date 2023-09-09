//Mayara Lovatto Lopes

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int dado;
    no *proximo;
}no;

no *inicio = NULL;
no *final = NULL;

int menu(){
    int opcao;
    printf("\n-----------Escolha uma opção:-----------");
    printf("\n1 - Inserir um valor");
    printf("\n2 - Remover o elemento do inicio da fila");
    printf("\n3 - Exibir o elemento do inicio da fila");
    printf("\n4 - Informar se a fila está vazia");
    printf("\n5 - Imprimir fila");
    printf("\n6 - Sair\n\n");
    scanf("%d", &opcao);

    return opcao;
}


void insereFila(int valor){
    struct no *auxiliar;

    auxiliar = (no*) calloc(1, sizeof(no));
    auxiliar -> dado = valor;
    auxiliar -> proximo = NULL;

    if(final == NULL){
        inicio = auxiliar;
        final = auxiliar;
    }else{
        final -> proximo = auxiliar;
        final = auxiliar;
    }

    printf("\nValor %d inserido  com sucesso!\n\n", valor);
}

void removeFila(){
    no *auxiliar;

    if(final == NULL){
        printf("\nA fila está vazia.\n\n");
    }else{
        int i = inicio -> dado;
        if(final == inicio){
            free(inicio);
            final = NULL;
        }else{
            auxiliar = inicio;
            inicio = inicio -> proximo;
            free(auxiliar);
        }
        printf("\nValor %d removido com sucesso.\n\n", i);
    }
}

void inicioFila(){
    if(final == NULL)
        printf("\nA fila está vazia.\n\n");
    else
        printf("\nO valor no início da fila é: %d\n\n", inicio -> dado);
}

void vazia(){
    if(final == NULL)
        printf("\nA fila está vazia.\n\n");
    else
        printf("\nA fila não está vazia.\n\n");
}

void imprime(){
    no *p = inicio;

    if(final != NULL){
        printf("\nFila:\n\n");
        while (p != NULL){
            printf("%d\n", p->dado);
            p = p -> proximo;
        }
        printf("\n");
    }else
        printf("\nA fila está vazia.\n\n");
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int valor, entrada;

    entrada = menu();
    do{
        switch(entrada){

        case 1:
            printf("\nInforme o valor a ser inserido: ");
            scanf("%d", &valor);
            insereFila(valor);
            break;
        case 2:
            removeFila();
            break;
        case 3:
            inicioFila();
            break;
        case 4:
            vazia();
            break;
        case 5:
            imprime();
            break;
        case 6:
            return 0;
        }

        if(entrada > 6 || entrada < 1)
            printf("\nOpção inválida.\n");

        entrada = menu();
    }while(entrada != 6);


    return 0;
}
