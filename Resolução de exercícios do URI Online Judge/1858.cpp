#include <iostream>
using namespace std;
int main(){
    int n, t, s=0, aux;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>t;
        if(i==0){
            aux = t;
            s=i;
        }

        if(t<aux){
            aux = t;
            s = i;
        }
    }

    cout<<s+1<<endl;

    return 0;
}
