//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//MergeSort
#include<bits/stdc++.h>
using namespace std;
int arre[50];
//Function Merge that is used to merge the principal array into 2 different arrays.
auto Merge(int ini, int fin,int mid)->void{
    //ia2 variable is used to calculate the number of elements in the right array.
    //ib2 is used to calculate the number of elements in the left array.
    int ia2=mid-ini+1,ib2=fin-mid;
    //A1 is the left array and B1 is the right array.
    //Those arrays are set with new int array to reserve the memory space and take out possible errors or trash numbers.
    //a1 and b1 are variables just used as a counter for A1 and B1 arrays.
    //xs variable is just a copy of the parameter ini that indicates the initial index of the array
    int *A1=new int[ia2],*B1=new int[ib2],a1=0,b1=0,m1=mid+1,xs=ini;
    //Here we are just making a copy of the values of the original array "arre" to the left part (Just the fist half)
    for(int i=0;i<ia2;i++){
        A1[i]=arre[i+ini];
    }
    //Here we make a copy for the second half of the principal array
    for(int i=0;i<ib2;i++){
        B1[i]=arre[i+m1];
    }
    //Here we are sorting the numbers into the principal array checking who is the biggest one
    //We ask if the actual value of the right array is bigger than the value of the left array
    //if that happend, the value of the left array is replaced in the original array
    //else if the value of the left array is bigger than the value of the right array, this one is replaced on the principal array
    while(a1<ia2 && b1<ib2){
        if(A1[a1]<=B1[b1]){
            arre[xs]=A1[a1];
            a1++;
        }else{
            arre[xs]=B1[b1];
            b1++;
        }
        xs++;
    }
    //Here we are replacing the rest of the elements of the arrays in the original array
    for(;a1<ia2;a1++,xs++){
        arre[xs]=A1[a1];
    }
    for(;b1<ib2;b1++,xs++){
        arre[xs]=B1[b1];
    }
}
//Principal function for the MergeSort algorithm.
auto MergeSort(int ini,int fin)->void{
    //Conditional to take out possible cyclic redundancy.
    if(ini>=fin) return;
    //Creating the mid value
    int mid= ini+(fin-ini)/2;
    //Here we just invoke the principal function to make it recursive and complete the algorithm.
    //Using the system memory to save the process that will make done in the future, after finishing the first process
    MergeSort(ini,mid);
    MergeSort(mid+1,fin);
    Merge(ini,fin,mid);
}
auto main()->int{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arre[i];
    }
    MergeSort(0,n-1);
    for(int i=0;i<n;i++) cout<<arre[i]<<" ";
}