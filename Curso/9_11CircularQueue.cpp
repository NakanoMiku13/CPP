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
    private: pointer<node<data>> head,back;
    private: size_t _size;
    public:
        CQueue(): head{nullptr},back{nullptr},_size{0}{}
    auto empty()->bool{
        return (not head and not back and _size == 0) ? true : false;
    }
    auto size()->size_t{
        return _size;
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
                head->prev = back;
                back->next = head;
                delete tmp;
            }
            _size--;
        }
    }
    auto front()->data{
        return (head!=nullptr) ? head->value : data(NULL);
    }
    auto begin(){
        return (head!=nullptr) ? head : NULL;
    }
    auto end(){
        return (back!=nullptr) ? back : NULL;
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
    auto tmp = circularQueues.begin();
    while(true){
        cout<<tmp->value<<" ";
        tmp=tmp->next;
    }
    cout<<"holi";
}