#include <bits/stdc++.h>
using namespace std;
map<char,int> letters;
auto result(auto s)->int{
    for(auto i:s) letters[i]++;
    return letters.size();
}
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string x;
    cin>>x;
    auto res = result(x);
    if(res%2==0) cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";
    
}