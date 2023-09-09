#include <iostream>
#include <stdio.h>
using namespace std;
int main(){

    int n=0, m, l;

    while(scanf("%d", &l) != EOF){
        int v[l];
        for(int j=0; j<l; j++){
            cin>>v[j];
            if(j==0){
                m=v[j];
            }else if(v[j]>m){
                m=v[j];
            }
        }

        if(m<10){
            cout<<"1"<<endl;
        }else if(m>=10 && m<20){
            cout<<"2"<<endl;
        }else{
            cout<<"3"<<endl;
        }
    }

    return 0;
}



