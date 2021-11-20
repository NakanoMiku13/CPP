//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//Linear search
#include<bits/stdc++.h>
using namespace std;
int arre[50];
//Function that search a specific value in the array, if the value is on the array, the function return a true value that indicates that exist
//else the function returns a false that indicates that the value  in this case "x" is not on the array.
auto Search(int x,int n)->bool{
    for(int i=0;i<n;i++){
        //Just ask if the current value is equal to the value in search.
        if(arre[i]==x) return true;
    }
    return false;
}
auto main()->int{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arre[i];
    cin>>x;
    if(Search(x,n)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}