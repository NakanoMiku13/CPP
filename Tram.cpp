#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,maxi=0,tmp=0,a=0,b=0;
    cin>>n;
    for(auto i=0;i<n;i++,tmp-=a,tmp+=b){
        cin>>a>>b;
        maxi=max(tmp,maxi);
    }
    cout<<maxi;
}