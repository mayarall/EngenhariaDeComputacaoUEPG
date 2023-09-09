#include <iostream>
#include <stdio.h>
using namespace std;
int main(){

    int entrada, entDtres, a;

    while((scanf("%d", &entrada)) != EOF){
        entDtres=entrada/3;
        a=(entrada-1)/2;
        int matriz[entrada][entrada];

        for(int i=0; i<entrada; i++){
            for(int j=0; j<entrada; j++){
                matriz[i][j] = 0;
                if((i >= entDtres && i < (entrada - entDtres)) && (j >= entDtres && j < (entrada - entDtres)) ){
                    matriz[i][j] = 1;
                }
                if((i == j)  && (matriz[i][j] == 0)){
                    matriz[i][j] = 2;
                }

                if((i+j) == (entrada-1) && (matriz[i][j] == 0)){
                    matriz[i][j] = 3;
                }

                if(i == a && j == a){
                    matriz[i][j] = 4;
                }

                cout<<matriz[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
