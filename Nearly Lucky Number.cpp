#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    string x;
    cin>>x;
    int count7=0,count4=0;
    for(auto i:x)
        if(i=='7') count7++;
        else if (i=='4') count4++;
    if(count7+count4)==7 or (count7+count4)==4 or (count7==7 and count4<4) or (count4==4 and count7<7)) cout<<"YES";
    else cout<<"NO";
}