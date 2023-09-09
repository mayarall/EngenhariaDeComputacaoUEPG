#include <iostream>
using namespace std;
int main(){
    int a, b, c, d, q, r;
    cin>>a>>b;

    if(a<0){
        c = b;
        if(b<0){
            c = b * -1;
        }

        for(r=0; r<c; r++){
            d = a-r;
            if(d%b == 0) break;
        }
        q = d/b;
    }else{
        r = a%b;
        q =a/b;
    }

    cout<<q<<" "<<r<<endl;
    return 0;
}



