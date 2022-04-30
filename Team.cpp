#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    int n,counter=0;
    cin>>n;
    for(auto i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if((a==1 && b==1 && c==1) or (a==1 && b==1) or (b==1 && c==1) or (c==1 && a==1)) counter++;
    }
    cout<<counter;
}