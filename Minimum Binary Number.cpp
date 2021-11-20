#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    if(s[0]=='0') cout<<"0\n";
    else{
        cout<<"1";
        for(int i=1;i<n;i++) if(s[i]=='0') cout<<"0";
        cout<<"\n";
    }
}