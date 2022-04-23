#include<bits/stdc++.h>
using namespace std;
int cA,cB;
auto whileA(auto check,int ini)->int{
    int i=ini;
    while(check[i]=='a'){
        i++;
        cA++;
    }
    return i;
}
auto whileB(auto check,int ini)->int{
    int i=ini;
    while(check[i]=='b'){
        i++;
        cB++;
    }
    return i;
}
auto verify(auto check)->bool{
    int n=check.size();
        int i=0;
        while(i<n){
            if(check[i]=='a'){
                cA=0;
                i=whileA(check,i);
                if(cA<2) return false;
            }else{
                cB=0;
                i=whileB(check,i);
                if(cB<2) return false;
            }
        }
        return true;
}
auto main()->int{
    int n;
    cin>>n;
    for(auto i = 0; i < n;i++){
        string check;
        cin>>check;
        if(verify(check) && check.size()>1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
