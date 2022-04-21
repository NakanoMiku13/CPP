#include<bits/stdc++.h>
using namespace std;
int counter=0;
auto verify(auto arrays)->bool{
    for(auto i=0;i<arrays.size();i++){
        if(arrays[i]!=arrays[0]) return false;
    }
    return true;
}
auto cloneArray(auto original){
    counter++;
    return original;
}
//Need to be optimized
auto swapNumbers(auto original, auto copy){
    int i=0;
    while(original[i]!=original[0]) i++;
    i++;
    for(auto j=i,c=0;j<original.size() and copy[c]==original[0];j++,c++){
        swap(original[j],copy[c]);
    }
    counter++;
    return original;
}
auto repeatedNumbers(auto arrays,auto mostRepeated)->void{
    cout<<"Hu\n";
}
auto nonRepeatedNumbers(auto arrays)->void{
    while(!verify(arrays)){
        auto clone = cloneArray(arrays);
        arrays=swapNumbers(arrays,clone);
    }
}
auto checkIfExistRepeated(auto arrays)->pair<bool,char>{
    char let;
    int count = 0;
    for(auto i=0;i<arrays.size();i++){
        if(arrays[i]==arrays[i+1]){
            count++;
            let = char(arrays[i]);
        }
    }
    cout<<let<<" "<<count<<endl;
    if(count==1) return {false,let};
    return {true,let};
}
auto select(auto arrays){
    auto value = checkIfExistRepeated(arrays);
    if(value.first) repeatedNumbers(arrays,value.second);
    else nonRepeatedNumbers(arrays);
}
auto main()->int{
    int n;
    cin>>n;
    for(auto i=0;i<n;i++){
        int x;
        cin>>x;
        string arrays;
        for(auto j=0;j<x;j++){
            char a;
            cin>>a;
            arrays+=a;
        }
        sort(arrays.begin(), arrays.end());
        select(arrays);
        counter = 0;
    }
}