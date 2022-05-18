#include<bits/stdc++.h>
using namespace std;
auto main()->int{
   ios_base::sync_with_stdio(0);cin.tie(0);
   long long int n;
   cin>>n;
   unsigned long long int sum = 0,a=0;
   for(long long int i=0;i<n;i++){
      cin>>a;
      sum^=(a);
   }
   cout<<sum;
   return 0;
}
