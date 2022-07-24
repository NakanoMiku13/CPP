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
template<typename dataset> struct _iterator{
    private:
        pointer<node<dataset>> _current;
    public:
        _iterator(pointer<node<dataset>> _currentNode) : _current(_currentNode){}
        auto &operator++(){
            _current = _current->next;
            return _current;
        }
        auto operator++(int){
            auto retVal = *this;
            ++(*this);
            return retVal;
        }
        auto *operator->()const{
            return &_current->value;
        }
        auto &operator*()const{
            return _current->value;
        }
        auto operator==(const auto &self){
            return _current == self->_current;
        }
        auto operator!=(const auto &self){
            return _current!= self._current;
        }
};
template<typename data> struct Vector{
    private:
        pointer<node<data>> _head,_back;
        size_t _size;
        #define not_head not _head
        #define not_back not _back
        #define emp not_head and not_back and _size==0
        #define insert if(empty()) _head = _back = _newNode(value); else
        typedef _iterator<data> iterator;
        auto _newNode(data value)->pointer<node<data>>{
            auto x = new node<data>(value);
            return x;
        }
        auto _getValue(const int index){
            auto move = _head;
            for(int i=0;i<index;i++,move = move->next);
            return (move!=nullptr) ? move->value : data(NULL);
        }
        template<typename valueA,typename valueB>
        auto _swap(valueA* nodeA,valueB* nodeB)->void{
            auto tmp = *nodeA;
            *nodeA = *nodeB;
            *nodeB = tmp;
        }
        auto _getNode(const int index){
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
            auto new_Node = _newNode(value);
            insert{
                new_Node->next = _head;
                _head->prev = new_Node;
                _head = new_Node;
            }
            _size++;
        }
        auto push_back(data value){
            auto new_Node = _newNode(value);
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
        auto bubble_Sort(){
            auto x = _head;
            for(int i=0;i<_size;i++,x=x->next){
                auto y = x;
                for(int j=i;j<_size;j++,y=y->next){
                    if(x->value>y->value) _swap(&x->value,&y->value);
                }
            }
        }
        /*auto bubble_Sort(){
            auto x = *this;
            for(int i=0;i<_size;i++){
                for(int j=i;j<_size;j++){
                    if(x[i]>x[j]) _swap(&x[i],&x[j]);
                }
            }
        }*/
        auto at(const int index){
            return (!empty()) ? _getValue(index) : data(NULL);
        }
        auto &operator[](const int index){
            auto move = _head;
            for(int i=0;i<index;i++,move = move->next);
            return move->value;
        }
        auto operator+(const int index){
            return (!empty() && _size>0) ? _getValue(index) : data(NULL);
        }
        iterator begin(){
            return this->_head;
        }
        iterator end(){
            return this->_back->next;
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
    cout<<endl<<"Antes de ordenar: "<<endl;
    for(auto i=0;i<vectors.size();i++){
        cout<<vectors[i]<<" ";
    }
    vectors.bubble_Sort();
    cout<<"\nDespues de ordenar: "<<endl;
    for(auto i:vectors){
        cout<<i<<" ";
    }

}