#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    string numbers;
    cin>>numbers;
    int n = numbers.size(), counter1=0, counter2=0;
    for(auto i=0;i<n && (counter1<7 and counter2<7);i++){
        if(numbers[i]=='1'){
            counter2=0;
            counter1++;
        }else{
            counter1=0;
            counter2++;
        }
    }
    if(counter1<7 and counter2<7) cout<<"NO";
    else cout<<"YES";
}