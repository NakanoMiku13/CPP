#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    cout<<"Ingresa dos numeros"<<endl<<"Ingresa el primer numero: \n";
    int n,m;
    cin>>n;
    cout<<"Ingresa el segundo numero:\n";
    cin>>m;
    if(n>m && n%2==0){
        cout<<n<<" es mayor a "<<m<<endl;
    }else if(n!=m and m>=0){
        cout<<n<<" es distinto de "<<m<<" y es mayor a 0"<<endl;
    }else{
        if(n==m){
            cout<<n<<" es identico a "<<m<<endl;
        }else{
            if(n>2 or m>2 and m!=3 or m!=3){
                cout<<n<<" y "<<m<<" son mayores a 2 y son disintos de 3"<<endl;
            }else{
                cout<<n<<" es menor a "<<m<<endl;
            }
        }
    }
}