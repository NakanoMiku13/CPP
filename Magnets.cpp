#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    long long int s=0;
    cin>>n;
    string tmp="";
    string magnets;
    for(auto i=0;i<n;i++){
        cin>>magnets;
        if(tmp != magnets){
            tmp=magnets;
            s++;
        }
    }
    cout<<s;
}