#include<bits/stdc++.h>
using namespace std;
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
        for(auto i:a) s+=(int)i;
        for(auto i:b) s2+=(int)i;
        cout<<s<<endl<<s2<<endl;
        if(s>=s2) return 1;
        else return -1;
    }
}
auto main()->int{
    string a,b;
    cin>>a>>b;
    a=toLowerString(a);
    b=toLowerString(b);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout<<comparison(a,b);
}