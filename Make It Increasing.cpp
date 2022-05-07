#include<bits/stdc++.h>
using namespace std;
vector<unsigned long long int> v;
auto verifyDecrease()->bool{
    int n = v.size()-1;
    for(auto i=0;i<n;i++){
        if(v[i]<v[i+1]) continue;
        else return false;
    }
    return true;
}
auto modifyVector(auto counter)->int{
    int n = v.size()-1;
    for(auto i=0;i<n;i++){
        if(v[i+1]>v[i]) continue;
        else{
            if(v[i]>=1){
                v[i]/=2;
                counter++;
                return modifyVector(counter);
            }
        }
    }
    return counter;
}
auto verify()->long long int{
    int n=v.size()-1;
    if(verifyDecrease()) return 0;
    else{
        int counter=modifyVector(0);
        if(verifyDecrease()) return counter;
        else return -1;
    }
}
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long int n;
    cin>>n;
    for(auto i=0;i<n;i++){
        vector<unsigned long long int> v1(0);
        v = v1;
        int m;
        cin>>m;
        for(auto j=0;j<m;j++){
            long long int x;
            cin>>x;
            v.push_back(x);
        }
        if(m>1) cout<<verify()<<endl;
        else cout<<"0\n";
    }
}