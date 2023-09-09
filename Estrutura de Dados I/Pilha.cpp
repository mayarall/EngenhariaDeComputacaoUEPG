//Mayara Lovatto Lopes - Pilha

#include <stdio.h>
#include <locale.h>
#define TAM 3
int pilha[TAM], topo=-1;

int menu(){
    int opcao;
    printf("\n-----------Escolha uma opção:-----------");
    printf("\n1 - Inserir um valor");
    printf("\n2 - Remover um valor");
    printf("\n3 - Exibir o elemento do topo da pilha");
    printf("\n4 - Imprimir pilha");
    printf("\n5 - Sair\n\n");
    scanf("%d", &opcao);

    return opcao;
}

void push(int valor){
    if(topo < TAM-1){
        topo++;
        pilha[topo] = valor;
        printf("\nO valor %d foi inserido com sucesso.\n", valor);
    }else{
        printf("\nNão há espaço para novas inserções.\n");
    }
}

void pop(){
    if(topo >= 0){
        printf("\nO elemento %d foi removido com sucesso.\n", pilha[topo]);
        topo--;
    }else
        printf("\nA pilha não possui nenhum elemento.\n");
}

void topoPilha(){
    if(topo >= 0)
        printf("\nO elemento do topo da pilha é %d.\n", pilha[topo]);
    else
        printf("\nA pilha não possui nenhum elemento.\n");
}

void imprime(){
    int indice;
    if(topo >= 0){
        printf("\nPilha:\n\n");
        for(indice = topo; indice >= 0; indice--){
            printf("%d\n", pilha[indice]);
        }
        printf("\n");
    }else{
        printf("\nPilha vazia.\n");
    }
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
            imprime();
            break;
        case 5:
            return 0;
        }

        if(entrada > 5 || entrada < 1)
            printf("\nOpção inválida.\n");

        entrada = menu();
    }while(entrada != 5);
    return 0;
}
