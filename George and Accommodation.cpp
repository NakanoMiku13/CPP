#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    int n,s=0;
    cin>>n;
    for(auto i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(abs(a-b)>=2) s++;
    }
    cout<<s;
}