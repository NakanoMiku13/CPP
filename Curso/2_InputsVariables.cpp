#include<bits/stdc++.h>
using namespace std;
int variableGlobalEntera;
auto main()->int{
    int variableLocalEntera=0;
    char variableLocalCaracter='a';
    float variableLocalFlotante=3.1415;
    double variableLocalDoble = 54.12432123;
    string variableLocalCadena = "Hola mundo";
    cout<<variableGlobalEntera<<endl;
    cout<<variableLocalCaracter<<endl;
    cout<<variableLocalFlotante<<endl;
    cout<<variableLocalDoble<<endl;
    cout<<variableLocalCadena<<endl;
    cout<<"Ingresar un dato tipo entero: "<<endl;
    cin>>variableLocalEntera;
    cout<<"El dato ingresado es: "<<variableLocalEntera<<endl;
}