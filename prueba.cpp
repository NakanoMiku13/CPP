#include <iostream>
using namespace std;

int main(){
    char letrama='A',letrami='b';
    int x=13;
    while (x != 0){
        cout<<letrama<<endl<<letrami<<endl;
        letrama+=2;
        letrami+=2;
        x--;
    }

    return 0;
}