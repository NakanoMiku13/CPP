#include <bits/stdc++.h>
using namespace std;
auto main()->int{
    int n,sum=0;
    cin>>n;
    for(auto i=0;i<n;i++){
        string x;
        cin>>x;
        if(x=="X++" or x=="++X") sum++;
        else sum--;
    }
    cout<<sum;
}