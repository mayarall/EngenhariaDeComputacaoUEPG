
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define n 3

char U[n+1], V[n+1], Resultado[2*n];

void Soma(char *U, char *V, char *Soma){
    int aux_u[n], aux_v[n], result[n+1], i, aux=0;
    /*transformando os vetores de caracteres em vetores de inteiros:*/

    for(i=0; i<n; i++){
        aux_u[i] = U[i]-'0';
        aux_v[i] = V[i]-'0';
        /*printf("u: %d   v: %d\n", aux_u[i], aux_v[i]);*/
    }

    i=n-1;

    while(i >= 0){
         if((aux_u[i]+aux_v[i]+aux) > 9){
            result[i+1] = (aux_u[i]+aux_v[i]+aux)-10;
            aux = 1;
            /*printf("result[%d] = %d\n", i, result[i+1]);*/
            if(i == 0)
                result[i]=1;
        }else{
            result[i+1] = aux_u[i]+aux_v[i]+aux;
            aux=0;
            if(i == 0)
                result[i]=0;
            /*printf("result[%d] = %d\n", i, result[i+1]);*/
        }
        i--;
    }

    printf("\nSoma: ");
    for(i=0; i<=n; i++){
        Resultado[i] = result[i] + '0';
        printf("%c", Resultado[i]);
    }
    printf("\n");
}


void Mult (char *U, char *V, char *Resultado){
    int aux_u[n], aux_v[n], result[2*n], i, j, cont=2*n-1, aux=1, temp=0;
    for(i=0; i<n; i++){
        aux_u[i] = U[i]-'0';
        aux_v[i] = V[i]-'0';
        /*printf("u: %d   v: %d\n", aux_u[i], aux_v[i]);*/
    }

    for(j=0; j<2*n; j++){
            result[j]=0;

    }

    for(i=n-1; i>=0; i--){
        for(j=n-1; j>=0; j--){
            if(aux_v[i]*aux_u[j] > 9){
                result[cont] += aux_v[i]*aux_u[j] - ((aux_v[i]*aux_u[j])/10)*10;
                result[cont-1]+=((aux_v[i]*aux_u[j])/10);
                /*printf("\n%d", result[cont]);*/
                cont--;
            }else{
                result[cont] += aux_v[i]*aux_u[j];
                /*printf("\n%d", result[cont]);*/
                cont--;
            }
        }
        cont = n*2-1-aux;
        aux++;
    }
    printf("\n");

    for(j=2*n-1; j>=0; j--){
            if(result[j]>9){
                temp = result[j];
                /*printf("uuuuuuuuu%d\n", (result[j]));*/
                result[j] -= (result[j]/10)*10;
                /*printf("eeeeeeeee%d\n", (result[j]));*/
                if(temp >= 20)
                    result[j-1] = result[j-1] + 2;
                else
                    result[j-1] = result[j-1] + 1;
                /*printf("aaaaaaaaa%d\n", (result[j-1]));*/
            }
    }
        printf("Multiplicacao: ");
        for(j=0; j<2*n; j++){
            Resultado[j] = result[j] + '0';
            printf("%c", Resultado[j]);
        }
        printf("\n");
}

int main(){
    U[0] = '0';
    U[1] = '0';
    U[2] = '8';


    V[0] = '0';
    V[1] = '0';
    V[2] = '5';


    Mult(U,V, Resultado);
    /*Soma(U,V, Resultado);*/

    return 0;

}
