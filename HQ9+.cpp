#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    string text;
    cin>>text;
    for(auto i:text){
        if(i=='H' or i=='Q' or i=='9'){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
}