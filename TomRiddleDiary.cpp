#include<bits/stdc++.h>
using namespace std;
map<string,bool> maps;
auto main()->int{
    int n;
    cin>>n;
    string name;
    for(int i=0;i<n;i++){
        cin>>name;
        if(maps[name]) cout<<"YES\n";
        else{
            maps[name]=true;
            cout<<"NO\n";
        }
    }
}