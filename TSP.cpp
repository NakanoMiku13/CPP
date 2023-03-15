#include<bits/stdc++.h>
using namespace std;
template<typename datatype>
using pointer = datatype*;
template<typename datatype> class node{
    public:
        datatype value;
        vector<pointer<node>> connections;
        node(datatype value, initializer_list<pointer<node>> nodes): value(value), connections(nodes){}
        node(){
            value = NULL;
            connections = vector<pointer<node>>();
        }
        node(datatype value): value(value){
            connections = vector<pointer<node>>();
        }
};
auto main()->int{
    return 0;
}
//template<typename> 