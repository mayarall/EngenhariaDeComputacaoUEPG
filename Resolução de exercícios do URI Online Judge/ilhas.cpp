#include <iostream>
using namespace std;
int main(){

    int n, m, s;
    cin>>n>>m;
    int  u[m+1], v[m+1], p[m+1];

    for(int i=0; i<m; i++){
        cin>>u[i]>>v[i]>>p[i];
    }

    cin>>s;

    int ping[n];

    /*for(int i=1; i<n+1; i++){
        if(i == s){

        }else{*/
            for(int j=0; j<m; j++){
                if(u[j] == s || v[j] == s){
                    ping[]
                }
            }
        /*}
    }*/


    return 0;
}
