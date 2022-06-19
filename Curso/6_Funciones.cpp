#include<bits/stdc++.h>
using namespace std;
auto funcionBool()->bool{
    return true;
}
bool funcionBool2(){
    return false;
}
auto funcionInt()->int{
    return 100;
}
int funcionInt2(){
    return -500;
}
auto funcionVacia(){
    //Esta es una función vacía
    cout<<"Esta es una funcion vacia 1"<<endl;
}
void funcionVacia2(){
    //Esta es una función vacía
    cout<<"Esta es una funcion vacia 2"<<endl;
}
auto funcionConParametros(int numero1,auto numero2)->int{
    return numero1+(int)numero2;
}
auto funcionCompleja(auto iteration,auto block)->map<int,vector<pair<int,bool>>>{
    if(block == 20) return iteration;
    vector<pair<int,bool>>myVector;
    for(auto i=1;i<=10;i++){
        pair<int,bool> types;
        types.first = (pow(i,2)+(i*2) + 1) * (rand() % 10);
        if(types.first%2  == 0) types.second=true;
        else types.second=false;
        myVector.push_back(types);
    }
    iteration[block]=myVector;
    return funcionCompleja(iteration,block+1);
}
auto funcionCondicionalAbstracta(auto parametro){
    //condition ? result_if_true : result_if_false
    return (parametro > 0) ? parametro : 0;
}
auto funcionInvocaFuncionesRecursiva(auto parameter,const size_t block){
    if(block==0) return;
    auto vect = parameter[block];
    for(auto i:vect){
        if(i.second) cout<<funcionCondicionalAbstracta(i.first)<<" ";
    }
    cout<<endl;
    funcionInvocaFuncionesRecursiva(parameter, block - 1);
}
auto main()->int{
    srand (time(NULL));
    cout<<"Esta es una funcion bool con auto "<<funcionBool()<<endl;
    cout<<"Esta es una funcion bool tradicional "<<funcionBool2()<<endl;
    cout<<"Esta es una funcion int con auto "<<funcionInt()<<endl;
    cout<<"Esta es una funcion int tradicional "<<funcionInt2()<<endl;
    //Esta es una funcion vacia
    funcionVacia();
    funcionVacia2();
    cout<<"Este el restultado de una funcion con parametros "<<funcionConParametros(12,'a')<<endl;
    cout<<"Esta es una funcion Condicional "<<funcionCondicionalAbstracta((int)'a')<<endl;
    map<int,vector<pair<int,bool>>> tmp;
    funcionInvocaFuncionesRecursiva(funcionCompleja(tmp,0),20);
}