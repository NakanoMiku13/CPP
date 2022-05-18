#include<bits/stdc++.h>
using namespace std;
auto convertToNumber(auto value)->unsigned long long int{
    long long int result=0;
    stringstream geek(value);
    geek>>result;
    return result;
}
auto main()->int{
    string x;
    cin>>x;
    int count=0;
    auto z = convertToNumber(x);
    for(auto i:x){
        auto y = (int)i-48;
        if(y>0) if(z%y==0) count++;
    }
    cout<<count<<endl;
    return 0;
}