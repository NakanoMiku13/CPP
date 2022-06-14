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
    }
    if(m<n){
        cout<<m<<" es menor a "<<n<<endl;
    }
    if(m==n){
        cout<<m<<" es igual a "<<n<<endl;
    }
    if(m!=n){
        cout<<m<<" es diferente de "<<n<<endl;
    }
}