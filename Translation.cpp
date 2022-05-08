#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    string a,b;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    if(a==b)cout<<"YES";
    else cout<<"NO";
}