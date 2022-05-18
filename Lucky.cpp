#include<bits/stdc++.h>
using namespace std;
auto convert(auto number)->int{
    return (int)number-48;
}
auto isLucky(auto ticket)->bool{
    int s=0,c=0;
    for(auto i=0;i<3;i++)
        s+=convert(ticket[i]);
    for(auto i=3;i<6;i++)
        c+=convert(ticket[i]);
    if(s==c) return true;
    return false;
}
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(auto i=0;i<n;i++){
        string ticket;
        cin>>ticket;
        if(isLucky(ticket)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}