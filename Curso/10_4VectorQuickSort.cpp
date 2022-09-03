#include<bits/stdc++.h>
using namespace std;
template<typename data> using pointer = data*;
template<typename data> struct node{
    private:
        #define emptyNode nullptr
    public:
        data value;
        pointer<node> next,prev;
        node(data newValue) : value(newValue),next(emptyNode),prev(emptyNode){}
};
template<typename data> struct Vector{
    private:
        pointer<node<data>> _head,_back;
        size_t _size;
        template<typename first, typename second> auto _swap(first* valueA,second* valueB){
            auto tmp = *valueA;
            *valueA = *valueB;
            *valueB = tmp;
        }
        template<typename dataset> struct _iterator{
            private:
                pointer<node<dataset>> _current;
            public:
                _iterator(pointer<node<dataset>> _currentNode): _current(_currentNode){}
                auto node(){
                    return _current;
                }
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
                auto &operator--(){
                    _current = _current->prev;
                    return _current;
                }
                auto operator--(int){
                    auto retVal = *this;
                    --(*this);
                    return retVal;
                }
                auto operator==(const auto &_self){
                    return _current==_self->_current;
                }
                auto operator!=(const auto &_self){
                    return _current!=_self._current;
                }
                auto dir(){
                    return &_current->value;
                }
        };
        typedef _iterator<data> iterator;
        auto _getValue(const int index){
            if(index > _size) return data(NULL);
            auto move = _head;
            for(int i=0;i<index;i++,move = move->next);
            return move->value;
        }
        #define emptyNode nullptr
    public:
        Vector(): _head(emptyNode),_back(emptyNode),_size(0){}
        auto empty()->bool{
            return (not _head or not _back or _size==0) ? true : false;
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
        auto pop_back(){
            if(empty()) return;
            else{
                if(_head == _back){
                    delete _head;
                    _head = _back = emptyNode;
                    _size=0;
                }else{
                    auto tmp = _back;
                    _back = _back->prev;
                    delete _back;
                    _size--;
                }
            }
        }
        auto pop_front(){
            if(empty()) return;
            else{
                if(_head == _back){
                    delete _head;
                    _head = _back = emptyNode;
                    _size=0;
                }else{
                    auto tmp = _head;
                    _head = _head->next;
                    delete tmp;
                    _size--;
                }
            }
        }
        auto at(const int index){
            return (index <= _size and !empty()) ? _getValue(index) : data(NULL);
        }
        auto &operator[](const int index){
            auto move = _head;
            for(int i=0;i<index;i++,move = move->next);
            return move->value;
        }
        auto *operator+(const int index){
             auto move = _head;
            for(int i=0;i<index;i++,move = move->next);
            return move;
        }
        iterator begin(){
            return (!empty()) ? _head : NULL;
        }
        iterator end(bool foreach=true){
            if(foreach) return (!empty()) ? _back->next : NULL;
            else return (!empty()) ? _back : NULL;
        }
        auto back(){
            return _back->value;
        }
        auto front(){
            return _head->value;
        }
        auto size(){
            return _size;
        }
        auto reverse(){
            auto tmp1 = _head,tmp2 = _back;
            auto t = _size/2;
            for(int i=0 ; tmp1!=tmp2 && i < t; tmp1=tmp1->next , tmp2=tmp2->prev, i++) _swap(&tmp1->value,&tmp2->value);
        }
        auto quickSort(const int begin = 0, int end = -1)->void{
            auto array = *this;
            if(end == -1) end = _size - 1;
            iterator b = array+begin, e = array+end;
            if(begin>=end){
                return;
            }else if(begin+1 == end or begin == end-1){
                if(*b > *e) _swap(b.dir(),e.dir());
                return;
            }
            auto pivot = *b;
            int i = begin, j = end, pos = 0;
            while(i <= j){
                if(*b < pivot){
                    b++;
                    i++;
                }else{
                    if(*e > pivot){
                        e--;
                        j--;
                    }else{
                        _swap(b.dir(),e.dir());
                        if(*b==pivot) pos = i;
                        else if(*e==pivot) pos = j;
                        b++;
                        e--;
                        i++;
                        j--;
                    }
                }
            }
            //for(int x = begin; x <= end;x++) if(array[x]==pivot){pos = x; break;}
            //left
            quickSort(begin,pos);
            //right
            quickSort(pos+1,end);
        }
};

auto main()->int{
    int n;
    Vector<int> v;
    cin>>n;
    for(auto i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    v.quickSort();
    cout<<endl<<"Despues de ordenar:\n";
    for(auto i:v){
        cout<<i<<" ";
    }
}