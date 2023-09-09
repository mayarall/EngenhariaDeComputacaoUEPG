#include <iostream>
using namespace std;
int main(){

    int n, m, p;

    cin>>n;

    int x[n];

    for(int i=0; i<n; i++){
        cin>>x[i];

        if(i==0){
            m=x[i];
            p=i;
        }else{
            if(x[i] < m){
                m = x[i];
                p=i;
            }
        }
    }

    cout<<"Menor valor: "<<m<<endl;
    cout<<"Posicao: "<<p<<endl;

    return 0;
}
