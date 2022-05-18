#include<bits/stdc++.h>
using namespace std;
map<long long int,bool> companies;
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long int n,m,k,c=0;
    vector<pair<vector<long long int>,bool>> lists;
    cin>>n>>m;
    for(long long int i=0;i<n;i++){
        cin>>k;
        long long int x;
        vector<long long int> list(0);
        for(long long int j=0;j<k;j++){
            cin>>x;
            list.push_back(x);
        }
        sort(list.begin(),list.end());
        lists.push_back({list,true});
    }
    sort(lists.begin(),lists.end());
    int z = lists.size();
    for(int i=1;i<=m;i++){
        for(long long int j=0;j<z;j++){
            auto zk = lists[j].first.size();
            for(long long int ji=0;ji<zk;ji++){
                if(!companies[lists[j].first[ji]] && lists[j].second){
                    companies[lists[j].first[ji]]=true;
                    lists[j].second=false;
                    break;
                }
            }
        }
    }
    for(auto i=1;i<=m;i++){
        if(!companies[i]) c++;
    }
    cout<<c;
    return 0;
}