#include <bits/stdc++.h>
using namespace std;
auto check(auto word)->int{
    int s=0;
    for(auto i:word) s+=i;
    return s;
}
auto result(auto words,auto length){
    int s = 0,mini = 999999999;
    int n = words.size()-1;
    for(auto i = 0; i < n;i++){
        for(auto j = i;j<n;j++){
            //cout<<words[i]<<" "<<words[j+1]<<endl;
            string a = words[i], b = words[j+1];
            int tmp = 0;
            for(auto k=0;k<length;k++){
                tmp += abs(b[k]-a[k]);
            }
            //cout<<tmp<<endl;
            mini = min(mini,tmp);
        }
    }
    return mini;
}
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(auto i=0; i<n; i++){
        int x,m;
        cin>>x>>m;
        if(m>1){
            vector<string> words;
            for(auto j=0;j<x;j++){
                string y;
                cin>>y;
                words.push_back(y);
            }
            cout<<result(words,m)<<endl;
        }else{
            vector<char> letters;
            for(auto j=0;j<x;j++){
                char y;
                cin>>y;
                letters.push_back(y);
            }
            int mini = 99999;
            x--;
            for(auto j=0;j<x;j++)
                for(auto k=j;k<x;k++)
                    mini = min(mini,abs(letters[j]-letters[k+1]));
            cout<<mini<<endl;
        }
    }
}