#include <bits/stdc++.h>
using namespace std;
template<typename data>
using pointer = data*;
template<typename data>
struct node{
    data value;
    pointer<node> next,prev;
    public:
        node(data value) : value{value},next{nullptr},prev{nullptr}{}
};
template<typename data>
struct DEQueue{
    pointer<node<data>> head,_back;
    size_t size;
    public:
        DEQueue(): head{nullptr},_back{nullptr},size{0}{}
    auto empty()->bool{
        return (not head or not _back or size <=0) ? true : false;
    }
    auto push_front(data value){
        auto newNode = new node<data>(value);
        if(empty()) head = _back = newNode;
        else{
            head->prev = newNode;
            auto tmp = head;
            head = newNode;
            head->next = tmp;
        }
        size++;
    }
    auto push_back(data value){
        auto newNode = new node<data>(value);
        if(empty()) head = _back = newNode;
        else{
            _back->next = newNode;
            newNode -> prev = _back;
            _back = newNode;
        }
        size++;
    }
    auto pop_front(){
        if(empty()) return;
        else{
            size--;
            auto tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    auto pop_back(){
        if(empty()) return;
        else{
            size--;
            auto tmp = _back;
            _back = _back->prev;
            delete tmp;
        }
    }
    auto front()->data{
        return head->value;
    }
    auto back()->data{
        return _back->value;
    }
};
auto main()->int{
    DEQueue<int> dequeue;
    int n;
    cin>>n;
    for(auto i=0;i<n;i++){
        int x;
        cin>>x;
        dequeue.push_back(x);
    }
    while(!dequeue.empty()){
        cout<<dequeue.back()<<endl;
        dequeue.pop_back();
    }
}