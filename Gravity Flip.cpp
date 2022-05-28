#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    int n,x;
    cin>>n;
    vector<int> v(0);
    for(auto i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(auto i:v) cout<<i<<" ";
}