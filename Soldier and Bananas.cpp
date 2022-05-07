#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    int n,k,w;
    unsigned long long int sum=0;
    cin>>k>>n>>w;
    for(auto i=0;i<w;i++,sum+=(i*k));

    if(n>=sum) cout<<0;
    else cout<<sum-n;
}