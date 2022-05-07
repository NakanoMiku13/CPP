#include<bits/stdc++.h>
using namespace std;
auto convert(auto text)->string{
    string tmp="";
    for(auto i:text){
        char x = tolower(i);
        if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u' or x=='y') continue;
        else{
            tmp+='.';
            tmp+=x;
        }
    }
    return tmp;
}
auto main()->int{
    string text;
    cin>>text;
    cout<<convert(text);
}