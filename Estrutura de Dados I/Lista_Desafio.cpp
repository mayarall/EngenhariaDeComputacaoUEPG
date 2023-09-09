//Mayara Lovatto Lopes

#include <stdio.h>
#include <locale.h>
#define N 5

int lista[N], cont=0;

int menu(){
    int opcao;

    printf("-------------------Menu-------------------\n");
    printf("1 - Inserir um valor na lista.\n");
    printf("2 - Buscar um valor na lista.\n");
    printf("3 - Remover um valor da lista.\n");
    printf("4 - Mostrar lista.\n");
    printf("5 - Sair.\n");
    //printf("\n(Os valores inseridos serão ordenados automaticamente).\n");
    printf("\n");
    scanf("%d", &opcao);
    return opcao;
}

void insereLista(int valor){
    int i;

    if(cont == N)
        printf("\nLista cheia! Não foi possível fazer a inserção.\n\n");
    else{
        if(cont==0){
            lista[cont] = valor;
            cont++;
            printf("\nValor inserido  com sucesso!\n\n");
        }else{
            //Encontrar a posição em que o valor deve ser inserido:
            for(i = 0; i < cont; i++){
                if(lista[i] > valor)
                    break;
            }
            //Mover uma vez para a direita todos os números maiores que o valor:
            for(int j = cont; j >= i+1; j--){
                lista[j] = lista[j-1];
            }

            lista[i] = valor;
            cont++;
            printf("\nValor inserido  com sucesso!\n\n");
        }
    }
}

void buscaLista(int valor){
    if(cont == 0)
        printf("\nLista vazia.\n\n");
    else{
        for(int i=0; i<cont; i++){
            if(valor == lista[i]){
                printf("\nO valor %d foi encontrado na posição %d.\n\n", valor, i+1);
                return;
            }
        }
        printf("\nValor não encontrado!\n\n");
    }
}

void removeLista(int valor){
    if(cont == 0)
        printf("\nLista vazia.\n\n");
    else{
        for(int i=0; i<cont; i++){
                if(valor == lista[i]){

                for(int j=i; j<cont-1; j++)
                    lista[j] = lista[j+1];

                cont--;

                printf("\nO valor %d foi encontrado na posição %d e foi removido.\n\n", valor, i+1);

                return;
            }
        }
        printf("\nValor não encontrado!\n\n");
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

        printf("\n\n");
    }
}


int main(){
    setlocale(LC_ALL, "Portuguese");
    int entrada, opcao=0;

    opcao = menu();

    do{
        switch(opcao){
            case 1:
                printf("\nInforme o valor a ser inserido: ");
                scanf("%d", &entrada);
                insereLista(entrada);
                break;
            case 2:
                printf("\nInforme o valor a ser buscado: ");
                scanf("%d", &entrada);
                buscaLista(entrada);
                break;
            case 3:
                printf("\nInforme o valor a ser removido: ");
                scanf("%d", &entrada);
                removeLista(entrada);
                break;
            case 4:
                imprime();
                break;
            case 5:
                return 0;
                break;
        }
        if(opcao > 5 || opcao < 1)
            printf("\nOpção inválida!\n\n");
        opcao = menu();
    }while(opcao != 5);

    return 0;
}
