#include<iostream>
using namespace std;
template <typename data>
using pointer = data*;
template <typename data>
struct node{
    data value;
    pointer<node> next,prev;
    public:
        node(data value): value{value},next{nullptr},prev{nullptr}{}
};
template<typename data>
struct List{
    private: pointer<node<data>> cabeza,espalda;
    private: size_t size;
    public:
        List(): cabeza{nullptr},espalda{nullptr},size{0}{}
    auto empty()->bool{
        return (size==0 or not cabeza or not espalda) ? true : false;
    }
    auto push_back(data pedritoSola){
        auto newNode = new node<data>(pedritoSola);
        if(empty()) cabeza = espalda = newNode;
        else{
            newNode->prev=espalda;
            espalda->next = newNode;
            espalda = newNode;
        }
        size++;
    }
    auto push_front(data value){
        auto newNode = new node<data>(value);
        if(empty()) cabeza = espalda = newNode;
        else{
            cabeza->prev = newNode;
            newNode->next = cabeza;
            cabeza = newNode;
        }
        size++;
    }
    auto pop_front(){
        if(empty()) return;
        else{
            size--;
            if(cabeza == espalda) {delete cabeza; cabeza = espalda = nullptr;}
            else{
                auto tmp = cabeza;
                cabeza = cabeza->next;
                cabeza->prev = nullptr;
                delete tmp;
            }
        }
    }
    auto front()->data{
        return (cabeza!=nullptr) ? cabeza->value : data(NULL);
    }
    auto back()->data{
        return (espalda!=nullptr) ? espalda->value : data(NULL);
    }
    auto pop_back(){
        if(empty()) return;
        else{
            size--;
            if(cabeza == espalda) {delete cabeza; cabeza = espalda = nullptr;}
            else{
                auto tmp = espalda;
                espalda = espalda->prev;
                espalda->next = nullptr;
                delete tmp;
            }
        }
    }
    auto push_middle(data value){
        if(empty()) push_front(value);
        else{
            auto newNode = new node<data>(value);
            auto mid = (size/2)-1;
            auto move = cabeza;
            for(int i=0;i<mid;i++,move = move->next);
            auto tmp1 = move;
            auto tmp2 = move->next;
            tmp1->next = newNode;
            newNode->prev = tmp1;
            newNode->next = tmp2;
            tmp2->prev = newNode;
            size++;
        }
    }
    auto push_at(data value,int position){
        position--;
        if(empty()) push_front(value);
        else if(position == 0) push_front(value);
        else if(position == size-1) push_back(value);
        else{
            auto move = cabeza;
            auto newNode = new node<data>(value);
            position--;
            for(int i=0;i<position;i++,move = move->next);
            auto tmp1 = move;
            auto tmp2 = move->next;
            tmp1->next = newNode;
            newNode->prev = tmp1;
            newNode->next = tmp2;
            tmp2->prev = newNode;
            size++;
        }
    }
    auto length()->size_t{
        return size;
    }
};
int main(){
   List<int> lista;
   lista.push_back(1);
   lista.push_back(2);
   lista.push_back(3);
   lista.push_back(4);
   lista.push_front(6);
   lista.push_middle(5);
   lista.push_middle(15);
   lista.push_at(35,1);
   lista.push_at(100,8);
   lista.push_at(500,3);
   lista.push_at(600,7);
   while(!lista.empty()){
    cout<<lista.front()<<endl;
    lista.pop_front();
   }
   cout<<"holiii";
}