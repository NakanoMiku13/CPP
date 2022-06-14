#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    cout<<"Ingresa dos numeros"<<endl<<"Ingresa el primer numero: \n";
    int n,m;
    cin>>n;
    cout<<"Ingresa el segundo numero:\n";
    cin>>m;
    if(n>m){
        cout<<n<<" es mayor a "<<m<<endl;
    }else{
        if(n==m){
            cout<<n<<" es identico a "<<m<<endl;
        }else{
            cout<<n<<" es menor a "<<m<<endl;
        }
    }
}