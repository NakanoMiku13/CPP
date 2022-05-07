#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    int n,m;
    cin>>n>>m;
    for(auto i=0;i<m;i++){
        if(n%10==0) n/=10;
        else n--;
    }
    cout<<n;
}