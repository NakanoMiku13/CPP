#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    int n,maxi=0;
    cin>>n;
    for(auto i=0; i<n; i++){
        int x,y;
        cin>>x;
        if(x==1){
            cin>>y;
            maxi=max(y,maxi);
        }else if(x==3){
            cout<<maxi<<endl;
        }
    }
}