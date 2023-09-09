#include <iostream>
#include <string>
using namespace std;
int main(){

    int t;
    cin>>t;

    string sheldon, raj;

    for(int i=0; i<t; i++){
        cin>>sheldon>>raj;

        if(sheldon == "tesoura" && raj == "papel" || sheldon == "papel" && raj == "pedra" || sheldon == "pedra" && raj == "lagarto" || sheldon == "lagarto" && raj == "Spock" || sheldon == "Spock" && raj == "tesoura" || sheldon == "tesoura" && raj == "lagarto" || sheldon == "lagarto" && raj == "papel" || sheldon == "papel" && raj == "Spock" || sheldon == "Spock" && raj == "pedra" ||sheldon == "pedra" && raj == "tesoura"){
            cout<<"Caso #"<<i+1<<": Bazinga!"<<endl;
        }else if(raj == "tesoura" && sheldon == "papel" || raj == "papel" && sheldon == "pedra" || raj == "pedra" && sheldon == "lagarto" || raj == "lagarto" && sheldon == "Spock" || raj == "Spock" && sheldon == "tesoura" || raj == "tesoura" && sheldon == "lagarto" || raj == "lagarto" && sheldon == "papel" || raj == "papel" && sheldon == "Spock" || raj == "Spock" && sheldon == "pedra" ||raj == "pedra" && sheldon == "tesoura"){
            cout<<"Caso #"<<i+1<<": Raj trapaceou!"<<endl;
        }else if(raj == sheldon){
            cout<<"Caso #"<<i+1<<": De novo!"<<endl;
        }
    }

    return 0;
}

