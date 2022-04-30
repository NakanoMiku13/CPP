#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k,c=0;
    cin>>n>>k;
    vector<int> vect(0);
    for(auto i=0, y=0;i<n;i++){
        cin>>y;
        vect.push_back(y);
    }
    for(auto i:vect) if(i>0 && i>=vect[k-1]) c++;
    cout<<c;
}