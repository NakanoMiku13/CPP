#include <bits/stdc++.h>
using namespace std;
#define apuntadorVacio nullptr
#define nodoVacio nullptr
template<typename dato> using pointer = dato*;
template<typename informacion> struct nodo{
    public:
        informacion valorAlmacenado;
        pointer<nodo> siguiente;
        nodo(informacion valorPorAlmacenar): valorAlmacenado(valorPorAlmacenar),siguiente(apuntadorVacio){}
};
template<typename dato> struct Pila{
    private:
        pointer<nodo<dato>> _top;
        size_t _size;
    public:
        Pila(): _top(nodoVacio), _size(0){}
        auto vacia()->bool{
            return (_size==0 or not _top) ? true : false;
        }
        auto push(dato datoRecibido){
            auto newNode = new nodo<dato>(datoRecibido);
            if(vacia()) _top = newNode;
            else{
                newNode->siguiente = _top;
                _top = newNode;
            }
            _size++;
        }
        auto pop(){
            if(vacia()) return;
            else{
                if(_top->siguiente == nodoVacio){
                    delete _top;
                    _size = 0;
                    return;
                }
                auto temporal = _top;
                _top = _top->siguiente;
                delete temporal;
                _size--;
            }
        }
        auto size()->size_t{
            return _size;
        }
        auto top()->dato{
            return _top->valorAlmacenado;
        }
};
auto main()->int{
    int n;
    Pila<int> pilita;
    cin>>n;
    for(auto i=0;i<n;i++){
        int x;
        cin>>x;
        pilita.push(x);
    }
    cout<<endl;
    system("color a");
    while(!pilita.vacia()){
        cout<<pilita.top()<<endl;
        pilita.pop();
    }
}