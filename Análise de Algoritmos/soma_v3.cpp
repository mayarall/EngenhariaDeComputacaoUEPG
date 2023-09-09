#include <iostream>
using namespace std;
#define c 500000

int n, k, entrada, soma[c], repeticoes[c];
long long resp;

int busca_binaria(int i){
    int inicio=i, fim=n, meio, resp = -1;

        while(inicio <= fim){
            meio = (inicio+fim)/2;

            if((soma[meio] - soma[i-1]) == k){
                resp = meio;
                inicio = meio+1;
            }else if(soma[meio] - soma[i-1] > k) fim = meio-1;
            else inicio = meio+1;
        }
        return resp;
}

int main(){


    //scanf("%d %d", &n, &k);
    cin>>n>>k;

    for(int i=0; i<n; i++){

        //scanf("%d", &entrada);
        cin>>entrada;
            soma[i+1] = soma[i] + entrada;

            if(entrada == 0) repeticoes[i+1] = repeticoes[i];
            else repeticoes[i+1] = i + 1;
    }

    for(int i=1; i<=n; i++){
        int maior, aux = busca_binaria(i);
        if(aux != -1){
//            if(i > repeticoes[aux]){
//                maior = i;
//            }else if(repeticoes[aux] >= i){
//                maior = repeticoes[aux];
//            }

            resp += (long long)(aux - max(i, repeticoes[aux]) + 1);
        }
    }

    cout<<resp;

    return 0;
}

