#include<bits/stdc++.h>
using namespace std;
template<typename T>
auto concat(vector<T> to,vector<T> from)->vector<T>{
    for(auto i : from) to.push_back(i);
    return to;
}
template<typename T>
auto concat(vector<T> from,T item, vector<T> to)->vector<T>{
    to.push_back(item);
    for(auto i : from) to.push_back(i);
    return to;
}
template<typename T>
auto Swap(T* a, T* b){
    T z = *a;
    *a = *b;
    *b = z;
}
template<typename type>
auto quickSort(vector<type> arr)->vector<type>{
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
        vector<type> right,left;
        for(int i = 0 ; i < arr.size()-1 ; i++){
            if(arr[i] < pivot) right.push_back(arr[i]);
            else if(arr[i] > pivot) left.push_back(arr[i]);
        }
        return concat(quickSort(left),pivot,quickSort(right));
    }
}
template<typename T>
auto bucketSort(vector<T> arr,const T maxi)->vector<T>{
    if(arr.size() == 1 or arr.size() == 0) return arr;
    if(arr.size() == 2){
        if(arr[0] > arr[1]) Swap(&arr[0],&arr[1]);
        return arr;
    }else{
        int range = 5, split = maxi / range;
        map<int, vector<T>> buckets;
        vector<int> keys = vector<T>(), result = vector<T>();
        int maxis[] = {0,0,0,0,0};
        for(int i = 1 ; i <= range ; keys.push_back(split * i), i++) buckets[split*i] = vector<T>();
        for(auto i : arr)
            if( i < keys[0]){ buckets[keys[0]].push_back(i);}
            else if( i < keys[1]) { buckets[keys[1]].push_back(i);}
            else if( i < keys[2]) { buckets[keys[2]].push_back(i);}
            else if( i < keys[3]) { buckets[keys[3]].push_back(i);}
            else{ buckets[keys[4]].push_back(i);}
            /*if( i < keys[0]){ buckets[keys[0]].push_back(i); maxis[0] = max(maxis[0],i);}
            else if( i < keys[1]) { buckets[keys[1]].push_back(i); maxis[1] = max(maxis[1],i);}
            else if( i < keys[2]) { buckets[keys[2]].push_back(i); maxis[2] = max(maxis[2],i);}
            else if( i < keys[3]) { buckets[keys[3]].push_back(i); maxis[3] = max(maxis[3],i);}
            else{ buckets[keys[4]].push_back(i); maxis[4] = max(maxis[4],i);}*/
        //Using quickSort
        for(auto key : keys) result = concat(result,quickSort(buckets[key]));
        //Making it recursive
        /*int k = 0;
        for(auto key : keys){ result = concat(result,bucketSort(buckets[key],maxis[k])); k++; }*/
        return result;
    }
}
auto main()->int{
    vector<int> t = vector<int>();
    srand(time(NULL));
    int size = rand() % 15 + 5, maxi = 0;
    map<int,bool> exist;
    for(int i = 0, val = rand()%100 ; i < size ; i++){
        if(!exist[val]){
            maxi = max(maxi,val);
            t.push_back(val);
            exist[val] = true;
            val = rand()%100;
        }
    }
    for(auto i : t) cout<<i<<" ";
    cout<<endl;
    auto result = bucketSort(t,maxi);
    for(auto i : result) cout<<i<<" ";
}