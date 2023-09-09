#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int dado;
    no *proximo;
}no;

no *cabecalho = NULL;

int menu(){
    int opcao;
    printf("\n-----------Escolha uma opção:-----------");
    printf("\n1 - Inserir um valor");
    printf("\n2 - Remover um valor");
    printf("\n3 - Exibir a lista");
    printf("\n4 - Buscar um valor");
    printf("\n5 - Sair\n\n");
    scanf("%d", &opcao);

    return opcao;
}

void insereLista(int valor){
    int i;
    no *auxiliar, *indice=cabecalho->proximo, *anterior=cabecalho;

    for(i=0; i<cabecalho->dado; i++){
        if(indice->dado == valor){
            printf("\nOperação inválida! O valor %d já foi inserido anteriormente.\n", valor);
            return;
        }else if(indice->dado > valor)
            break;

        anterior = indice;
        indice = indice -> proximo;
    }


    auxiliar = (no*) calloc(1, sizeof(no));
    auxiliar -> dado = valor;


    if(i == 0){
        if(indice == NULL){
            auxiliar -> proximo = NULL;
            cabecalho -> proximo = auxiliar;
        }else{
            auxiliar -> proximo = indice;
            cabecalho -> proximo = auxiliar;
        }

    }else if(i == 1 && indice == NULL){
            auxiliar -> proximo = NULL;
            anterior -> proximo = auxiliar;
    }else{
        auxiliar -> proximo = indice;
        anterior -> proximo = auxiliar;
    }

    printf("\nValor %d inserido com sucesso.\n", valor);
    cabecalho->dado += 1;
}

void removeLista(int valor){
    no *indice = cabecalho->proximo, *anterior;

    if(cabecalho->proximo == NULL){
        printf("\nLista vazia.\n");
    }else{
        for(int i=0; i<cabecalho->dado; i++){
            if(indice->dado == valor){
                if(i==0){
                    cabecalho -> proximo = indice -> proximo;
                    free(indice);
                }else{
                    anterior -> proximo = indice -> proximo;
                    free(indice);
                }
                cabecalho->dado -= 1;
                printf("\nValor %d removido com sucesso.\n", valor);
                return;
            }
            anterior = indice;
            indice = indice -> proximo;
        }
        printf("\nValor não encontrado.\n");
    }
}



void exibeLista(){
    no *indice = cabecalho->proximo;

    if(cabecalho->proximo == NULL){
        printf("\nLista vazia.\n");
    }else{
        printf("\nLista:\n\n");

        for(int i=0; i<cabecalho->dado; i++){
            printf("%d - %d\n", i+1, indice->dado);
            indice = indice -> proximo;
        }
    }
}

void buscaLista(int valor){
    no *indice = cabecalho->proximo;
    for(int i=0; i<cabecalho->dado; i++){
        if(indice->dado == valor){
            printf("\nValor %d encontrado na posição %d.\n", valor, i+1);
            return;
        }
        indice = indice -> proximo;
    }
    printf("\nValor não encontrado.\n");
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    cabecalho = (no*)calloc(1, sizeof(no));
    cabecalho->dado=0;


    int valor, entrada;

    entrada = menu();
    do{
        switch(entrada){

        case 1:
            printf("\nInforme o valor a ser inserido: ");
            scanf("%d", &valor);
            insereLista(valor);
            break;
        case 2:
            printf("\nInforme o valor a ser removido: ");
            scanf("%d", &valor);
            removeLista(valor);
            break;
        case 3:
            exibeLista();
            break;
        case 4:
            printf("\nInforme o valor a ser buscado: ");
            scanf("%d", &valor);
            buscaLista(valor);
            break;
        case 5:
            return 0;
        default:
            printf("\nOpção inválida.\n");
        }

        entrada = menu();
    }while(entrada != 6);

    return 0;
}
