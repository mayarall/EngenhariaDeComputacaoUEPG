//Mayara Lovatto Lopes

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct no{
    int contador;
    char palavra[40];
    no *esq, *dir;
}no;

no *raiz = NULL; //inicializando a raiz vazia

void insere(char *valor){

    no *novo, *ant, *atual;

    novo=(no*) calloc(1, sizeof(no)); //alocando mem�ria em um lugar sem lixo
    strcpy(novo->palavra, valor); //copiando valor p/ novo->palavra
    //definindo os ponteiros para os n�s filhos como vazios:
    novo -> esq = NULL;
    novo -> dir = NULL;
    novo -> contador = 1;
    //se a raiz estiver vazia, ela recebe os valores da estrutura auxiliar e termina a inser��o:
    if(raiz == NULL){
        raiz = novo;
        printf("\nElemento %s inserido com sucesso!\n", valor);
        return;
    }
    //se a raiz n�o estiver vazia...:
    //os valores da raiz s�o copiados para a estrutura atual e como s raiz n�o tem nenhum ancestral, ant = NULL:
    atual = raiz;
    ant = NULL;
    //loop at� chegar em um lugar vazio:
    //, para que tudo se repita at� a inser��o ser bem sucedida:
    while(atual != NULL){
        ant = atual;
        //se a palavra a ser inserida for igual a palavra atual...
        if(strcmp(novo->palavra, atual->palavra) == 0){
            //se for, mostra a mensagem a seguir, incrementa o contador e libera a mem�ria do novo:
            printf("Elemento %s j� foi inserido anteriormente!\n", valor);
            atual -> contador++;
            free(novo);
            return;
        }
        //se a palavra a ser inserida for menor que a palavra atual (alfabeticamente), atual recebe o n� que estava a sua esquerda:
        if(strcmp(novo->palavra, atual->palavra) < 0)
            atual = atual -> esq;
        //se for maior, atual recebe o n� que estava a sua direita:
        else
            atual = atual -> dir;
    }
    //Ap�s encontrar a posi��o anterior a que a inser��o deve ser realizada, faz-se a inser��o de fato:
    if(strcmp(novo->palavra, ant->palavra) < 0)
        ant->esq = novo;
    else
        ant->dir = novo;

    printf("Elemento %s inserido com sucesso!\n", valor);
}

//fun��o recursiva para mostrar os valores da arvore em ordem:
//Come�a tendo como parametro a raiz. Se o parametro n�o for nulo, chama-se a mesma fun��o passando o filho esquerdo como parametro
//portando o mesmo processo � repetido para esse novo param�tro). Ent�o mostra na tela o valor do pr�prio param�tro, e por fim chama-se
//a mesma fun��o passando o filho direito como parametro (portando o mesmo processo � repetido para esse novo param�tro).
//resumidamente: para cada subarvore chama-se a fun��o novamente e mostra-se os valores na seguinte ordem: esquerdo, raiz, direito.

void em_ordem(no *atual){

    if(atual != NULL){
        em_ordem(atual -> esq);
        printf("\n%s -- Quantidade: %d", atual -> palavra, atual -> contador);
        em_ordem(atual -> dir);
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    FILE *fp;
    char palavra[50];
    fp = fopen("texto.txt", "r");
    if(fp == NULL)
        printf("Arquivo n�o encontrado!\n");
    else{
        printf("----------------------------------------------------------\n");
        while(!feof(fp)){
            if(fscanf(fp,"%s", palavra) != EOF)
                insere(palavra);
        }
    }
    printf("\n----------------------------------------------------------\n");
    em_ordem(raiz);
    printf("\n\n----------------------------------------------------------\n");
    fclose(fp);

    return 0;
}


