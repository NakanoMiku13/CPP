#include<bits/stdc++.h>
using namespace std;
stack<int> check,maxis;
auto main()->int{
    int n,maxi=0;
    cin>>n;
    for(auto i=0;i<n;i++){
        int a;
        cin>>a;
        switch(a){
            case 1:
                int x;
                cin>>x;
                check.push(x);
                maxi=max(maxi,x);
            break;
            case 2:
                if(check.top()==maxi){
                    maxi=0;
                    auto tmp = check;
                    tmp.pop();
                    while(!tmp.empty()){
                        maxi=max(maxi,tmp.top());
                        tmp.pop();
                    }
                }
                check.pop();
                break;
            case 3: cout<<maxi<<"\n";
        }
    }
}