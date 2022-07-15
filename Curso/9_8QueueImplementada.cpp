#include<bits/stdc++.h>
using namespace std;
template<typename data>
using pointer = data*;
template<typename data>
struct node{
    data value;
    pointer<node> next;
    public:
        node(data value): value{value},next{nullptr}{}
};
template<typename data>
struct Queue{
    private: pointer<node<data>> head,back;
    private: size_t _size;
    public:
        Queue(): head{nullptr},back{nullptr},_size{0}{}
    auto empty()->bool{
        return (not head and _size==0) ? true : false;
    }
    auto size()->size_t{
        return _size;
    }
    auto push(data value){
        auto newNode = new node<data>(value);
        if(empty()) head = back = newNode;
        else{
            back->next = newNode;
            back = newNode;
        }
        _size++;
    }
    auto pop(){
        if(!empty()){
            if(head == back){
                delete head;
                head = back = nullptr;
            }else{
                auto tmp = head;
                head = head->next;
                delete tmp;
            }
            _size--;
        }
    }
    auto front()->data{
        return (head!=nullptr)? head->value : data(NULL);
    }
};
auto main()->int{
    int n,x;
    Queue<int> colaSimple;
    cin>>n;
    for( int i=0;i<n;i++){
        cin>>x;
        colaSimple.push(x);
    }
    cout<<endl;
    while(!colaSimple.empty()){
        cout<<colaSimple.front()<<endl;
        colaSimple.pop();
    }
}