#include <stdio.h>
#define c 50

int main(){

    int n, k, entrada, x[c+10], cont_x = 0, repeticoes[c+10], saida=0;
    x[0] = 0;

    scanf("%d %d", &n, &k);

    for(int i=0; i<=n+10; i++) repeticoes[i]=0;

    for(int i=0; i<n; i++){

        scanf("%d", &entrada);

        if(entrada > 0){
            x[cont_x+1] = x[cont_x] + entrada;
            cont_x++;
        }else if(entrada == 0) repeticoes[cont_x]++;
    }

    for(int i=0; i<=cont_x; i++){
        int inicio=i, fim=cont_x, meio;

        while(inicio <= fim){
            meio = (inicio+fim)/2;

            if((x[meio]-x[i-1]) == k){
                saida += 1 + repeticoes[meio];
                printf("\n\nsoma = 0 em x[%d]\n, saida = %d", meio, saida);
                inicio = meio+1;
            }else if(x[meio] - x[i-1] > k) fim = meio-1;
            else inicio = meio+1;
        }
    }

    printf("\n%d\n", saida);

    printf("\n\nsoma: \n");
    for(int i=0; i<=cont_x; i++){
        printf("%d ", x[i]);
    }

    printf("\n\nrepeticoes: \n");
    for(int i=0; i<=cont_x; i++){
        printf("%d ", repeticoes[i]);
    }

    return 0;
}
