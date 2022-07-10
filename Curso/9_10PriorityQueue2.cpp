#include<bits/stdc++.h>
using namespace std;
template<typename data>
using pointer = data*;
template<typename data>
struct node{
    data value;
    pointer<node> next,prev;
    public:
        node(data value): value{value},next{nullptr}{}
};
template<typename data>
struct PQueue{
    pointer<node<data>> head,back;
    size_t size;
    public:
        PQueue(): head{nullptr},back{nullptr},size{0}{}
    auto empty()->bool{
        return (not head && size<=0) ? true : false;
    }
    auto push(data value){
        auto newNode = new node<data>(value);
        if(empty()) head = back = newNode;
        else{
            if(head->value <= newNode->value){
                auto tmp = head;
                head = newNode;
                tmp->prev = newNode;
                head->next = tmp;
            }else{
                auto move = head;
                while(move->next != nullptr){
                    if(move->value < newNode->value){
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
};
auto main()->int{
    int n,x;
    PQueue<int> colaDePrioridad;
    cin>>n;
    for( int i=0;i<n;i++){
        cin>>x;
        colaDePrioridad.push(x);
    }
    cout<<endl;
    while(!colaDePrioridad.empty()){
        cout<<colaDePrioridad.front()<<endl;
        colaDePrioridad.pop();
    }
    return 0;
}