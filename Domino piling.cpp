#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    int n,m;
    cin>>n>>m;
    auto x = n*m;
    if(x%2==0) cout<<x/2;
    else cout<<(x-1)/2;
}