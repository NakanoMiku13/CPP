#include<bits/stdc++.h>
using namespace std;
//Creating a template for pointers for abstract datatype
template<typename ptr> using pointer = ptr*;
//Creating a node for the vector
template<typename dataset> struct node{
    private:
        #define nullNode nullptr
    public:
        dataset value;
        pointer<node> next,prev;
        node(dataset newValue): value(newValue), next(nullNode), prev(nullNode){}
};
//Creating the vector
template<typename data> struct Vector{
    private:
        pointer<node<data>> _head,_back;
        size_t _size;
        template<typename valueA,typename valueB> auto _swap(pointer<valueA> a, pointer<valueB> b){
            auto t = *a;
            *a = *b;
            *b = t;
        }
        template<typename dataset> struct _iterator{
            private:
                pointer<node<dataset>> _current;
            public:
                _iterator(pointer<node<dataset>> currentNode): _current(currentNode){}
                auto operator++(){
                    _current = _current->next;
                    return (_current != nullptr) ? _current : nullptr;
                }
                auto operator++(int){
                    auto retVal = *this;
                    ++(*this);
                    return *this;
                }
                auto operator--(){
                    _current = _current->prev;
                    return (_current != nullptr) ? _current : nullptr;
                }
                auto *operator->()const{
                    return &_current->value;
                }
                auto &operator*()const{
                    return _current->value;
                }
                auto operator==(const auto& self){
                    return _current == self->_current;
                }
                auto operator!=(const auto& self){
                    return _current != self._current;
                }
        };
        typedef _iterator<data> iterator;
    public:
        Vector(): _head(nullptr),_back(nullptr),_size(0){}
        auto empty()->bool{
            return (not _head or not _back or _size==0) ? true : false;
        }
        auto push_back(data newValue){
            auto newNode = new node<data>(newValue);
            if(empty()) _head = _back = newNode;
            else{
                _back->next = newNode;
                newNode->prev = _back;
                _back = newNode;
            }
            _size++;
        }
        auto push_front(data newValue){
            auto newNode = new node<data>(newValue);
            if(empty()) _head = _back = newNode;
            else{
                _head->prev = newNode;
                newNode->next = _head;
                _head = newNode;
            }
            _size++;
        }
        auto find(data searchValue){
            auto array = *this;
            for(auto i:array){
                if(i==searchValue) return i;
            }
        }
        auto findPosition(data searchValue)->int{
            auto t = _size-1;
            auto array = *this;
            for(int i=0;i<t;i++){
                if(array[i]==searchValue) return i;
            }
            return data(NULL);
        }
        auto &operator[](const int index){
            auto move = _head;
            for(int i=0;i<index;i++,move=move->next);
            return move->value;
        }
        auto begin()->iterator{
            return _head;
        }
        auto end()->iterator{
            return _back->next;
        }
};
auto main()->int{
    int n,x;
    Vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    for(auto i:v) cout<<i<<" ";
    cout<<endl;
    cin>>x;
    cout<<"Valor: "<<v.find(x)<<endl<<"Posicion: "<<v.findPosition(x)+1;
}