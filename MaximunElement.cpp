#include<bits/stdc++.h>
using namespace std;
stack<int> lst;
auto Max()->int{
    auto tmp = lst;
    int MaxV=0;
    while(!tmp.empty()){
        MaxV=max(MaxV,tmp.top());
        tmp.pop();
    }
    return MaxV;
}
auto main()-> int {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x;
        if(x==1){
            cin>>y;
            lst.push(y);
        }else if(x==2) lst.pop();
        else if(x==3) cout<<Max()<<endl;
    }
}