#include <bits/stdc++.h>
using namespace std;
auto main()->int{
    int x;
    cin>>x;
    int sumSteps=0,div=0;
    while(x>0){
        if(x>=5){
            div=x/5;
            sumSteps+=div;
            x-=(div*5);
        }else if(x>=4){
            div=x/4;
            sumSteps+=div;
            x-=(div*4);
        }else if(x>=3){
            div=x/3;
            sumSteps+=div;
            x-=(div*3);
        }else if(x>=2){
            div=x/2;
            sumSteps+=div;
            x-=(div*2);
        }else{
            x--;
            sumSteps++;
        }
    }
    cout<<sumSteps;
}