//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//Function Sort
#include<bits/stdc++.h>
using namespace std;
int arre[50];
auto main()->int{
    int n;
    cin>>n;
    for(auto i=0;i<n;i++){
        cin>>arre[i];
    }
    //Predefined function that allow us to sort the items in the array, in this case the
    //The array called "arre", and sort it
    //We give the array to the function and the length of the array
    sort(arre,arre+n);
    for(auto i=0;i<n;i++){
        cout<<arre[i]<<" ";
    }
}