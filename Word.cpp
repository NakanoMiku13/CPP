#include<bits/stdc++.h>
using namespace std;
auto compare(string value)->int{
    int upper=0,lower=0;
    for(auto i:value){
        if(i==toupper(i)) upper++;
        else lower++;
    }
    if(upper>lower) return 1;
    else if (lower>upper) return 2;
    else return -1;
}
auto toLower(string value)->string{
    string tmp = "";
    for(auto i:value) tmp+=tolower(i);
    return tmp;
}
auto toUpper(string value)->string{
    string tmp = "";
    for(auto i:value) tmp+=toupper(i);
    return tmp;
}
auto main()->int{
    string n;
    cin>>n;
    int x = compare(n);
    if(x==1){
        cout<<toUpper(n);
    }else{
        cout<<toLower(n);
    }
}