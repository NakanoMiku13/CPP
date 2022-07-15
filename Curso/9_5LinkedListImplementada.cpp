#include<bits/stdc++.h>
using namespace std;
template<typename data>
using pointer = data*;
template<typename data>
struct node{
    data value;
    pointer<node> next, prev;
    public:
        node(data value): value{value},next{nullptr},prev{nullptr}{}
};
template <typename data>
struct LinkedList{
    pointer<node<data>> head, back;
    size_t size;
    public:
        LinkedList(): head{nullptr},back{nullptr},size{0}{}
    auto empty()->bool{
        return (not head and not back and size<=0) ? true : false;
    }
    auto push_back(data value){
        auto newNode = new node<data>(value);
        if(empty()){
            head = back = newNode;
            back->prev = head;
        }else{
            back->next = newNode;
            auto tmp = back;
            back = newNode;
            back->prev = tmp;
        }
        size++;
    }
    auto push_front(data value){
        auto newNode = new node<data>(value);
        if(empty()){
            head = back = newNode;
            back->prev = head;
        }else{
            head->prev = newNode;
            auto tmp = head;
            head = newNode;
            head->next = tmp;
        }
        size++;
    }
    auto pop_back(){
        if(empty()) return;
        else{
           if(back->prev!=nullptr && back!=head){
                auto tmp = back;
                back = back->prev; 
            }
            else{
                delete head;
                head = back = nullptr;
            }
        }
        size--;
    }
    auto pop_front(){
        if(empty()) return;
        else{
            if(head->next!=nullptr){
                auto tmp = head;
                head = head->next;
            }else{
                delete head;
                head = back = nullptr;
            }
        }
        size--;
    }
    auto Front()->data{
        return (!not head) ? head->value : data(NULL);
    }
    auto Back()->data{
        return (!not back) ? back->value : data(NULL);
    }
    auto clear(){
        while(!empty() && head->next!=nullptr){
            auto tmp = head;
            head = head->next;
            delete tmp;
        }
        head = back = nullptr;
    }
};
auto main()->int{
    LinkedList<int> lista;
    int n;
    cin>>n;
    for(auto i=0;i<n;i++){
        int x;
        cin>>x;
        lista.push_back(x);
    }
    auto tmp = lista;
    cout<<endl<<endl;
    while(!tmp.empty()){
        cout<<tmp.Front()<<endl;
        tmp.pop_front();
    }
    cout<<endl<<endl;
    tmp = lista;
    while(!tmp.empty()){
        cout<<tmp.Back()<<endl;
        tmp.pop_back();
    }
    lista.clear();
}