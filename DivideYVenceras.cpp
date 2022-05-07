#include<bits/stdc++.h>
using namespace std;
auto convertToNumber(auto value)->long long int{
    long long int result=0;
    stringstream geek(value);
    geek>>result;
    return result;
}
auto getFirstHalf(auto value)->string{
    string tmp = "";
    int n = value.size();
    n/=2;
    for(auto i=0;i<n;i++) tmp+=value[i];
    return tmp;
}
auto getSecondHalf(auto value)->string{
    string tmp = "";
    int n = value.size(),z = value.size();
    n/=2;
    for(auto i=n;i<z;i++) tmp+=value[i];
    return tmp;
}
auto getProduct(const auto a,const auto b, const auto c, const auto d,const auto n)->long long int{
    //a = a primary, b = b primary, c = a bi primary, d = b bi primary
    auto x = n/2;
    return (pow(10,(2*x))*a*b)+(pow(10,x)*a*d)+(pow(10,x)*c*b)+(c*d);
}
auto main()->int{
    int n;
    string a,b;
    cin>>a>>b;
    n=a.size();
    auto a1=convertToNumber(getFirstHalf(a));
    auto a2=convertToNumber(getSecondHalf(a));
    auto b1=convertToNumber(getFirstHalf(b));
    auto b2=convertToNumber(getSecondHalf(b));
    auto x = getProduct(a1,b1,a2,b2,n);
    cout<<x;
}