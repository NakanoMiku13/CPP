#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,x;
    cin>>n;
    long long int counter=0,maxi=0,tmp=0;
    for(auto i=0;i<n;i++){
        cin>>x;
        if(tmp<=x) {counter++;}
        else {maxi=max(maxi,counter); counter=1;}
        tmp=x;
    }
    maxi=max(counter,maxi);
    cout<<maxi;
}