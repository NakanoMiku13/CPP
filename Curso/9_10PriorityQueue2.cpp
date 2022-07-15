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
    private: pointer<node<data>> head,back;
    private: size_t _size;
    public:
        PQueue(): head{nullptr},back{nullptr},_size{0}{}
    auto empty()->bool{
        return (not head or _size<=0) ? true : false;
    }
    auto size()->size_t{
        return _size;
    }
    auto push(data value){
        auto newNode = new node<data>(value);
        if(empty()) head = back = newNode;
        else{
            if(newNode->value > head->value){
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }else{
                auto move = head;
                for(;move->value > newNode->value && move->next!=nullptr;move = move->next);
                if(move->next != nullptr or (move->value < newNode->value && move->next == nullptr)){
                    auto tmp = move->prev;
                    tmp->next = move->prev = newNode;
                    newNode->next = move;
                    newNode->prev = tmp;
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
        if(!empty()){
            auto tmp = head;
            head = head->next;
            delete tmp;
        }
        _size--;
    }
    auto front()->data{
        return (head!=nullptr)? head->value : data(NULL);
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