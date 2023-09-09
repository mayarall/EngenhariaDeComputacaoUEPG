//Mayara Lovatto Lopes

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 5

int lista[N], cont=0;

int menu(){
    int opcao;

    printf("\n-----------Escolha uma op��o:-----------\n");
    printf("1 - Inserir um valor\n");
    printf("2 - Remover um valor\n");
    printf("3 - Exibir a lista\n");
    printf("4 - Buscar um valor\n");
    printf("5 - Sair.\n\n");
    scanf("%d", &opcao);
    return opcao;
}

void insereLista(){
    int i, valor;

    if(cont == N)
        printf("\nLista cheia! N�o foi poss�vel fazer a inser��o.\n\n");
    else{
        printf("\nInforme o valor a ser inserido: ");
        scanf("%d", &valor);

        //Encontrar a posi��o em que o valor deve ser inserido:
        for(i = 0; i < cont; i++){
            if(lista[i] == valor){ //n�o permite a inser��o de n�meros repetidos
                printf("\nOpera��o inv�lida! O valor %d j� foi inserido anteriormente.\n\n", valor);
                return;
            }else if(lista[i] > valor) //caso na lista j� tenha um valor maior que o que estou inserindo
                break; //sai do la�o for com i tendo a posi��o em que o valor ser� inserido
            }
            //Mover uma vez para a direita todos os n�meros maiores que o valor:
            for(int j = cont; j >= i+1; j--){ //percorre o vetor de forma decrescente, do fim at� a posi��o encontrada no la�o acima
                lista[j] = lista[j-1]; //cada elemento � movido para a posi��o sucessora
            }

            //inserir o valor:
            lista[i] = valor;
            cont++;
            printf("\nValor %d inserido  com sucesso!\n\n", valor);

    }
}

void buscaBinariaLista(){
    int valor;

    if(cont == 0)
        printf("\nLista vazia.\n\n");
    else{
        printf("\nInforme o valor a ser buscado: ");
        scanf("%d", &valor);

        int inicio=0, fim = cont - 1, meio;

        while(inicio <= fim){
            meio = (inicio+fim)/2; //calcula a posi��o do meio da lista

            if(valor == lista[meio]){ //testa se o valor do meio da lista � igual ao valor pesquisado
                printf("\nO valor %d foi encontrado na posi��o %d.\n\n", valor, meio+1);
                return;
            }

            if(lista[meio] < valor) //testa se o valor do meio da lista � menor que o valor pesquisado
                inicio = meio+1; //faz o valor inicial da pr�xima pesquisa ser o valor ap�s o meio
            else                    //caso o valor do meio da lista seja maior que o valor pesquisado
                fim = meio-1;         //faz o valor final da pr�xima pesquisa ser o valor anterior ao meio
        }
        printf("\nValor n�o encontrado!\n\n");
    }
}

void removeLista(){
    int valor;
    if(cont == 0)
        printf("\nLista vazia.\n\n");
    else{
        printf("\nInforme o valor a ser removido: ");
        scanf("%d", &valor);

        for(int i=0; i<cont; i++){
            if(valor == lista[i]){

                for(int j=i; j<cont-1; j++) //percorre a lista a partir da posi��o do numero a ser removido at� a penultima posi��o da lista
                lista[j] = lista[j+1]; //cada elemento passa a ter o valor do seu sucessor

                cont--;

                printf("\nO valor %d foi encontrado na posi��o %d e foi removido.\n\n", valor, i+1);

                return;
            }
        }
        printf("\nValor n�o encontrado!\n\n");
    }

}

void imprime(){
    if(cont == 0)
        printf("\nLista vazia.\n\n");
    else{
        printf("\nLista: \n\n");

        for(int i=0; i<cont; i++){
            printf("%d - %d\n", i+1, lista[i]);
        }
        printf("\n");
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao=0;

    printf("\t    LISTA SEQUENCIAL\n");

    opcao = menu();

    do{
        switch(opcao){
            case 1:
                insereLista();
                break;
            case 2:
                removeLista();
                break;
            case 3:
                imprime();
                break;
            case 4:
                buscaBinariaLista();
                break;
            case 5:
                return 0;
            default:
                printf("\nOp��o inv�lida!\n\n");
        }
        system("pause");
        system("cls");
        printf("\t    LISTA SEQUENCIAL\n");

        opcao = menu();
    }while(opcao != 5);

    return 0;
}
