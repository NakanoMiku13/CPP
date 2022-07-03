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
    pointer<node<data>> head,back;
    size_t size;
    public:
        Queue(): head{nullptr},size{0}{}
    auto empty()->bool{
        return (not head && size<=0) ? true : false;
    }
    auto push(data value){
        auto newNode = new node<data>(value);
        if(empty()) head = back = newNode;
        else{
            auto tmp = back;
            back->next = newNode;
            back = newNode;
        }
        size++;
    }
    auto pop(){
        if(!empty()){
            auto tmp = head;
            head = head->next;
            delete tmp;
        }
        size--;
    }
    auto front()->data{
        return head->value;
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