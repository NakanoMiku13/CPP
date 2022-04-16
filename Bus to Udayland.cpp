#include<bits/stdc++.h>
using namespace std;
char matrix[1010][7];
bool check=false;
auto main()->int{
    int n;
    cin>>n;
    for(auto i=0;i<n;i++){
        cin>>matrix[i][0]>>matrix[i][1]>>matrix[i][2]>>matrix[i][3]>>matrix[i][4];
        if(!check and matrix[i][0]=='O' and matrix[i][1]=='O'){
            check=true;
            matrix[i][0]=matrix[i][1]='+';
        }else if(!check and matrix[i][3]=='O' and matrix[i][4]=='O'){
            check=true;
            matrix[i][3]=matrix[i][4]='+';
        }
    }
    if(check) cout<<"YES\n";
    else{
        cout<<"NO\n";
        return 0;
    }
    for(auto i=0;i<n;i++){
        for(auto j=0;j<5;j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}