#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    string x;
    cin>>x;
    cout<<(char)toupper(x[0]);
    for(auto i=1;i<x.size();i++) cout<<(char)tolower(x[i]);
}