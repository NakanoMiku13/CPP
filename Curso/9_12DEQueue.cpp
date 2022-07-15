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
    private: pointer<node<data>> head,_back;
    private: size_t _size;
    public:
        DEQueue(): head{nullptr},_back{nullptr},_size{0}{}
    auto empty()->bool{
        return (not head and not _back and _size ==0) ? true : false;
    }
    auto size()->size_t{
        return _size;
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
        _size++;
    }
    auto push_back(data value){
        auto newNode = new node<data>(value);
        if(empty()) head = _back = newNode;
        else{
            _back->next = newNode;
            newNode -> prev = _back;
            _back = newNode;
        }
        _size++;
    }
    auto pop_front(){
        if(empty()) return;
        else{
            if(head == _back){
                delete head;
                head = _back = nullptr;
            }else{
                auto tmp = head;
                head = head->next;
                delete tmp;
            }
            _size--;
        }
    }
    auto pop_back(){
        if(empty()) return;
        else{
            if(head == _back){
                delete head;
                head = _back = nullptr;
            }else{
                 auto tmp = _back;
                _back = _back->prev;
                delete tmp;
            }
            _size--;
        }
    }
    auto front()->data{
        return (head!=nullptr) ? head->value : data(NULL);
    }
    auto back()->data{
        return (_back!=nullptr) ? _back->value : data(NULL);
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