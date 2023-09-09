#include <iostream>
using namespace std;

int n, k;
long int saida, soma;
int sequencia[500000];

void varredura(int j){
    for(j; j<n-1; j++){
        soma += sequencia[j+1];
        if(soma==k){
            saida++;
        }else if(soma>k){
            break;
        }
    }
}

int main(){
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>sequencia[i];
    }

    for(int i=0; i<n; i++){
        soma = sequencia[i];
        if(soma<k){
            varredura(i);
        }else if(soma == k){
            saida++;
            varredura(i);
        }
    }
    cout<<saida<<endl;

    return 0;
}
