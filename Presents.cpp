#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    int n;
    cin>>n;
    vector<int> v(0);
    for(auto i=0; i<n; i++){
        int x;
        cin>>x;
        x--;
        v.push_back(x);
    }
    for(auto i=0;i<n;i++){
        for(auto j=0;j<n;j++){
            if(v[j]==i) cout<<j+1<<" ";
        }
    }
}