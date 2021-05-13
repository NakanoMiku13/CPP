#include<bits/stdc++.h>
using namespace std;
//Se declara el nodo funcional para la pila
struct Nodo{
    //Valor del nodo
    int Valor;
    //Apuntador al nodo siguiente
    Nodo* Sig;
};
struct Pila{
    //Se declara la cabeza
    Nodo* nodo=nullptr;
    //Se declara el tamaño
    int size=0;
    //Se pregunta si está vacia la pila
    bool Empty(){
        if(size==0) return true;
        return false;
    }
    //Regresa el último valor agregado
    int tope(){
        return nodo->Valor;
    }
    //Agrega un elemento
    void push(int x){
        //Se aumenta en 1 el tamaño de la pila
        size++;
        //Se crea un nodo auxiliar
        Nodo* tmp=new Nodo();
        //Se asigna al valor del temporal x
        tmp->Valor=x;
        //Se pregunta si el nodo cabeza está vacío
        if(nodo==nullptr){
            //Si es el caso se asigna a la cabeza el nodo temporal, para crear esta misma
            nodo = tmp;
        }else{
            //En caso contrario se crea un nodo llamado "move" para no perder de vista al nodo original
            //o la "head", y a nodo o sea la "head", se asigna el valor de tmp, esto con el fin de 
            //que el nodo siguiente sea move, así desplazamos la cabeza para abajo
            //Y el nuevo valor se vuelve la cabeza
            Nodo* move=nodo;
            nodo=tmp;
            nodo->Sig=move;
            move=nullptr;
        }
    }
    //Funcion para elimiar el head
    void pop(){
        //Se pregunta si está nulo
        if(nodo!=nullptr){
            size--;
            //Se crea un nodo temporal y se apunta a la cabeza
            Nodo* tmp=nodo;
            //Ahora el nodo original, pasa a ser el valor de siguiente y con tmp, borramos el original
            nodo=nodo->Sig;
            delete(tmp);
        }
    }
};
int main(){
    Pila test;
    for(int i=0;i<5;i++){
        test.push(i);
    }
    cout<<test.tope()<<" "<<test.size<<endl;
    test.pop();
    cout<<test.tope()<<" "<<test.size<<endl;
    while(!test.Empty()){
        cout<<test.tope()<<" "<<test.size<<endl;
        test.pop();
    }
}