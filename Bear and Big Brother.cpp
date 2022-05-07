#include <bits/stdc++.h>
using namespace std;
auto main()->int{
    int a,b,c=0;
    cin>>a>>b;
    for(;a<=b;a*=3,b*=2,c++);
    cout<<c;
}