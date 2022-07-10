#include <bits/stdc++.h>
using namespace std;
template<typename data>
using pointer = data*;
template<typename data>
struct node{
    data value;
    pointer<node> next,prev;
    public:
        node(data value): value{value},next{nullptr},prev{nullptr}{}
};
template<typename data>
struct Vector{
    private: pointer<node<data>> _head,_back;
    private: size_t _size;
    public:
        Vector(): _head{nullptr},_back{nullptr},_size{0}{}
    auto empty()->bool{
        return (_size==0 or not _head or not _back) ? true : false;
    }
    auto push_clear(data value){
        if(empty()) _head = _back = new node<data>(value);
        else{
            auto tmp = &_back;
            tmp++;
            *tmp = nullptr;
            *tmp = new node<data>(value);
            auto t = &_back;
            cout<<"back: "<<&_back<<" "<<_back<<" "<<++t<<endl;
            cout<<"tmp: "<<tmp<<" "<<*tmp<<endl;
            auto temp = _back;
            _back = *tmp;
            temp->next = _back;
            _back->prev = temp;
            cout<<_back<<" "<<temp<<endl;
        }
        _size++;
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
            auto tmp = _head;
            _head = _head->next;
            delete tmp;
        }
    }
    auto pop_back(){
        if(empty()) return;
        else{
            _size--;
            auto tmp = _back;
            _back = _back->prev;
            delete tmp;
        }
    }
    auto front()->data{
        return _head->value;
    }
    auto back()->data{
        return _back->value;
    }
    auto at(const int index)->data{
        if(index < _size){
            auto move = _head;
            for(auto i = 1; i <= index; i++,move=move->next);
            return move->value;
        }else{
            return (data)NULL;
        }
    }
    auto size()->size_t{
        return _size;
    }
    auto operator[](const int index)->data{
        if(index < _size){
            auto move = _head;
            for(auto i = 1; i <= index; i++,move=move->next);
            return move->value;
        }else{
            return (data)NULL;
        }
    }
    auto begin(){
        return &_head;
    }
    auto end(){
        return &_back;
    }
};
auto main()->int{
    Vector<int> vectorI;
    int n;
    cin>>n;
    for(auto i=0;i<n;i++){
        int x;
        cin>>x;
        vectorI.push_back(x);
    }
    for(auto i=0;i<n;i++){
        cout<<vectorI[i]<<endl;
    }
    cout<<endl;
    for(auto i=0;i<n;i++){
        cout<<vectorI.at(i)<<endl;
    }
    cout<<endl;
    while(!vectorI.empty()){
        cout<<vectorI.front()<<endl;
        vectorI.pop_front();
    }
}