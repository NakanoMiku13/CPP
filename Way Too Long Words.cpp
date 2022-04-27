#include <bits/stdc++.h>
using namespace std;
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(auto i = 0; i < n;i++){
        string x;
        cin>>x;
        int y=x.size();
        if(y>10)cout<<x[0]<<y-2<<x[y-1]<<endl;
        else cout<<x<<endl;
    }
}