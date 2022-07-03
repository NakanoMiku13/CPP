#include <bits/stdc++.h>
using namespace std;
auto main()->int{
    int n,x;
    stack<int> pila;
    cin>>n;
    for(auto i=0;i<n;i++){
        cin>>x;
        pila.push(x);
    }
    cout<<endl;
    while(!pila.empty()){
        cout<<pila.top()<<endl;
        pila.pop();
    }

}