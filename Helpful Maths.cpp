#include<bits/stdc++.h>
using namespace std;
auto result(auto value)->string{
    string tmp="";
    queue<char> plus;
    for(auto i:value){
        if(i!='+'){
            tmp+=i;
        }else{
            plus.push(i);
        }
    }
    string out="";
    for(auto i:tmp){
        out+=i;
        if(!plus.empty()) {out+=plus.front(); plus.pop();}
    }
    return out;
}
auto main()->int{
    string x;
    cin>>x;
    sort(x.begin(), x.end());
    cout<<result(x);
}