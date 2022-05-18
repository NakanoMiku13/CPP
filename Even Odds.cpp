#include<bits/stdc++.h>
using namespace std;
auto pairs(auto k,auto x,auto n)->unsigned long long int{
    auto y = k-x;
    if(y==n) return (y*2)-1;
    auto z = n-y;
    if(z<0) z*=-1;
    return z*2;
}
auto unpair(auto n)->unsigned long long int{
    return n+(n-1);
}
using namespace std;
auto main()->int{
    unsigned long long int n,m,x;
    cin>>n>>m;
    x=n/2;
    if(m<=x) cout<<unpair(m);
    else cout<<pairs(n,x,m);
}