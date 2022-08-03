#include<iostream>
using namespace std;
template<typename dataset> using pointer = dataset*;
template<typename data> struct node{
    public:
        data value;
        pointer<node> next,prev;
        node(data newValue): value(newValue),next(nullptr),prev(nullptr){}
};
template<typename data> struct Vector{
    private:
        pointer<node<data>> _head,_back;
        size_t _size;
        template<typename dataA,typename dataB> auto _swap(dataA a,dataB b)->void{
            auto t = *a;
            *a = *b;
            *b = t;
        }
        template<typename dataset> struct _iterator{
            private:
                pointer<node<dataset>> _current;
            public:
                _iterator(pointer<node<dataset>> _currentNode): _current(_currentNode){}
                auto &operator++(){
                    _current = _current->next;
                    return _current;
                }
                auto operator++(int){
                    auto retVal = *this;
                    ++(*this);
                    return retVal;
                }
                auto *operator->(){
                    return &_current->value;
                }
                auto &operator*(){
                    return _current->value;
                }
                auto operator==(const auto &_self){
                    return _current==_self->_current;
                }
                auto operator!=(const auto &_self){
                    return _current != _self._current;
                }
        };
        typedef _iterator<data> iterator;
    public:
        Vector(): _head(nullptr),_back(nullptr),_size(0){}
        auto empty(){
            return (_size==0 or not _head or not _back) ? true : false;
        }
        auto push_front(data newValue){
            auto newNode = new node<data>(newValue);
            if(empty()) _head = _back = newNode;
            else{
                _head->prev = newNode;
                newNode->next = _head;
                _head = newNode;
            }
            _size++;
        }
        auto push_back(data newValue){
            auto newNode = new node<data>(newValue);
            if(empty()) _head = _back = newNode;
            else{
                _back->next = newNode;
                newNode->prev = _back;
                _back = newNode;
            }
            _size++;
        }
        auto size(){
            return _size;
        }
        auto front(){
            return _head->value;
        }
        auto back(){
            return _back->value;
        }
        auto &operator[](const int index){
            auto move = _head;
            for(int i=0;i<index;i++,move=move->next);
            return move->value;
        }
        auto operator+(const int index){
            auto move = _head;
            for(int i=0;i<index;i++,move=move->next);
            return move->value;
        }
        auto begin()->iterator{
            return this->_head;
        }
        auto end()->iterator{
            return this->_back->next;
        }
        auto MergeSort(const int begin=0,int end=-1)->void{
            if(end==-1) end = _size-1;
            if(begin >= end-1) return;
            auto array = *this;
            int mid = (begin + end) / 2;
            auto pivot = array[mid];
            //swapping elements
            for(int i = begin,j = end; i < j; ){
                auto t = array[i], v = array[j];
                if(t < pivot) i++;
                else if(v > pivot) j--;
                else _swap(&array[i],&array[j]);
            }
            MergeSort(begin,mid-1);
            MergeSort(mid,end);
        }
};
auto main()->int{
    int n;
    Vector<int> v;
    cin>>n;
    for(int i=0,x;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    v.MergeSort();
    for(auto i:v) cout<<i<<" ";
}