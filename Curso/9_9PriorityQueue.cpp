#include<bits/stdc++.h>
using namespace std;
template<typename data>
using pointer = data*;
template<typename data,typename data2>
struct node{
    data value;
    data2 priority;
    pointer<node> next,prev;
    public:
        node(data value,data2 priority): value{value},priority{priority},next{nullptr}{}
};
template<typename data,typename data2>
struct PQueue{
    pointer<node<data,data2>> head,back;
    size_t size;
    public:
        PQueue(): head{nullptr},back{nullptr},size{0}{}
    auto empty()->bool{
        return (not head and size<=0) ? true : false;
    }
    auto push(data value,data2 priority){
        auto newNode = new node<data,data2>(value,priority);
        if(empty()) head = back = newNode;
        else{
            if(head->priority < newNode->priority){
                auto tmp = head;
                head = newNode;
                tmp->prev = newNode;
                head->next = tmp;
            }else{
                auto move = head;
                while(move->next != nullptr){
                    if(move->priority < newNode->priority){
                        auto tmp = move;
                        move->prev->next = newNode;
                        move = newNode;
                        newNode->next = tmp;
                        size++;
                        return;
                    }
                    move = move -> next;
                }
                move->next = newNode;
            }
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
    auto frontPriority()->data2{
        return head->priority;
    }
};
auto main()->int{
    int n,x,p;
    PQueue<int,bool> colaDePrioridad;
    cin>>n;
    for( int i=0;i<n;i++){
        cin>>x>>p;
        colaDePrioridad.push(x,p);
    }
    cout<<endl;
    while(!colaDePrioridad.empty()){
        cout<<colaDePrioridad.front()<<endl;
        colaDePrioridad.pop();
    }
    return 0;
}