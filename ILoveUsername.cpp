#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c=0;
    cin>>n;
    int arre[n+1];
    vector<int> best;
    vector<int> worst;
    for(int i=0;i<n;i++){
        cin>>arre[i];
    }
    worst.push_back(arre[0]);
    best.push_back(arre[0]);
    //Check For the worst one
    for(int i=1;i<n;i++){
       if(arre[i]<worst[worst.size()-1]){
           c++;
           worst.push_back(arre[i]);
       }
       if(arre[i]>best[best.size()-1]){
           c++;
           best.push_back(arre[i]);
       }
    }
    cout<<c;
}