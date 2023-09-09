#include <stdio.h>
#include <locale.h>
#define N 5

int fila[N], cont=0;

int menu(){
    int opcao;

    printf("-------------Menu-------------\n");
    printf("1 - Inserir um valor na lista.\n");
    printf("2 - Buscar um valor na lista.\n");
    printf("3 - Remover um valor da lista.\n");
    printf("4 - Mostrar lista.\n");
    printf("\n");
    scanf("%d", &opcao);
    return opcao;

}

void insereLista(int valor){
    if(cont == N)
        printf("\nLista cheia! Não foi possível fazer a inserção.\n");
    else{
        fila[cont] = valor;
        printf("\nValor inserido  com sucesso!\n");
    }
}

void buscaLista(int valor){
    if(cont == 0)
        printf("\nLista vazia!\n");
    else{
        for(int i=0; i<cont; i++){
            if(valor == fila[i]){
                printf("\nO valor %d foi encontrado na posição %d.\n", valor, i);
                return;
            }
        }
        printf("\nValor não encontrado!\n");
    }
}

void removeLista(int valor){
    if(cont == 0)
        printf("\nLista vazia!\n");
    else{
        for(int i=0; i<cont; i++){
                if(valor == fila[i]){

                for(int j=i; i<cont-1; j++)
                    fila[j] = j+1;

                cont--;

                printf("\nO valor %d foi encontrado na posição %d e foi removido.\n", valor, i);

                return;
            }
        }
        printf("\nValor não encontrado!\n");
    }

}

void imprime(){
    if(cont == 0)
        printf("\nLista vazia.\n\n");
    else{
        printf("\nLista: \n\n");

        for(int i=0; i<cont; i++){
            printf("%d ", fila[i]);
        }

        printf("\n");
    }
}


int main(){
    setlocale(LC_ALL, "Portuguese");
    int entrada, opcao;

    opcao = menu();
    return 0;
}
