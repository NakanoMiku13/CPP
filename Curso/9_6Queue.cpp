#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    queue<int> colaSimple;
    int n,x;
    cin>>n;
    for(auto i=0; i<n; i++){
        cin>>x;
        colaSimple.push(x);
    }
    cout<<endl;
    while(!colaSimple.empty()){
        cout<<colaSimple.front()<<endl;
        colaSimple.pop();
    }
}