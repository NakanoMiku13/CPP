#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    srand(time(NULL));
    int a,b;
    cin>>a>>b;
    while(true) cout<<a+(rand()%(b-a+1))<<endl;
}