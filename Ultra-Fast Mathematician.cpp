#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b;
    cin>>a>>b;
    auto n = a.size();
    for(auto i=0;i<n;i++){
        if(a[i]!=b[i]) cout<<"1";
        else cout<<"0";
    }
}