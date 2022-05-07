 #include<bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
int main(){
    int n, d;
    int same[]={6,3,5,2,4,7};
    sort(same,same+6);
    reverse(same,same+6);
    for(auto i:same) cout<<i<<" ";
}