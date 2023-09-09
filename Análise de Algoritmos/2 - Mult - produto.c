#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define n 4

char U[5], V[5], Resultado[10];

void Soma(char *U, char *V, char *Soma){
    int aux_u[n], aux_v[n], result[n+1], i, cont_u=0, cont_v=0, aux=0;
    /*transformando os vetores de caracteres em vetores de inteiros:*/

    for(i=0; i<n; i++){
        aux_u[i] = U[i]-'0';
        aux_v[i] = V[i]-'0';

    }

    /*cont_u = strlen(U);
    cont_v = strlen(V);

    if(cont_u > cont_v)
        i = cont_u;
    else
        i = cont_v;*/

    i=n-1;
    aux=0;
    while(i >= 0){
         if((aux_u[i]+aux_v[i]+aux) > 9){

            result[i+1] = (aux_u[i]+aux_v[i]+aux)-10;
            aux = 1;

            if(i == 0)
                result[i]=1;
        }else{
            result[i+1] = aux_u[i]+aux_v[i]+aux;
            aux=0;
        }
        i--;
    }

    /*for(i=0; i<n; i++){
        aux_u[i] = U[i]-'0';
        aux_v[i] = V[i]-'0';
    }


    for(i=n-1; i>=0; i--){
        if(((aux_u[i]+aux_v[i]+aux) > 9)){
            result[i+1] = (aux_u[i]+aux_v[i]+aux)-10;
            aux = 1;

            if(i!=0)
                result[i]=1;
        }else{
            result[i+1] = aux_u[i]+aux_v[i]+aux;
            aux=0;
        }
    }*/
    printf("\nSoma: ");
    for(i=0; i<=n; i++){
        printf("%d", result[i]);
    }
    printf("\n");
}


void Mult (char *U, char *V, char *Resultado){
    int aux_u[n], aux_v[n], result[2*n], i, j, cont=0;
    for(i=0; i<n; i++){
        aux_u[i] = U[i]-'0';
        aux_v[i] = V[i]-'0';
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            /*result[cont] =*/;
        }
    }
}

int main(){
    U[0] = '9';
    U[1] = '9';
    U[2] = '9';
    U[3] = '9';

    V[0] = '9';
    V[1] = '9';
    V[2] = '9';
    V[3] = '9';

    /*Mult(U,V, Resultado);*/
    Soma(U,V, Resultado);

    return 0;

}
