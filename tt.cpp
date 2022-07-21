#include<bits/stdc++.h>
using namespace std;
template<typename data> using pointer = data*;
template<typename data> struct node{
    data value;
    pointer<node> next,prev;
    public:
        node(data value) : value{value}, next{nullptr},prev{nullptr}{}
};
template<typename index,typename data> struct Map{
    private: pointer<node<data>> _head,_back;
    private: size_t _size;
    public:
        Map(): _head{nullptr},_back{nullptr},_size{0}{}
    auto size()->size_t{
        return _size;
    }
    auto empty()->bool{
        return (_size==0 and not _head and not _back) ? true : false;
    }
    auto operator[](index index){
        
    }
};