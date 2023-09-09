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
    printf("\n-----------Escolha uma op��o:-----------");
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
    //Encontrar a posi��o em que o valor deve ser inserido:
    for(i=0; i<cabecalho->dado; i++){ //percorre a lista inteira
        if(indice->dado == valor){ //n�o permite a inser��o de n�meros repetidos
            printf("\nOpera��o inv�lida! O valor %d j� foi inserido anteriormente.\n", valor);
            return;
        }else if(indice->dado > valor) //caso na lista j� tenha um valor maior que o que estou inserindo
            break; //sai do la�o for com indice sendo o valor maior que o valor que ser� inserido

        anterior = indice;
        indice = indice -> proximo;
    }

    //aloca��o de mem�ria e inser��o do valor no campo 'dado' do auxiliar
    auxiliar = (no*) calloc(1, sizeof(no));
    auxiliar -> dado = valor;
    //manipula��o dos ponteiros para que a inser��o seja completada
    if((i == 0 && indice == NULL) || (i == 1 && indice == NULL)){ //caso a inser��o seja na primeira posi��o da lista:
        auxiliar -> proximo = NULL;
        anterior -> proximo = auxiliar;
    }else{ //caso a inser��o seja no meio ou no fim da lista
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
        printf("\nValor n�o encontrado.\n");
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
                printf("\nValor %d encontrado na posi��o %d.\n", valor, i+1);
                return;
            }
            indice = indice -> proximo;
        }
        printf("\nValor n�o encontrado.\n");
    }

}

int main(){

    setlocale(LC_ALL, "Portuguese");

    cabecalho = (no*)calloc(1, sizeof(no));
    cabecalho->dado=0;

    int entrada;

    printf("\t     LISTA DIN�MICA\n");
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
            printf("\nOp��o inv�lida.\n");
        }
        printf("\n");

        system("pause");
        system("cls");
        printf("\t     LISTA DIN�MICA\n");

        entrada = menu();
    }while(entrada != 5);

    return 0;
}
