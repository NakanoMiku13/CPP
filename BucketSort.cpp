#include<bits/stdc++.h>
using namespace std;
template<typename T>
auto concat(vector<T> to,vector<T> from)->vector<T>{
    for(auto i : from) to.push_back(i);
    return to;
}
template<typename T>
auto Swap(T* a, T* b){
    T z = *a;
    *a = *b;
    *b = z;
}
template<typename T>
auto bucketSort(vector<T> arr,const T maxi)->vector<T>{
    cout<<"Size: "<<arr.size()<<endl<<endl;
    if(arr.size() <= 1) return arr;
    if(arr.size() == 2){
        if(arr[0] > arr[1]) Swap(&arr[0],&arr[1]);
        return arr;
    }else{
        int range = 5, split = maxi / range;
        map<int, vector<T>> buckets;
        vector<int> keys = vector<T>(), result = vector<T>();
        int maxis[] = {0,0,0,0,0};
        for(int i = 1 ; i <= range ; keys.push_back(split * i), i++) buckets[split*i] = vector<T>();
        for(auto i : arr){
            cout<<i<<" ";
            if( i < keys[0]){ buckets[keys[0]].push_back(i); maxis[0] = max(maxis[0],i);}
            else if( i < keys[1]) { buckets[keys[1]].push_back(i); maxis[1] = max(maxis[1],i);}
            else if( i < keys[2]) { buckets[keys[2]].push_back(i); maxis[2] = max(maxis[2],i);}
            else if( i < keys[3]) { buckets[keys[3]].push_back(i); maxis[3] = max(maxis[3],i);}
            else{ buckets[keys[4]].push_back(i); maxis[4] = max(maxis[4],i);}
            /*if( i < keys[0]){ buckets[keys[0]].push_back(i);}
            else if( i < keys[1]) { buckets[keys[1]].push_back(i);}
            else if( i < keys[2]) { buckets[keys[2]].push_back(i);}
            else if( i < keys[3]) { buckets[keys[3]].push_back(i);}
            else{ buckets[keys[4]].push_back(i);}*/
        }
        cout<<endl<<"Maxis: ";
        for(int i = 0 ; i < 5 ; i++) cout<<maxis[i]<<" ";
        cout<<endl;
        int k = 0;
        int asd;
        cin>>asd;
        for(auto key : keys){
            cout<<"Key: "<<key<<endl;
            cout<<"Max: "<<maxis[k]<<endl;
            cout<<"Bucket: ";
            for(auto i : buckets[key]) cout<<i<<" ";
            cout<<endl;
            concat(result,/*buckets[key]*/bucketSort(buckets[key],maxis[k]));
            k++;
            cout<<"Result: ";
            for(auto i : result) cout<<i<<" ";
            cout<<endl;
        }
        cout<<"Ret"<<endl;
        return result;
    }
}
auto main()->int{
    vector<int> t = vector<int>();
    srand(time(NULL));
    int size = rand() % 15 + 5;
    for(int i = 0 ; i < size ; t.push_back(rand()%100), i++);
    auto result = bucketSort(t,79);
    for(auto i : t) cout<<i<<" ";
}