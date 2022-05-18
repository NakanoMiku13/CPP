#include <bits/stdc++.h>
using namespace std;
auto result(auto boxes,auto mini){
    unsigned long long int sum = 0;
    for(auto i:boxes)
        sum+=abs(i-mini);
    return sum;
}
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(auto i=0; i<n;i++){
        int m;
        long long int mini=0;
        cin>>m;
        vector<long long int> v(0);
        for(auto j=0; j<m;j++){
            long long int x;
            cin>>x;
            if(j==0) mini=x;
            else mini=min(x,mini);
            v.push_back(x);
        }
        if(m>1)
        cout<<result(v,mini)<<endl;
        else cout<<0<<endl;
    }
}