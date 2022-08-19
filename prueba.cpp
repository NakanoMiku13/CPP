#include<iostream>
using namespace std;
template<typename dataset> auto insertionSort(const dataset* arr,const int size,const dataset newValue){
  dataset* tmp = (dataset*)malloc(sizeof(dataset)*size+2);
  if(newValue < arr[0]){
    tmp[0] = newValue;
    for(int i=1,j=0;j < size;i++,j++){
      tmp[i]=arr[j];
    }
  }else{
    int c=0;
    for(int i=0;i<size and newValue > arr[i];i++,c++) tmp[i]=arr[i];
    if(c>=size){
      tmp[size]=newValue;
    }else{
      tmp[c]=newValue;
      for(int i=c;i<size;i++) tmp[i+1]=arr[i];
    }
  }
  return tmp;
}
auto main()->int{
  int n,*arr;
  cin>>n;
  arr=(int*)malloc(sizeof(int)*n+2);
  for(auto i=0;i<n;i++){
    int x;
    cin>>x;
    arr=insertionSort(arr,i,x);
  }
  cout<<"\nFinalArray\n";
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}