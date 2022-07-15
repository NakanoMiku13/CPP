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
    private: pointer<node<data,data2>> head,back;
    private: size_t _size;
    public:
        PQueue(): head{nullptr},back{nullptr},_size{0}{}
    auto empty()->bool{
        return (not head and _size==0) ? true : false;
    }
    auto push(data value,data2 priority){
        auto newNode = new node<data,data2>(value,priority);
        if(empty()) head = back = newNode;
        else{
            if(newNode->priority > head->priority){
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }else{
                auto move = head;
                for(;move->priority > newNode->priority and move->next!=nullptr;move=move->next);
                if(move->next != nullptr or (move->priority < newNode->priority && move->next == nullptr)){
                    auto tmp = move->prev;
                    tmp->next = newNode;
                    newNode->prev = tmp;
                    newNode->next = move;
                    move->prev = newNode;
                }else{
                    move->next = newNode;
                    newNode->prev = move;
                    back = newNode;
                }
            }
        }
        _size++;
    }
    auto pop(){
        if(empty()) return;
        else{
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
    auto size()->size_t{
        return _size;
    }
    auto front()->data{
        return (head!=nullptr)? head->value : data(NULL);
    }
    auto frontPriority()->data2{
        return (head!=nullptr)? head->priority : data(NULL);
    }
};
auto main()->int{
    int n,x,p;
    PQueue<int,int> colaDePrioridad;
    cin>>n;
    for( int i=0;i<n;i++){
        cin>>x>>p;
        colaDePrioridad.push(x,p);
    }
    cout<<endl<<endl;
    while(!colaDePrioridad.empty()){
        cout<<colaDePrioridad.front()<<endl;
        colaDePrioridad.pop();
    }
    return 0;
}