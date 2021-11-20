#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long a,b,c,n,m,maxi=0;
    cin>>n>>m;
    vector<long long> arr(n+1,0);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        for(int j=a;j<=b;j++){
            arr[j]+=c;
            maxi=max(maxi,arr[j]);
        }
    }
    cout<<maxi;
}