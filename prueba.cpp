#include <iostream>
using namespace std;
template<typename data> using pointer = data*;
template<typename data> struct node{
    private:
        #define punteroVacio nullptr
    public:
        data valor;
        pointer<node> siguiente,anterior;
        node(data contenido): valor(contenido),siguiente(punteroVacio), anterior(punteroVacio){}
};
template<typename data> struct Vector{
    private:
        pointer<node<data>> _head,_back;
        size_t _numElementos;
    public:
        Vector(): _head(nullptr),_back(nullptr),_numElementos(0){}
        auto empty()->bool{
            return (_numElementos == 0) ? true : false;
        }
        auto push_back(data valor){
            //Crear nuevo nodo
            auto newNode = new node<data>(valor);
            //Comprobar si el vector está vacio
            if(empty()) _head = _back = newNode;
            else{
                //Ya hay por lo menos un elemento
                newNode->anterior = _back;
                _back->siguiente = newNode;
                _back = newNode;
            }
            _numElementos++;
        }
        auto front()->data{
            return (_head != nullptr) ? _head->valor : data(NULL);
        }
        auto longitud()->size_t{
            return _numElementos;
        }
        auto push_front(data primero){
            auto newNode = new node<data>(primero);
            if(empty()) _head = _back = newNode;
            else{
                _head->anterior = newNode;
                newNode->siguiente = _head;
                _head = newNode;
            }
            _numElementos++;
        }
};
auto main()->int{
    // .at push_back pop_back size vector[2] vector[6]=2 vector+i reverse begin end
}