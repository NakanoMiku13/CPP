//Usando librería MainLib.h
#include "MainLib.h"
using namespace std;
auto binarySearch(auto arr,const int begin,const int end,const auto x){
    int mid = (begin +  mid) / 2;
    if(begin >= end){
        if(x == arr[begin] or x == arr[mid] or arr[end] == x) return x;
        else return -1;
    }
    else{
        if(arr[mid] > x) return binarySearch(arr,begin,mid-1,x);
        else return binarySearch(arr,mid,end,x);
    }

}
auto main()->int{
    List<int> list = {9,1,3,2,0,5,4,6,8,7};
    list.print();
    list.sort();
    cout<<endl;
    list.print();
    cout<<endl;
    cout<<binarySearch(list,0,list.size(),2);
}