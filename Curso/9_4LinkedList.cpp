#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    list<int> listaNumeros;
    int n,x;
    cout<<"Cuantos numeros desea guardar?"<<endl;
    cin>>n;
    for(auto i=0;i<n;i++){
        cin>>x;
        listaNumeros.push_back(x);
    }
    cout<<"La lista de numeros es la siguiente"<<endl;
    for(auto i:listaNumeros){
        cout<<i<<endl;
    }
    cout<<"Otra forma de mostrar la lista de numeros"<<endl;
    auto tmp = listaNumeros;
    while(!tmp.empty()){
        cout<<tmp.back()<<endl;
        tmp.pop_back();
    }
    cout<<"Otra forma de mostrar la lista de numeros"<<endl;
    tmp = listaNumeros;
    while(!tmp.empty()){
        cout<<tmp.front()<<endl;
        tmp.pop_front();
    }
}