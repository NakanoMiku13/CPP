#include<bits/stdc++.h>
using namespace std;
template<typename data>
using pointer = data*;
template<typename data>
class node{
    public:
        data value;
        pointer<node> next,prev;
        node(data value): value{value},next{nullptr},prev{nullptr}{}
        template<typename val>
        friend ostream& operator<<(ostream&,const pointer<node<val>>&);
        auto operator!=(const auto &compare){
            auto tmp = *this;
            if(compare->value!=tmp->value) return true;
            else return false;
        }
};
template<typename dataset>
ostream& operator<<(ostream& os,const pointer<node<dataset>>& val){
    os<<val->value;
    return os;
}
template<typename data>
class Vector{
    private:
        pointer<node<data>> _head,_back,_tmp;
        size_t _size;
        template<typename dataset>
        class _iterator{
            private:
                pointer<node<dataset>> current;
            public:
                _iterator(pointer<node<dataset>> currentNode): current(currentNode){}
                auto &operator++(){
                    current = current->next;
                    return current;
                }
                auto operator++(int){
                    auto retVal = *this;
                    ++(*this);
                    return retVal;
                }
                auto *operator->()const{
                    return &current->value;
                }
                auto &operator*()const{
                    return current->value;
                }
                auto operator==(const auto& self){
                    return current == self->current;
                }
                auto operator!=(const auto& self){
                    return current != self.current;
                }
        };
        typedef _iterator<data> iterator;
    public:
        Vector(): _head{nullptr},_back{nullptr},_size{0},_tmp{nullptr}{}
        Vector(initializer_list<data> initial){
            _head = _back = nullptr;
            _size = 0;
            for(auto i : initial) push_back(i);
        }
        auto empty()->bool{
            return (_size==0 or not _head or not _back) ? true : false;
        }
        auto push_back(data value){
            auto newNode = new node<data>(value);
            if(empty()) _head = _back = newNode;
            else{
                _back->next = newNode;
                newNode->prev = _back;
                _back = newNode;
            }
            _size++;
        }
        auto push_front(data value){
            auto newNode = new node<data>(value);
            if(empty()) _head = _back = newNode;
            else{
                _head->prev = newNode;
                newNode->next = _head;
                _head = newNode;
            }
            _size++;
        }
        auto pop_back(){
            if(empty()) return;
            else{
                _size--;
                if(_head == _back){
                    _head = _back = nullptr;
                    _size = 0;
                    return;
                }
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
                if(_head == _back){
                    _head = _back = nullptr;
                    _size = 0;
                    return;
                }
                auto tmp = _head;
                _head = _head -> next;
                _head -> prev = nullptr;
                delete(tmp);
            }
        }
        auto retVal(const int index)->data{
            auto tmp = _head;
            for(auto i=0;i<index;i++,tmp=tmp->next);
            return tmp->value;
        }
        auto front()->data{
            return (_head!=nullptr) ? _head->value : data(NULL);
        }
        auto back()->data{
            return (_back != nullptr) ? _back->value : data(NULL);
        }
        auto at(const int index)->data{
            return (index < _size) ? retVal(index) : data(NULL);
        }
        auto size()->size_t{
            return _size;
        }
        auto &operator[](const int index){
            if(index < _size && !empty()){
                auto tmp = _head;
                for(auto i=0;i<index;i++,tmp=tmp->next);
                return tmp->value;
            }
        }
        auto operator+(data newValue){
            Vector<data> retVector = *this;
            retVector.push_front(newValue);
            return retVector;
        }
        auto operator!=(const auto &compare){
            auto tmp = *this;
            if(compare->value!=tmp->value) return true;
            else return false;
        }
        iterator begin(){
            return this->_head;
        }
        iterator end(){
            return this->_back->next;
        }
};
auto merge(auto x,auto y)->Vector<int>{
    if(x.empty() or x.size()==0)return y;
    if(y.empty() or y.size()==0) return x;
    if(x[0] <= y[0]){
        auto v = x.front();
        x.pop_front();
        auto t = merge(x,y) + v;
        return t;
    }else{
        auto v = y.front();
        y.pop_front();
        auto t = merge(y,x) + v;
        return t;
    }
}
auto main()->int{
    Vector<int> a = {1,3,9,62,63}, b = {5,6,7,8,231,543};
    auto t = merge(a,b);
    for(auto i : t) cout<<i<<" ";
}
