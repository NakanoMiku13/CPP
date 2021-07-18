//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//QuickSort
#include<bits/stdc++.h>
using namespace std;
int arre[50];
//Function that is used to sort the numbers using the pivot
auto Order(int ini,int fin)->void{
    //tmpA1 and tmpA2 are arrays that we will use to divide the main array in two halfs
    //iA1 and iA2 are varibales used as the index of the temproray arrays
    //mid is just the medium value of the main array
    //Pivot is the principal variable used in the algorithm, in this case the pivot is the last elemnt in the main array
    //The pivot could be any number of the array, so be careful changing the main code to make it work
    int tmpA1[50], tmpA2[50],iA1=0,iA2=0,mid = (ini+fin)/2,pivot=arre[fin-1];
    for(int i=0;i<fin;i++){
        //Checking if the actual value of the array is bigger or lower than the pivot
        //if the value is higher than the pivot, is sent to the right array (tmpA2)
        //else if the value is lower than the pivot, is sent to the left array (tmpA1)
        if(arre[i]>pivot){
            tmpA2[iA2]=arre[i];
            iA2++;
        }else{
            tmpA1[iA1]=arre[i];
            iA1++;
        }
    }
    //Here we are just replacing the original values of the main array for the values of the temporary arrays
    for(int i=0;i<iA1;i++){
        arre[i]=tmpA1[i];
    }
    for(int i=iA1, j=0;i<fin;i++,j++){
        arre[i]=tmpA2[j];
    }
}
//Principal function of the QuickSort
auto QuickSort(int ini,int fin)->void{
    //Conditional to take out possible cyclic redundancy.
    if(ini>=fin) return;
    //Creating the mid value
    int mid = (ini+fin)/2;
    //Here we just invoke the principal function to make it recursive and complete the algorithm.
    //Using the system memory to save the process that will make done in the future, after finishing the first process
    QuickSort(ini,mid);
    QuickSort(mid+1,fin);
    Order(ini,fin);
}
auto main()->int{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arre[i];
    QuickSort(0,n);
    for(int i=0;i<n;i++) cout<<arre[i]<<" ";
}