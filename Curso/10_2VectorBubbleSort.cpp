#include<bits/stdc++.h>
using namespace std;
template<typename data> using pointer = data*;
template<typename data> struct node{
    public:
        data value;
        pointer<node> next,prev;
        node(data value) : value(value),prev(nullptr),next(nullptr){}
        template<typename val> friend ostream& operator<<(ostream&,pointer<node<val>>&);
};
template<typename dataset> auto operator<<(ostream& os,pointer<node<dataset>> data){
    os<<data->value;
    return os;
}
template<typename data> struct Vector{
    private:
        pointer<node<data>> _head,_back;
        size_t _size;
        #define not_head not _head
        #define not_back not _back
        #define emp not_head and not_back and _size==0
        #define insert if(empty()) _head = _back = newNode(value); else
        auto newNode(data value)->pointer<node<data>>{
            auto x = new node<data>(value);
            return x;
        }
        auto getValue(const int index){
            auto move = _head;
            for(int i=0;i<index;i++,move = move->next);
            return (move!=nullptr) ? move->value : data(NULL);
        }
        auto Swap(auto* valueA,auto* valueB){
            auto tmp = *valueA;
            *valueA = *valueB;
            *valueB = *tmp;
            cout<<valueA<<" "<<valueB<<endl;
        }
        auto getNode(const int index){
            auto move = _head;
            for(int i=0;i<index;i++,move = move->next);
            return (move!=nullptr) ? move : data(NULL);
        }
    public:
        Vector(): _head(nullptr),_size(0),_back(nullptr){}
        auto empty()-> bool{
            return (emp) ? true : false;
        }
        auto size()->size_t{
            return _size;
        }
        auto front()->data{
            return (!empty()) ? _head->value : data(NULL);
        }
        auto back()->data{
            return (!empty()) ? _back->value : data(NULL);
        }
        auto push_front(data value){
            auto new_Node = newNode(value);
            insert{
                new_Node->next = _head;
                _head->prev = new_Node;
                _head = new_Node;
            }
            _size++;
        }
        auto push_back(data value){
            auto new_Node = newNode(value);
            insert{
                new_Node->prev = _back;
                _back->next = new_Node;
                _back = new_Node;
            }
            _size++;
        }
        auto pop_back(){
            if(empty()) return;
            else{
                if(_head == _back){
                    delete _head;
                    _head = _back = nullptr;
                }else{
                    auto tmp = _back;
                    _back = _back->prev;
                    delete tmp;
                }
                _size--;
            }
        }
        auto pop_front(){
            if(empty()) return;
            else{
                if(_head == _back){
                    delete _head;
                    _head = _back = nullptr;
                }else{
                    auto tmp = _head;
                    _head = _head->next;
                    delete tmp;
                }
                _size--;
            }
        }
        auto &operator[](const int index){
            auto move = _head;
            for(int i=0;i<index;i++,move = move->next);
            return move->value;
        }
        auto operator+(const int index){
            return (!empty() && _size>0) ? getValue(index) : data(NULL);
        }
        auto swap2(const int indexA, const int indexB){
            auto a = getNode(indexA);
            auto b = getNode(indexB);
            Swap(&a->value,&b->value);
        }
        auto reverse(){
            
        }
        auto bubbleSort(){

        }
};
int main(){
    Vector<int> vectors;
    int n;
    cin>>n;
    for(auto i=0,x=0;i<n;i++){
        cin>>x;
        vectors.push_back(x);
    }
    cout<<endl;
    for(auto i=0;i<vectors.size();i++){
        cout<<vectors[i]<<" ";
    }
    vectors.swap2(0,1);
    cout<<endl;
    for(auto i=0;i<n;i++){
        auto x = vectors+i;
        cout<<x<<" ";
    }
    cout<<endl;
    while(!vectors.empty()){
        cout<<vectors.back()<<" ";
        vectors.pop_back();
    }
}