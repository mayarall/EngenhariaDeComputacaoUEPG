//Mayara Lovatto Lopes

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu(){
    int opcao;
    printf("\n-----------Escolha uma op��o:-----------");
    printf("\n1 - Inserir um valor");
    printf("\n2 - Buscar um valor");
    printf("\n3 - Exibir a �rvore");
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

    aux=(no*) calloc(1, sizeof(no)); //alocando mem�ria em um lugar sem lixo
    aux -> dado = valor; //colocando o valor no dado da estrutura auxiliar
    //definindo os ponteiros para os n�s filhos como vazios:
    aux -> esq = NULL;
    aux -> dir = NULL;
    //se a raiz estiver vazia, ela recebe os valores da estrutura auxiliar e termina a inser��o:
    if(raiz == NULL){
        raiz = aux;
        printf("\nElemento %d inserido com sucesso!\n", valor);
        return;
    }
    //se a raiz n�o estiver vazia...:
    //os valores da raiz s�o copiados para a estrutura atual:
    atual = raiz;
    //loop, sem condi��o de parada a princ�pio, para que tudo se repita at� a inser��o ser bem sucedida:
    while(1){
        //se o valor que ser� inserido for maior ou igual o valor da raiz...
        if(aux -> dado >= atual -> dado){
            //e se a raiz n�o tiver um filho do lado direito, o filho direito da raiz recebe a inser��o e termina a inser��o:
            if(atual -> dir == NULL){
                atual -> dir = aux;
                printf("\nElemento %d inserido com sucesso!\n", valor);
                return;
            }
            //se a raiz tiver um filho do lado direito, os valores desse filho s�o copiados para a estrutura atual:
            atual = atual -> dir;
        }else{ //se o valor que ser� inserido for menor o valor da raiz...
            if(atual -> esq == NULL){ //e se a raiz n�o tiver um neto do lado esquerdo, o neto esquerdo da raiz recebe a inser��o e termina a inser��o:
                atual -> esq = aux;
                printf("\nElemento %d inserido com sucesso!\n", valor);
                return;
            }
            //se a raiz tiver um filho do lado esquerdo, os valores desse filho s�o copiados para a estrutura atual:
            atual = atual -> esq;
        }
    }
}

void busca(){
    int valor;

    printf("\nInforme o valor a ser buscado: ");
    scanf("%d", &valor);

    no *atual = raiz;

    while(atual != NULL){ //at� que a estrutura atual seja nula, a pesquisa vai continuar:
        if(valor == atual -> dado){ //se o dado da estrutura atual for igual ao valor pesquisado a pesquisa termina e informa ao usu�rio o sucesso.
            printf("\nValor encontrado.\n");
            return;
        }

        if(valor < atual -> dado) //se o valor pesquisado for menor que o dado da estrutura atual, atual recebe os valores de seu filho esquerdo.
            atual = atual -> esq;
        else //se o valor pesquisado for maior ou igual ao dado da estrutura atual, atual recebe os valores de seu filho direito.
            atual = atual -> dir;
    }

    printf("\nValor n�o encontrado\n"); //Informa o usu�rio caso a busca n�o tenha sido bem sucedida.
}

//fun��o recursiva para mostrar os valores da arvore em ordem:
//Come�a tendo como parametro a raiz. Se o parametro n�o for nulo, chama-se a mesma fun��o passando o filho esquerdo como parametro
//portando o mesmo processo � repetido para esse novo param�tro). Ent�o mostra na tela o valor do pr�prio param�tro, e por fim chama-se
//a mesma fun��o passando o filho direito como parametro (portando o mesmo processo � repetido para esse novo param�tro).
//resumidamente: para cada subarvore chama-se a fun��o novamente e mostra-se os valores na seguinte ordem: esquerdo, raiz, direito.

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
        printf("\tARVORE BIN�RIA DE BUSCA\n");
        entrada = menu();
        switch(entrada){
        case 1:
            insere();
            break;
        case 2:
            busca();
            break;
        case 3:
            printf("\nValores da �rvore:\n");
            em_ordem(raiz);
            printf("\n");
            break;
        case 4:
            return 0;
        default:
            printf("\nOp��o inv�lida.\n");
        }
        printf("\n");

        system("pause"); //pausa a tela e pede o pressionamento de uma tecla p/ continuar
        system("cls"); //limpa tudo que foi escrito na tela anteriormente

    }while(entrada != 4);

    return 0;
}


