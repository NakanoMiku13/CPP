#include<bits/stdc++.h>
using namespace std;
auto adjust(auto year)->vector<int>{
    for(auto i=0;i<5;i++){
        if(year[1]==10){
        year[1]=0;
        year[0]++;
        }
        if(year[2]==10){
            year[2]=0;
            year[1]++;
        }
        if(year[3]==10){
            year[3]=0;
            year[2]++;
        }
    }
    return year;
}
auto verify(vector<int> year)->bool{
    auto n=year.size(),x=n-1;
    year=adjust(year);
    for(auto i=0;i<x;i++){
        for(auto j=i+1;j<n;j++){
            if(year[i]!=year[j]) continue;
            else return false;
        }
    }
    return true;
}
auto beautiyear(vector<int> year)->void{
    while(!verify(year) && year[0]<=9){
        year=adjust(year);
        year[3]++;
    }
    year=adjust(year);
    for(auto i:year) cout<<i;
}
auto main()->int{
    string n;
    cin>>n;
    vector<int> array(0);
    for(auto i:n) array.push_back((int)i-48);
    array[3]++;
    beautiyear(array);
}