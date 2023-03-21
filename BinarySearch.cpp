#include<bits/stdc++.h>
using namespace std;
auto binarySearch(const int begin,const int end, vector<int> array,const int x)->int{
    int mid = (end + begin) / 2;
    return (begin >= end) ? ((array[begin] == x) ? begin : -1 ) : ((array[mid] == x) ? mid : ((array[mid] < x) ? binarySearch(mid + 1,end,array,x) : binarySearch(begin,mid,array,x)));
}
auto main()->int{
    srand(time(NULL));
    int n = rand() % 1000;
    vector<int> array;
    for(int i = 0 ; i < n ; i ++) array.push_back(rand()%n);
    sort(array.begin(), array.end());
    int x = rand() % n;
    int pos = binarySearch(0,n,array,x);
    cout<<"Array: "<<endl;
    for(auto i : array) cout<<i<<" ";
    cout<<"\nX: "<<x<<endl;
    if(pos != -1){
        cout<<"The number: "<<x<<" is at index: "<<pos<<endl;
    }else{
        cout<<"The number was not found"<<endl;
    }
    return 0;
}