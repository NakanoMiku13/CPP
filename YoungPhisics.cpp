#include<bits/stdc++.h>
using namespace std;
int n,matrix[101][4];
auto sumX()->int{
    int x=0;
    for(auto i=0;i<n;i++){
        x+=matrix[i][0];
    }
    return x;
}
auto sumY()->int{
    int x=0;
    for(auto i=0;i<n;i++){
        x+=matrix[i][1];        
    }
    return x;
}
auto sumZ()->int{
    int x=0;
    for(auto i=0;i<n;i++){
        x+=matrix[i][2];        
    }
    return x;
}
auto sumVector()->bool{
    if(sumX()!=0) return false;
    else if(sumY()!=0) return false;
    else if(sumZ()!=0) return false;
    return true;
}
auto main()->int{
    cin>>n;
    for(auto i=0; i<n; i++){
        for(auto j=0;j<3;j++){
            cin>>matrix[i][j];
        }
    }
    if(sumVector()) cout<<"YES";
    else cout<<"NO";
}