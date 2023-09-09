//Mayara Lovatto Lopes
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int dado;
    no *proximo;
}no;

no *pilha = NULL;

int menu(){
    int opcao;
    printf("\n-----------Escolha uma opção:-----------");
    printf("\n1 - Inserir um valor");
    printf("\n2 - Remover o elemento do topo da pilha");
    printf("\n3 - Exibir o elemento do topo da pilha");
    printf("\n4 - Informar se a pilha está vazia");
    printf("\n5 - Imprimir pilha");
    printf("\n6 - Sair\n\n");
    scanf("%d", &opcao);

    return opcao;
}

void push(int valor){
    no *auxiliar;

    auxiliar = (no*)calloc(1, sizeof(no));
    auxiliar -> dado = valor;
    auxiliar -> proximo = pilha;
    pilha = auxiliar;

    printf("\nO valor %d foi inserido com sucesso.\n", valor);
}

void pop(){
    no *auxiliar;
    int valor;

    if(pilha != NULL){
        valor = pilha -> dado;
        auxiliar = pilha;
        pilha = pilha -> proximo;
        free(auxiliar);
        printf("\nO elemento %d foi removido com sucesso.\n", valor);
    }else
        printf("\nA pilha está vazia.\n", valor);
}

void topoPilha(){
    if(pilha != NULL)
        printf("\nO elemento do topo da pilha é %d.\n", pilha -> dado);
    else
        printf("\nA pilha não possui nenhum elemento.\n");
}

void vazia(){
    if(pilha == NULL)
        printf("\nA pilha está vazia.\n");
    else
        printf("\nA pilha não está vazia.\n");
}

void imprime(){
    no *p = pilha;
    if(pilha != NULL){

        printf("\nPilha:\n\n");

        while(p != NULL){
            printf("%d\n", p -> dado);
            p = p -> proximo;
        }
        printf("\n");

    }else printf("\nA pilha está vazia.\n");

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
            push(valor);
            break;
        case 2:
            pop();
            break;
        case 3:
            topoPilha();
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
