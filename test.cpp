#include<bits/stdc++.h>
using namespace std;
auto buildTriangle(auto height){
    for(auto i=0;i<=height;i++){
        for(auto j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
auto main()->int{
    int amountTriangles,height;
    cin>>amountTriangles>>height;
    for(auto i=0;i<amountTriangles;i++){
        buildTriangle(height);
    }
}