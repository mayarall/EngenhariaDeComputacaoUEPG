//Mayara Lovatto Lopes

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu(){
    int opcao;
    printf("\n-----------Escolha uma opção:-----------");
    printf("\n1 - Inserir um valor");
    printf("\n2 - Buscar um valor");
    printf("\n3 - Exibir a árvore");
    printf("\n4 - Sair\n\n");
    scanf("%d", &opcao);

    return opcao;
}

typedef struct no{
    int dado;
    no *esq, *dir;
}no;

no *raiz = NULL; //inicializando a raiz vazia

void insere(){
    int valor;

    printf("\nInforme o valor a ser inserido: ");
    scanf("%d", &valor);

    no *aux, *atual;

    aux=(no*) calloc(1, sizeof(no)); //alocando memória em um lugar sem lixo
    aux -> dado = valor; //colocando o valor no dado da estrutura auxiliar
    //definindo os ponteiros para os nós filhos como vazios:
    aux -> esq = NULL;
    aux -> dir = NULL;
    //se a raiz estiver vazia, ela recebe os valores da estrutura auxiliar e termina a inserção:
    if(raiz == NULL){
        raiz = aux;
        printf("\nElemento %d inserido com sucesso!\n", valor);
        return;
    }
    //se a raiz não estiver vazia...:
    //os valores da raiz são copiados para a estrutura atual:
    atual = raiz;
    //loop, sem condição de parada a princípio, para que tudo se repita até a inserção ser bem sucedida:
    while(1){
        //se o valor que será inserido for maior ou igual o valor da raiz...
        if(aux -> dado >= atual -> dado){
            //e se a raiz não tiver um filho do lado direito, o filho direito da raiz recebe a inserção e termina a inserção:
            if(atual -> dir == NULL){
                atual -> dir = aux;
                printf("\nElemento %d inserido com sucesso!\n", valor);
                return;
            }
            //se a raiz tiver um filho do lado direito, os valores desse filho são copiados para a estrutura atual:
            atual = atual -> dir;
        }else{ //se o valor que será inserido for menor o valor da raiz...
            if(atual -> esq == NULL){ //e se a raiz não tiver um neto do lado esquerdo, o neto esquerdo da raiz recebe a inserção e termina a inserção:
                atual -> esq = aux;
                printf("\nElemento %d inserido com sucesso!\n", valor);
                return;
            }
            //se a raiz tiver um filho do lado esquerdo, os valores desse filho são copiados para a estrutura atual:
            atual = atual -> esq;
        }
    }
}

void busca(){
    int valor;

    printf("\nInforme o valor a ser buscado: ");
    scanf("%d", &valor);

    no *atual = raiz;

    while(atual != NULL){ //até que a estrutura atual seja nula, a pesquisa vai continuar:
        if(valor == atual -> dado){ //se o dado da estrutura atual for igual ao valor pesquisado a pesquisa termina e informa ao usuário o sucesso.
            printf("\nValor encontrado.\n");
            return;
        }

        if(valor < atual -> dado) //se o valor pesquisado for menor que o dado da estrutura atual, atual recebe os valores de seu filho esquerdo.
            atual = atual -> esq;
        else //se o valor pesquisado for maior ou igual ao dado da estrutura atual, atual recebe os valores de seu filho direito.
            atual = atual -> dir;
    }

    printf("\nValor não encontrado\n"); //Informa o usuário caso a busca não tenha sido bem sucedida.
}

//função recursiva para mostrar os valores da arvore em ordem:
//Começa tendo como parametro a raiz. Se o parametro não for nulo, chama-se a mesma função passando o filho esquerdo como parametro
//portando o mesmo processo é repetido para esse novo paramêtro). Então mostra na tela o valor do próprio paramêtro, e por fim chama-se
//a mesma função passando o filho direito como parametro (portando o mesmo processo é repetido para esse novo paramêtro).
//resumidamente: para cada subarvore chama-se a função novamente e mostra-se os valores na seguinte ordem: esquerdo, raiz, direito.

void em_ordem(no *atual){

    if(atual != NULL){
        em_ordem(atual -> esq);
        printf("%d ", atual -> dado);
        em_ordem(atual -> dir);
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int entrada;

    do{
        printf("\tARVORE BINÁRIA DE BUSCA\n");
        entrada = menu();
        switch(entrada){
        case 1:
            insere();
            break;
        case 2:
            busca();
            break;
        case 3:
            printf("\nValores da árvore:\n");
            em_ordem(raiz);
            printf("\n");
            break;
        case 4:
            return 0;
        default:
            printf("\nOpção inválida.\n");
        }
        printf("\n");

        system("pause"); //pausa a tela e pede o pressionamento de uma tecla p/ continuar
        system("cls"); //limpa tudo que foi escrito na tela anteriormente

    }while(entrada != 4);

    return 0;
}


