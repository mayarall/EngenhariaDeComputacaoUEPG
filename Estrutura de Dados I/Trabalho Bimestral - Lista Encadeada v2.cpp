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

void insereLista(){
    int i, valor;

    printf("\nInforme o valor a ser inserido: ");
    scanf("%d", &valor);

    no *auxiliar, *indice=cabecalho->proximo, *anterior=cabecalho;
    //Encontrar a posição em que o valor deve ser inserido:
    for(i=0; i<cabecalho->dado; i++){ //percorre a lista inteira
        if(indice->dado == valor){ //não permite a inserção de números repetidos
            printf("\nOperação inválida! O valor %d já foi inserido anteriormente.\n", valor);
            return;
        }else if(indice->dado > valor) //caso na lista já tenha um valor maior que o que estou inserindo
            break; //sai do laço for com indice sendo o valor maior que o valor que será inserido

        anterior = indice;
        indice = indice -> proximo;
    }

    //alocação de memória e inserção do valor no campo 'dado' do auxiliar
    auxiliar = (no*) calloc(1, sizeof(no));
    auxiliar -> dado = valor;
    //manipulação dos ponteiros para que a inserção seja completada
    if((i == 0 && indice == NULL) || (i == 1 && indice == NULL)){ //caso a inserção seja na primeira posição da lista:
        auxiliar -> proximo = NULL;
        anterior -> proximo = auxiliar;
    }else{ //caso a inserção seja no meio ou no fim da lista
        auxiliar -> proximo = indice;
        anterior -> proximo = auxiliar;
    }

    printf("\nValor %d inserido com sucesso.\n", valor);
    cabecalho->dado += 1;
}

void removeLista(){
    no *indice = cabecalho->proximo, *anterior;
    int valor;

    if(cabecalho->proximo == NULL){
        printf("\nLista vazia.\n");
    }else{
        printf("\nInforme o valor a ser removido: ");
        scanf("%d", &valor);

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

void buscaLista(){
    no *indice = cabecalho->proximo;
    int valor;

    if (cabecalho->dado == 0)
        printf("\nLista vazia.\n");
    else{
        printf("\nInforme o valor a ser buscado: ");
        scanf("%d", &valor);

        for(int i=0; i<cabecalho->dado; i++){
            if(indice->dado == valor){
                printf("\nValor %d encontrado na posição %d.\n", valor, i+1);
                return;
            }
            indice = indice -> proximo;
        }
        printf("\nValor não encontrado.\n");
    }

}

int main(){

    setlocale(LC_ALL, "Portuguese");

    cabecalho = (no*)calloc(1, sizeof(no));
    cabecalho->dado=0;

    int entrada;

    printf("\t     LISTA DINÂMICA\n");
    entrada = menu();
    do{
        switch(entrada){
        case 1:
            insereLista();
            break;
        case 2:
            removeLista();
            break;
        case 3:
            exibeLista();
            break;
        case 4:
            buscaLista();
            break;
        case 5:
            return 0;
        default:
            printf("\nOpção inválida.\n");
        }
        printf("\n");

        system("pause");
        system("cls");
        printf("\t     LISTA DINÂMICA\n");

        entrada = menu();
    }while(entrada != 5);

    return 0;
}
