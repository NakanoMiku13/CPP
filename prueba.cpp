#include<bits/stdc++.h>
using namespace std;
#define punteroVacio  nullptr
#define nodoVacio  nullptr
template<typename dato> using pointer = dato*;
template<typename informacion> struct nodo{
    public:
        informacion valorAlmacenado;
        pointer<nodo> siguiente, anterior;
        //constructor
        nodo(informacion valorPorAlmacenar): valorAlmacenado(valorPorAlmacenar),
        siguiente(punteroVacio),anterior(punteroVacio){}
};
template<typename tipoDeDato> struct pqueue{
    private:
        pointer<nodo<tipoDeDato>> _cabeza,_espalda;
        size_t _cantElementos;
    public:
        pqueue(): _cabeza(punteroVacio), _espalda(punteroVacio), _cantElementos(0){}
        auto vacia()->bool{
            return (_cantElementos == 0) ? true : false;
        }
        auto longitud()->size_t{
            return _cantElementos;
        }
        auto quitar(){
            if(vacia()) return;
            else{
                if(_cabeza == _espalda){
                    delete _cabeza;
                    _cabeza = _espalda = punteroVacio;
                }else{
                    auto temporal = _cabeza;
                    _cabeza = _cabeza->siguiente;
                    delete temporal;
                }
                _cantElementos--;
            }
        }
        auto insertar(tipoDeDato valorNuevo){
            auto nuevoNodo = new nodo<tipoDeDato>(valorNuevo);
            if(vacia()) _cabeza = _espalda = nuevoNodo;
            else{
                //Caso donde el nuevo elemento es mayor a la _cabeza
                if(_cabeza->valorAlmacenado < nuevoNodo->valorAlmacenado){
                    nuevoNodo->siguiente = _cabeza;
                    _cabeza->anterior = nuevoNodo;
                    _cabeza = nuevoNodo;
                }else{
                    //Caso especial
                    auto nodoMovimiento = _cabeza;
                    for(;nodoMovimiento->valorAlmacenado > nuevoNodo->valorAlmacenado
                    && nodoMovimiento->siguiente != nodoVacio;nodoMovimiento=nodoMovimiento->siguiente);
                    //Caso donde estamos en el ultimo nodo
                    if(nodoMovimiento->siguiente == nodoVacio && nodoMovimiento->valorAlmacenado > nuevoNodo ->valorAlmacenado){
                        _espalda-> siguiente = nuevoNodo;
                        nuevoNodo->anterior = _espalda;
                        _espalda = nuevoNodo;
                    }else{
                        auto temporal = nodoMovimiento->anterior;
                        nuevoNodo->siguiente = nodoMovimiento;
                        nuevoNodo->anterior = temporal;
                        nodoMovimiento->anterior = nuevoNodo;
                        temporal->siguiente = nuevoNodo;
                        _espalda = nodoMovimiento;
                    }
                }
            }
            _cantElementos++;
        }
        auto front(){
            return _cabeza->valorAlmacenado;
        }
};
auto main()->int{
    pqueue<int> pp;
    int n;
    cin>>n;
    for(auto i=0;i<n;i++){
        int x;
        cin>>x;
        pp.insertar(x);
    }

    cout<<endl;
    while(!pp.vacia()){
        cout<<pp.front()<<" ";
        pp.quitar();
    }
}