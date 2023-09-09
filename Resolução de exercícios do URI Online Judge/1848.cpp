#include <iostream>
using namespace std;
int main(){

    int cont=0;
    int aux[3];
    int resultado=0;

    aux[0]=0;
    aux[1]=0;
    aux[2]=0;

    string entrada = "";

    while(cont != 6){
        cin>>entrada;

        if(entrada == "caw"){
            cont++;
            if(cont%2 == 0){
                cout<<resultado<<endl;
                resultado=0;
            }

        }else{
            for(int i=0; i<3; i++){
                if(entrada[i] == '*'){
                    aux[i]=1;

                    if(i==0){
                        resultado +=4;
                    }else if(i==1){
                        resultado +=2;
                    }else if(i==2){
                        resultado +=1;
                    }
                }
            }

        }
    }

    return 0;
}

