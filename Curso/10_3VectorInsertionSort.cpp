#include<bits/stdc++.h>
using namespace std;
template<typename data> using pointer = data*;
template<typename data> struct node{
    public:
        data value;
        pointer<node> next,prev;
        #define emptyNode nullptr
        node(data newValue): value(newValue),next(emptyNode),prev(emptyNode){}
};
template<typename data> struct Vector{
    private:
        pointer<node<data>> _head,_back;
        size_t _size;
        #define emptyNode nullptr
        template<typename dataset> struct _iterator{
            private:
                pointer<node<dataset>> _current;
            public:
                _iterator(pointer<node<dataset>> _currentNode): _current(_currentNode){}
                auto &operator++(){
                    _current = _current->next;
                    return _current;
                }
                auto &operator--(){
                    _current = _current->prev;
                    return _current;
                }
                auto operator++(int){
                    auto retVal = *this;
                    ++(*this);
                    return retVal;
                }
                auto operator--(int){
                    auto retVal = *this;
                    --(*this);
                    return retVal;
                }
                auto *operator->()const{
                    return &_current->value;
                }
                auto &operator*()const{
                    return _current->value;
                }
                auto operator==(const auto &_self){
                    return _current==_self->_current;
                }
                auto operator!=(const auto &_self){
                    return _current!=_self._current;
                }
        };
        typedef _iterator<data> iterator;
        auto _getValue(const int index){
            if(index > _size) return NULL;
            auto move = _head;
            for(auto i=1;i<=index;i++,move= move->next);
            return move->value;
        }
    public:
        Vector(): _head(emptyNode),_back(emptyNode),_size(0){}
        auto empty()->bool{
            return (not _head or not _back or _size==0) ? true : false;
        }
        auto push_high(data newValue){
            auto newNode = new node<data>(newValue);
            if(empty()) _head = _back = newNode;
            else{
                if(newNode->value > _head->value){
                    _head->prev = newNode;
                    newNode->next = _head;
                    _head = newNode;
                }else{
                    auto move = _head;
                    for( ; move->next != emptyNode && move->value > newNode->value ; move = move->next);
                    if(move->next != emptyNode and move->value < newNode->value){
                        auto tmp = move->prev;
                        move->prev = tmp->next = newNode;
                        newNode->next = move;
                    }else{
                        if(move->value < newNode->value){
                            auto tmp = move->prev;
                            move->prev = tmp->next = newNode;
                            newNode->next = move;
                        }else{
                            move->next = newNode;
                            newNode->prev = move;
                            _back = newNode;
                        }
                    }
                }
            }
            _size++;
        }
        auto push_low(data newValue){
            auto newNode = new node<data>(newValue);
            if(empty()) _head = _back = newNode;
            else{
                if(_head->value > newNode->value){
                    _head->prev = newNode;
                    newNode->next = _head;
                    _head = newNode;
                }else{
                    auto move = _head;
                    for( ; move->next != emptyNode && move->value < newNode->value ; move = move->next);
                    if(move->next == emptyNode and move->value < newNode->value){
                        move->next = newNode;
                        newNode->prev = move;
                        _back = newNode;
                    }else{
                        auto tmp = move->prev;
                        tmp->next = move->prev = newNode;
                        newNode->next = move;
                        newNode->prev = tmp;
                    }
                }
            }
            _size++;
        }
        auto pop_back(){
            if(empty()) return;
            else{
                if(_head == _back){
                    delete _head;
                    _head = _back = emptyNode;
                    _size=0;
                    return;
                }
                auto tmp = _back;
                _back = _back->prev;
                delete tmp;
                _size--;
            }
        }
        auto pop_front(){
            if(empty()) return;
            else{
                if(_head == _back){
                    delete _head;
                    _head = _back = emptyNode;
                    _size=0;
                    return;
                }
                auto tmp = _head;
                _head = _head->next;
                delete tmp;
                _size--;
            }
        }
        auto at(const int index){
            return (index <= _size) ? _getValue(index) : data(NULL);
        }
        auto &operator[](const int index){
            return (index <= _size) ? _getValue(index) : data(NULL);
        }
        auto operator+(const int index){
            return (index <= _size) ? _getValue(index) : data(NULL);
        }
        iterator begin(){
            return this->_head;
        }
        iterator end(){
            return this->_back->next;
        }
};
auto main()->int{
    int n;
    cin>>n;
    Vector<int> v;
    for(auto i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_low(x);
    }
    cout<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }
}