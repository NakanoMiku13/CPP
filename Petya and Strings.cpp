#include<bits/stdc++.h>
using namespace std;
map<char,int> letters1,letters2;
auto toLowerString(auto convert)->string{
    string newS="";
    for(auto i:convert) newS+=tolower(i);
    return newS;
}
auto comparison(auto a,auto b)->int{
    if(a==b) return 0;
    else{
        auto n = a.size();
        auto s=0,s2=0;
        for(auto i:a) letters1[i]++;
        for(auto i:b) letters2[i]++;
        for(auto i='a';i<='z';i++){
            if(letters1[i]>0 && letters2[i]>0) {
                s+=i;
                s2+=i;
            }
            else{
                if(letters1[i]==0 && letters2[i]==0) continue;
                else if(letters1[i]>0 && letters2[i]==0) s+=i;
                else s2+=i;
            }
        }
        cout<<s<<" "<<s2<<endl;
        if(s2>s) return -1;
        return 1;
    }
}
auto main()->int{
    string a,b;
    cin>>a>>b;
    a=toLowerString(a);
    b=toLowerString(b);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout<<a<<" "<<b<<endl;
    cout<<comparison(a,b)<<endl;
}