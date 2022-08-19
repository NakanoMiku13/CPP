#include<bits/stdc++.h>
using namespace std;
auto input(const int n)->vector<string>{
    vector<string> tmp;
    cout<<"Ingrese los elementos a continuacion\n";
    for(int i=0;i<n;i++){
        cout<<"Ingresa el elemento "<<i+1<<endl;
        string t;
        cin>>t;
        tmp.push_back(t);
    }
    return tmp;
}
auto main()->int{
    vector<string> e1,e2,pf;
    int n,m,k;
    cout<<"Ingrese la cantidad de sopas sin espacios\n";
    cin>>n;
    e1=input(n);
    cout<<"Ingrese la cantidad de entremes sin espacios\n";
    cin>>m;
    e2=input(m);
    cout<<"Ingrese la cantidad de guisados sin espacios\n";
    cin>>k;
    pf=input(k);
    cout<<endl<<endl;
    for(auto i:e1){
        for(auto j:e2){
            for(auto l:pf){
                cout<<"La comida sera:\nComo primer entrada:\n"<<i<<endl;
                cout<<"Como segunda entrada sera:\n"<<j<<endl;
                cout<<"Como guisado tendremos:\n"<<l<<endl;
            }
        }
        cout<<endl<<endl;
    }
}