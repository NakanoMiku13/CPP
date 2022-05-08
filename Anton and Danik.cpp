#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    string rounds;
    int n,a=0,d=0;
    cin>>n;
    cin>>rounds;
    for(auto i:rounds)
        if(i=='A') a++;
        else d++;
    if(a>d) cout<<"Anton";
    else if (d>a) cout<<"Danik";
    else cout<<"Friendship";
}