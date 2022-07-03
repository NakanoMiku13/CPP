#include<bits/stdc++.h>
using namespace std;
template <typename data,typename data2>
struct pairI{
    data first;
    data2 second;
};
auto main()->int{
    pairI<int,char> parejaImplementada;
    cout<<"Este es un pair implementado"<<endl<<"Ingresa un numero y una letra"<<endl;
    cin>>parejaImplementada.first>>parejaImplementada.second;
    cout<<"Estos son los datos almacenados"<<endl<<parejaImplementada.first<<endl<<parejaImplementada.second<<endl;
}