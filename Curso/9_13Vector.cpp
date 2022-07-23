#include <bits/stdc++.h>
using namespace std;
template<typename data>
using pointer = data*;
template<typename data>
struct node{
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
template<typename dataset>
struct _iterator{
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
template<typename data>
struct Vector{
    private:
        typedef _iterator<data> iterator;
        pointer<node<data>> _head,_back,_tmp;
        size_t _size;
    public:
        Vector(): _head{nullptr},_back{nullptr},_size{0},_tmp{nullptr}{}
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
        auto pop_front(){
            if(empty()) return;
            else{
                _size--;
                if(_head == _back){
                    delete _head;
                    _head = _back = nullptr;
                }else{
                    auto tmp = _head;
                    _head = _head->next;
                    delete tmp;
                }
            }
        }
        auto pop_back(){
            if(empty()) return;
            else{
                _size--;
                if(_head == _back){
                    delete _head;
                    _head = _back = nullptr;
                }else{
                    auto tmp = _back;
                    _back = _back->prev;
                    delete tmp;
                }
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
        auto operator+(const int index){
            return (!empty()) ? retVal(index):NULL;
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
auto main()->int{
    int n;
    Vector<int> vectorI;
    cin>>n;
    for(auto i=0;i<n;i++){
        int x;
        cin>>x;
        vectorI.push_back(x);
    }
    cout<<"Tradicional: "<<endl;
    for(auto i=0;i<n;i++){
        cout<<vectorI[i]<<" ";
    }
    cout<<"\nCon asignacion: "<<endl;
    for(auto i=0;i<n;i++){
        auto x = vectorI[i];
        cout<<x<<" ";
    }
    cout<<"\nFuncion at: "<<endl;
    for(auto i=0;i<n;i++){
        cout<<vectorI.at(i)<<" ";
    }
    cout<<"\nAritmetica de apuntadores: "<<endl;
    for(auto i=0;i<vectorI.size();i++){
        auto x = vectorI+i;
        cout<<x<<" ";
    }
    cout<<"\nForeach: "<<endl;
    for(auto i : vectorI){
        cout<<i<<" ";
    }
    cout<<"\nWhile empty: "<<endl;
    while(!vectorI.empty()){
        cout<<vectorI.front()<<" ";
        vectorI.pop_front();
    }
}