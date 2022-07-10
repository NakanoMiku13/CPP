#include <bits/stdc++.h>
using namespace std;
template<typename data>
using pointer = data*;
template<typename data>
struct node{
    data value;
    pointer<node> prev,next;
    public:
        node(data value) : value{value},next{nullptr}{}
};
template<typename data>
struct CQueue{
    pointer<node<data>> head,back;
    size_t size;
    public:
        CQueue(): head{nullptr},back{nullptr},size{0}{}
    auto empty()->bool{
        return (not head or not back or size <= 0) ? true : false;
    }
    auto push(data value){
        auto newNode = new node<data>(value);
        if(empty()) head = back = newNode;
        else{
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
            back->next = head;
            head->prev = back;
        }
        size++;
    }
    auto pop(){
        if(empty()) return;
        else{
            auto tmp = head;
            head = head->next;
            head->prev = back;
            back->next = head;
            delete tmp;
            size--;
        }
    }
    auto front()->data{
        return head->value;
    }
};
auto main()->int{
    CQueue<int> circularQueues;
    int n,x;
    cin>>n;
    for(auto i=0;i<n;i++){
        cin>>x;
        circularQueues.push(x);
    }
    cout<<endl;
    while(!circularQueues.empty()){
        cout<<circularQueues.front()<<endl;
        circularQueues.pop();
    }
}