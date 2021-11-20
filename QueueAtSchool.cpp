#include<bits/stdc++.h>
using namespace std;
int n,m;
string sk;
void order(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(sk[j]=='B' && sk[j+1]=='G'){ swap(sk[j],sk[j+1]); j++;}
        }
    }
}
auto main()->int{
    cin>>n>>m;
    cin>>sk;
    order();
    cout<<sk;
}