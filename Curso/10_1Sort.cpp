#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    int arre[]={1,5,2,3,7};
    vector<int> arre2={6,2,81,100,1};
    string texto = "Hola mundo";
    cout<<"Estructuras sin ordenar: "<<endl;
    for(auto i:arre) cout<<i<<" ";
    cout<<endl;
    for(auto i:arre2) cout<<i<<" ";
    cout<<endl;
    for(auto i:texto) cout<<i<<" ";
    cout<<endl;
    cout<<"Estructuras ordenadas: "<<endl;
    sort(arre,arre+5);
    sort(arre2.begin(),arre2.end());
    sort(texto.begin(),texto.end());
    for(auto i:arre) cout<<i<<" ";
    cout<<endl;
    for(auto i:arre2) cout<<i<<" ";
    cout<<endl;
    for(auto i:texto) cout<<i<<" ";
    cout<<endl;
}