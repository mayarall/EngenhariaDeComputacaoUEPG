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

    novo=(no*) calloc(1, sizeof(no)); //alocando memória em um lugar sem lixo
    strcpy(novo->palavra, valor); //copiando valor p/ novo->palavra
    //definindo os ponteiros para os nós filhos como vazios:
    novo -> esq = NULL;
    novo -> dir = NULL;
    novo -> contador = 1;
    //se a raiz estiver vazia, ela recebe os valores da estrutura auxiliar e termina a inserção:
    if(raiz == NULL){
        raiz = novo;
        printf("\nElemento %s inserido com sucesso!\n", valor);
        return;
    }
    //se a raiz não estiver vazia...:
    //os valores da raiz são copiados para a estrutura atual e como s raiz não tem nenhum ancestral, ant = NULL:
    atual = raiz;
    ant = NULL;
    //loop até chegar em um lugar vazio:
    //, para que tudo se repita até a inserção ser bem sucedida:
    while(atual != NULL){
        ant = atual;
        //se a palavra a ser inserida for igual a palavra atual...
        if(strcmp(novo->palavra, atual->palavra) == 0){
            //se for, mostra a mensagem a seguir, incrementa o contador e libera a memória do novo:
            printf("Elemento %s já foi inserido anteriormente!\n", valor);
            atual -> contador++;
            free(novo);
            return;
        }
        //se a palavra a ser inserida for menor que a palavra atual (alfabeticamente), atual recebe o nó que estava a sua esquerda:
        if(strcmp(novo->palavra, atual->palavra) < 0)
            atual = atual -> esq;
        //se for maior, atual recebe o nó que estava a sua direita:
        else
            atual = atual -> dir;
    }
    //Após encontrar a posição anterior a que a inserção deve ser realizada, faz-se a inserção de fato:
    if(strcmp(novo->palavra, ant->palavra) < 0)
        ant->esq = novo;
    else
        ant->dir = novo;

    printf("Elemento %s inserido com sucesso!\n", valor);
}

//função recursiva para mostrar os valores da arvore em ordem:
//Começa tendo como parametro a raiz. Se o parametro não for nulo, chama-se a mesma função passando o filho esquerdo como parametro
//portando o mesmo processo é repetido para esse novo paramêtro). Então mostra na tela o valor do próprio paramêtro, e por fim chama-se
//a mesma função passando o filho direito como parametro (portando o mesmo processo é repetido para esse novo paramêtro).
//resumidamente: para cada subarvore chama-se a função novamente e mostra-se os valores na seguinte ordem: esquerdo, raiz, direito.

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
        printf("Arquivo não encontrado!\n");
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


