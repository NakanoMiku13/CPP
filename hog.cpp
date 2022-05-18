#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,maxi=0;
    cin>>n;
    int x = n/2;
    for(int i=x;i>0;i--){
        int y = abs((i*2)-n),k=y/2;
        maxi=max(maxi,k*i);
    }
    int maxis=maxi;
    cout<<maxis;
    return 0;
}