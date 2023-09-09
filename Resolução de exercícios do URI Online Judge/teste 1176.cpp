#include <iostream>
using namespace std;

//0 1 1 2 3 5 8 13 21 34 55


int main(){
    int fibonacci[8];

    for(int i=0; i<8; i++){
        if(i==0 || i==1){
            fibonacci[i] = 1;
        }else{
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        }
    }

    cout<<"F(8) = "<<fibonacci[7]<<endl;

    return 0;
}

