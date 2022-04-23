#include<bits/stdc++.h>
using namespace std;
auto verify(vector<pair<int,bool>> ar)->void{
    int n = ar.size();
    for(auto i=0;i<n-1;i++){
        auto x= ar[i+1].first-ar[i].first;
        if(x<=3 and x>0){
            if(i==n-2 && ar[i+1].first==ar[i].first){
                ar[i+1].first++;
            }
            if(x==1){
                ar[i].first++;
                ar[i].second=false;
            }
            else{
                if(x==2 && i==n-2){
                    ar[i+1].first--;
                }else
                if(x==2 && ar[i].second){
                    ar[i].second=false;
                    ar[i].first++;
                }else
                if(x==3 && ar[i+1].second && ar[i].second){
                    ar[i+1].first--;
                    ar[i].first++;
                    ar[i].second=ar[i+1].second=false;
                }else if(ar[i+1].second && !ar[i].second && ar[i+1].first-ar[i].first==2){
                    ar[i+1].first--;
                    ar[i+1].second=false;
                }
            }
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
    for(auto i=0;i<n-1;i++){
        auto x = ar[i+1].first - ar[i].first;
        if(x==1) continue;
        else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(auto i = 0; i < n;i++){
        int x;
        cin>>x;
        vector<pair<int,bool>> ar;
        for(auto j=0;j<x;j++){
            int y;
            cin>>y;
            pair<int,bool> tmp = {y,true};
            ar.push_back(tmp);
        }
        verify(ar);
    }
}