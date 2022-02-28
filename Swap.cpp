//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//Swap
#include<bits/stdc++.h>
using namespace std;
//Swap function
//This function allow us to swap to values with out move all the memory spaces, in this case is very useful to swap values on an array
auto Swap(int* a,int* b)-> void{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
auto main()->int{
    int a=50,b=100;
    cout<<a<<" "<<b<<endl;
    Swap(&a,&b);
    cout<<a<<" "<<b<<endl;
}