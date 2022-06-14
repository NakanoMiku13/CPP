#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    cout<<"Ingresa dos numeros"<<endl<<"Ingresa el primer numero: \n";
    int n,m;
    cin>>n;
    cout<<"Ingresa el segundo numero:\n";
    cin>>m;
    if((++m)>n){
        cout<<m<<" es mayor a "<<n<<endl;
    }else{
        cout<<m<<" no es mayor aun con el incremento a "<<n<<endl;
    }
    if(m%2==0 and n%3==0){
        cout<<m<<" es par, mientras que "<<n<<" el multiplo de 3"<<endl;
    }
}