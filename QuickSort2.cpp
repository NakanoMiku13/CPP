#include<bits/stdc++.h>
using namespace std;
template<typename A>
auto Swap(A* a, A* b)->void{
    A x = *a;
    *a = *b;
    *b = x;
}
int step1, step2;
template<typename T>
auto concat(vector<T> from,T item, vector<T> to)->vector<T>{
    to.push_back(item);
    for(auto i : from) to.push_back(i);
    return to;
}
template<typename type>
auto quickSort(vector<type> arr)->vector<type>{
    step1++;
    if(arr.size() == 1 or arr.size() == 0) return arr;
    else if(arr.size() == 2){
        if(arr[0] > arr[1]){
            Swap(&arr[0], &arr[1]);
            return arr;
        }else{
            return arr;
        }
    }else{
        type pivot = arr[arr.size() - 1];
        cout<<"\nPivot: "<<pivot<<endl;
        vector<type> right,left;
        for(int i = 0 ; i < arr.size()-1 ; i++){
            step1++;
            if(arr[i] < pivot) right.push_back(arr[i]);
            else if(arr[i] > pivot) left.push_back(arr[i]);
        }
        cout<<"Left: ";
        for(auto i : left) cout<<i<<" ";
        cout<<endl<<"Right: ";
        for(auto i : right) cout<<i<<" ";
        cout<<endl<<endl;
        return concat(quickSort(left),pivot,quickSort(right));
    }
}
template<typename T>
auto bubbleSort(vector<T> arr)->vector<T>{
    for(int i = 0 ; i < arr.size() - 1 ; i++){
        for(int j = 0 ; j < arr.size() ; j++){
            step2++;
            if(arr[i] < arr[j]) Swap(&arr[i], &arr[j]);
        }
    }
    return arr;
}
auto main()->int{
    vector<int> arr,arr2;
    srand(time(NULL));
    int size = rand() % 1000;
    for(int i = 0 ; i < size ; i++){
        int n = rand()%10000;
        arr.push_back(n);
        arr2.push_back(n);
    }
    auto t = quickSort(arr);
    auto f = bubbleSort(arr2);
    cout<<"\nSize: "<<size<<endl;
    cout<<"\nSteps quick: "<<step1<<endl;
    for(auto i : t){
        cout<<i<<" ";
    }
    cout<<"\nSteps bubble: "<<step2<<endl;
    for(auto i : f){
        cout<<i<<" ";
    }
}