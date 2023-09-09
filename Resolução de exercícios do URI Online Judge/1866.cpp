#include <iostream>
using namespace std;
int main(){

    int c, n, s=0;
    cin>>c;

    for(int i=0; i<c; i++){
        cin>>n;
        for(int j=0; j<n; j++){
            if(j%2 == 0){
                s += 1;
            }else{
                s -= 1;
            }
        }
        cout<<s<<endl;
        s=0;
    }


    return 0;
}




