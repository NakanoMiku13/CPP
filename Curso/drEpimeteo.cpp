#include<bits/stdc++.h>
using namespace std;
auto fillArray(int m,int n)->vector<int>{
  vector<int> tmp(0);
  for(auto i=0;i<n;i++) tmp.push_back(m);
  return tmp;
}
auto proceso(auto torretas, int ataques)->vector<int>{
  int x,y;
  for(auto i=0;i<ataques;i++){
    cin>>x>>y;
    torretas[y-1]-=x;
  }
  return torretas;
}
auto main()->int {
  int n,m,z;
  cin>>n>>m>>z;
  auto torretas = fillArray(m,n);
  torretas = proceso(torretas,z);
  for(auto i:torretas) cout<<i<<" ";
  return 0;
}