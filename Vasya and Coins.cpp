#include<bits/stdc++.h>
using namespace std;
auto sumProds(auto a,auto b){
    return a+b;
}
auto product(auto a,int multplier){
    return a*multplier;
}
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(auto i=0;i<n;i++){
        auto a=0,b=0;
        cin>>a>>b;
        if((a>0 and b>0) or (a>0 and b==0) or (a==0 and b==0)) cout<<sumProds(product(a,1),product(b,2))+1<<"\n";
        else cout<<1<<"\n";
    }
}