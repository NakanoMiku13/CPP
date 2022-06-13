#include<bits/stdc++.h>
using namespace std;
auto verify(auto text,int i)->string{
    int n = text.size(),c=0;
    if(n<2 && i>=n) return "";
    string r = "",ret="";
    while(text[i]=='W' and text[i+1]=='U' and text[i+2]=='B' && i<n) i+=3;
    while(i<n){
        if(text[i]!='W' and text[i+1]!='U' and text[i+2]!='B') c++;
        cout<<c<<endl;
        r+=text[i];
        i++;
    }
    return (r+" ")+verify(r,i);
}
auto main()->int{
    string x;
    cin>>x;
    cout<<verify(x,0)<<endl;
}