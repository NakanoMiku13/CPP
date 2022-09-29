#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <bitset>
#include <complex>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <locale>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
using namespace std;
//Creating the base pointer for the nodes of the class
template<typename data> using pointer = data*;
//Creating the class "node" that will be used on all the classes
template<typename nodeValue> class node{
    public:
        nodeValue value;
        pointer<node> next, prev;
        node(): value {NULL}, next {nullptr}, prev {nullptr}{}
        node(nodeValue newValue): value {newValue}, next {nullptr}, prev {nullptr}{}
        template<typename dataset> friend ostream& operator<<(ostream& os,pointer<node<dataset>>& self);
};
//Main function to print the node directly using cout
template<typename data> auto operator<<(ostream& os,pointer<node<data>>& self){
    os << self->value;
    return os;
}
//Class queue
template<typename data> class List{
    private:
        pointer<node<data>> _head, _back;
        size_t _size;
        template<typename valueA,typename valueB> auto _swap(valueA *a, valueB *b)->void{
            cout<<"Swap\n";
            auto tmp = *a;
            *a = *b;
            *b = tmp;
        }
        template<typename datasetA,typename datasetB> auto _replace(datasetA *oldValue,datasetB newValue){
            *oldValue = newValue;
        }
        template<typename dataset> class _iterator{
            private:
                pointer<node<dataset>> _current;
            public:
                _iterator(pointer<node<dataset>> newNode): _current {newNode}{}
                auto &operator++(){
                    _current = _current->next;
                    return _current;
                }
                auto operator++(int){
                    auto retVal = *this;
                    ++(*this);
                    return retVal;
                }
                auto &operator--(){
                    _current = _current->prev;
                    return _current;
                }
                auto operator--(int){
                    auto retVal = *this;
                    --(*this);
                    return retVal;
                }
                auto *operator->(){
                    return &_current->value;
                }
                auto &operator*(){
                    return _current->value;
                }
                auto operator==(const auto &self){
                    return _current == self->_current;
                }
                auto operator!=(const auto &self){
                    return _current != self._current;
                }
                auto dir(){
                    return &_current->value;
                }
        };
    public:
        typedef _iterator<data> iterator;
        List(): _head{nullptr},_back{nullptr},_size{0}{}
        List(initializer_list<data> list){
            _head = _back = nullptr;
            _size = 0;
            for(auto i : list) push_back(i);
        }
        //Output functions
        auto empty(){
            return (not _head or not _back or _size == 0) ? true : false;
        }
        auto size(){
            return (_size > 0) ? _size : 0;
        }
        auto front(){
            return (_head != nullptr && !empty()) ? _head->value : data(NULL);
        }
        auto back(){
            return (_back != nullptr && !empty()) ? _back->value : data(NULL);
        }
        iterator begin(){
            return _head;
        }
        iterator end(){
            return _back->next;
        }
        auto print(const int begin = 0, int end = -1){
            if(begin == 0 and end == -1){
                auto t = *this;
                for(auto i : t) cout << i << " " ;
                cout << endl;
            }else{
                if(end == -1) end = _size;
                auto t = *this;
                for(auto i = begin; i < end ; i++) cout << t[i] << " " ;
                cout << endl;
            }
        }
        auto *operator+(const int index){
            auto t = _head;
            for(auto i = 0; i < index; i++, t = t -> next);
            return t;
        }
        auto &operator[](const int index){
            auto t = _head;
            for(auto i = 0; i < index; i++, t = t -> next);
            return t->value;
        }
        //Input functions
        auto push_front(data newValue){
            auto newNode = new node<data>(newValue);
            if(empty()) _head = _back = newNode;
            else{
                newNode -> next = _head;
                _head -> prev = newNode;
                _head = newNode;
            }
            _size++;
        }
        auto push_back(data newValue){
            auto newNode = new node<data>(newValue);
            if(empty()) _head = _back = newNode;
            else{
                newNode -> prev = _back;
                _back -> next = newNode;
                _back = newNode;
            }
            _size++;
        }
        auto pop_back(){
            if(empty()) return;
            else{
                _size--;
                auto tmp = _back;
                _back = _back -> prev;
                _back -> next = nullptr;
                delete(tmp);
            }
        }
        auto pop_front(){
            if(empty()) return;
            else{
                _size--;
                auto tmp = _head;
                _head = _head -> next;
                _head -> prev = nullptr;
                delete(tmp);
            }
        }
        auto sort(const size_t begin = 0, size_t end = -1)->void{
            //Based on mergesort implementation
            if(end == -1) end = _size-1;
            if(begin >= end - 1) return;
            auto array = *this;
            size_t mid = (begin + end) / 2;
            auto pivot = array[mid];
            //swapping elements
            auto t = array[begin], v = array[end];
            for(int i = begin, j = end ; i < j ; ){
                if(t < pivot) i++;
                else if(v > pivot) j--;
                else _swap(&array[i],&array[j]);
            }
            sort(begin,mid-1);
            sort(mid,end);
        }
};