#include<bits/stdc++.h>
using namespace std;
string rocks;
int c,n;
auto Check()->void{
    for(int i=0;i<n;i++){
        if(rocks[i]==rocks[i+1]) c++;
    }
}
auto main()->int{
    cin>>n>>rocks;
    Check();
    cout<<c;
}