#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> arr(0);
        for(int j=0;j<2;j++){
            cin>>m;
            for(int k=0;k<m;k++){
                cin>>a;
                arr.push_back(a);
            }
        }
        sort(arr.begin(),arr.end());
        for(int j=0;j<(int)arr.size();j++){
            cout<<arr[j]<<" ";
        }
        arr.clear();
        cout<<endl;
    }
}