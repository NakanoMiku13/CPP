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
        template<typename datas>
        friend ostream &operator<<(ostream&,const node<datas>&);
};
template<typename data>
ostream &operator<<(ostream& os,const node<data>& newNode){
    os<<newNode.valor<<" holamundo";
    return os;
}
template<typename dataset> struct _iterator{
    private:
        pointer<node<dataset>> _current;
    public:
        _iterator(pointer<node<dataset>> _currentNode): _current(_currentNode){}
        auto &operator++(){
            _current = _current->siguiente;
            return _current;
        }
        //No termino de entender el porque aquí se usa el parametro int y en el otro no
        auto operator++(int){
            auto retVal = *this;
            ++(*this);
            return retVal;
        }
        auto *operator->(){
            return &_current->valor;
        }
        auto &operator*(){
            return _current->valor;
        }
        auto operator==(const auto &_self)const{
            return _current == _self->_current;
        }
        auto operator!=(const auto &_self)const{
            return _current != _self._current;
        }
};
template<typename data> struct Vector{
    private:
        pointer<node<data>> _head,_back;
        size_t _numElementos;
        typedef _iterator<data> iterator;
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
        auto back()->data{
            return (_back != nullptr) ? _back->valor : data(NULL);
        }
        auto pop_back(){
            if(empty()) return;
            else{
                if(_head == _back){
                    delete _head;
                    _head = _back = nullptr;
                    _numElementos = 0;
                    return;
                }
                auto tmp = _back;
                _back = _back->anterior;
                delete tmp;
                _back->siguiente = nullptr;
                _numElementos--;
            }
        }
        auto pop_front(){
            if(empty()) return;
            else{
                if(_head == _back){
                    delete _head;
                    _head = _back = nullptr;
                }else{
                    auto tmp = _head;
                    _head = _head->siguiente;
                    _head->anterior = nullptr;
                    delete tmp;
                }
                _numElementos--;
            }
        }
        auto &operator[](const int index){
            if(index < _numElementos){
                auto move = _head;
                for(int i = 0;i < index; i++,move=move->siguiente);
                return move->valor;
            }
        }
        auto &operator+(const int index){
            if(index < _numElementos){
                auto move = _head;
                for(int i = 0;i < index; i++,move=move->siguiente);
                return move->valor;
            }
        }
        auto at(const int index){
            if(index < _numElementos){
                auto move = _head;
                for(int i = 0;i < index; i++,move=move->siguiente);
                return move->valor;
            }
        }
        iterator begin(){
            return this->_head;
        }
        iterator end(){
            return this->_back->siguiente;
        }
};
auto main()->int{
    Vector<int> v;
    int n;
    int arreglo[]={1,2,3,4};
    cin>>n;
    for(auto i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<v[0];
    v[0] = 45;
    cout<<endl<<"Este es con un for tradicional: \n";
    for(int i =0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<"Este es con aritmetica de apuntadores: \n";
    for(int i =0;i<n;i++){
        cout<<v+i<<" ";
    }
    cout<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }
}