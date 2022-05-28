#include<bits/stdc++.h>
using namespace std;
map<int,int> groups;
auto main()->int{
    int n,s=0,x,index=1;
    cin>>n;
    for(auto i=0;i<n;i++,index++){
        cin>>x;
        groups[x]++;
    }
    for(auto i=1;i<=4;i++) cout<<"g"<<i<<" "<<groups[i]<<endl;
}