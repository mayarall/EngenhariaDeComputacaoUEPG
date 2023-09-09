#include <iostream>
using namespace std;
int main(){

    char frase[41] = "LIFE-IS-NOT-A-PROBLEM-TO-BE-SOLVED";

    int n, aux=0;
    cin>>n;

    for(int i=0; i<n; i++){
        if(frase[i] == '-'){
            cout<<" ";
        }else
            cout<<frase[i];
    }
    cout<<endl;

    return 0;
}
//1234567890123456789012345678901234
//LIFE IS NOT A PROBLEM TO BE SOLVED
