#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c=0,arre[3],results[3];
    cin>>n;
    for(int i=0;i<3;i++){
        cin>>arre[i];
    }
    sort(arre,arre+3);
    if(arre[0]==1){
        cout<<n;
        return 0;
    }
    int m=n;
    while(m>0){
        cout<<m<<endl;
        if(m%arre[2]==0){
            m/=arre[2];
            c+=m;
        }else if(m%arre[1]==0){
            m/=arre[1];
            c+=m;
        }else if(m%arre[0]==0){
            m/=arre[0];
            c+=m;
        }else if(m%arre[0]>=1){
            m/=arre[0];
            c+=m;
            break;
        }
    }
    results[0]=c;
    c=0; m=n;
    cout<<endl;
    while(m>0){
        cout<<m<<endl;
        if(m%arre[1]==0){
            m/=arre[1];
            c+=m;
        }else if(m%arre[0]==0){
            m/=arre[0];
            c+=m;
        }else if(m%arre[0]>=1){
            m/=arre[0];
            c+=m;
            break;
        }
    }
    results[1]=c;
    cout<<c;
}