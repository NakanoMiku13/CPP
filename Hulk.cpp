#include<bits/stdc++.h>
using namespace std;
pair<string,string> layers={"I hate", "I love"};
pair<string,string> layers2={" that "," it"};
auto main()->int{
    int n;
    cin>>n;
    if(n==1){
        cout<<layers.first<<layers2.second;
    }else{
        for(auto i=1;i<=n;i++){
            if(i%2==0) cout<<layers.second;
            else cout<<layers.first;
            if(i<n) cout<<layers2.first;
        }
        cout<<layers2.second;
    }
}