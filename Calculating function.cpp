#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    long long int n;
    cin>>n;
    if(n%2==0) cout<<n/2;
    else{
        long long int x = ((n+1)/2)*(-1);
        cout<<x;
    }
}