#include <iostream>
using namespace std;

void f(int n){

    long long int fibonacci[n];

    for(int i=0; i<n; i++){
        if(i==0 || i==1){
            fibonacci[i] = 1;
        }else{
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        }
    }

    cout<<"Fib("<<n<<") = "<<fibonacci[n-1]<<endl;

}

int main(){

    int t;

    cin>>t;

    int n[t];

    for(int i=0; i<t; i++){
        cin>>n[i];
        if(n[i] == 0){
            cout<<"Fib(0) = 0"<<endl;
        }else{
            f(n[i]);
        }
    }

    return 0;
}
