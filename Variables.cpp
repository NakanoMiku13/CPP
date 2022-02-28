#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    //int,float,double,string,char,bool,long, auto (var)
    //long, long long, unsigned, unsigned long long 
    // +, -, /, *
    // ++, --
    // ** 
    // =
    // (int),(char),(string),(float),etc...
    int a,b,r;
    cin>>a>>b;
    r=a+b+(int)"cas";
    cout<<"Suma: "<<a+b<<endl;
    cout<<"Resta: "<<a-b<<endl;
    cout<<"Divi: "<<a/b<<endl;
    cout<<"Multiplicity: "<<a*b<<endl;
    //cout<<"Incremento: "<<++a<<endl;
    //cout<<"Decremento: "<<--b<<endl;
    cout<<"Asignacion: "<<r<<endl;
    cout<<"Prefijo char: "<<(char)65<<endl;
    // && || and or == != 
    
    if((a==b and b-1==r) or a+1!=(!(a!=b+1))){
        cout<<"A es igual a B"<<endl;
    }else{
        cout<<"A no es igual a B"<<endl;
    }
    if(!(a!=b)) cout<<"A es distinto de B"<<endl;
    else cout<<"A no es distinto de B\n";
    system("PAUSE");
}