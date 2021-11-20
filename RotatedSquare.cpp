#include<bits/stdc++.h>
using namespace std;
vector<int> results(4,0);
vector<string> Rotate(vector<string> comp,int n){
    vector<string> ret(n,"");
    for(int i=0;i<n;i++){
        for(int j=0,k=n-1;j<n;j++,k--){
            ret[i][j]=comp[k][i];
        }
    }
    return ret;
}
vector<string> Segment(vector<string> face,int n,int ini){
    vector<string> ret(n,"");
    for(int i=ini;i<n;i++){
        for(int j=ini;j<n;j++){

        }
    }
}
int Count(vector<string> face,vector<string> comp,const int n,const int m){
    
}
int main(){
    int n,m;
    do{
        cin>>n>>m;
        vector<string> mains(0,""),comp(0,""),tp;
        for(int i=0;i<n;i++){
            string x;
            cin>>x;
            mains.push_back(x);
        }
        for(int i=0;i<m;i++){
            string x;
            cin>>x;
            comp.push_back(x);
        }
        vector<int> r(4,0);
        for(int i=0;i<4;i++){
            comp=Rotate(comp,m);
            
            r.push_back(Count(mains,comp,n,m));
        }
        for(int i=0;i<4;i++){
            cout<<r[i]<<" ";
        }
        cout<<endl;
        r.clear();
    }while(n!=0 && m!=0);
}