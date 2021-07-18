//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//BubbleSort
#include<bits/stdc++.h>
using namespace std;
int arre[52];
//Function that allow us to swap values on an array, eg. 3 and 2 after the swap 2 and 3
//You just have to give to the function the memory directions of the variables
auto Swap(int* a,int* b)->void{
	int x=*a;
	*a=*b;
	*b=x;
}
//Main function that sort the values on an array using the algorithm bubblesort
auto BubbleSort(int n)->void{
	//The function works checking the actual value of the array and it is compared with the rest of the array
	//the values of the array, in the case that the actual value is higher than the compared value
	//both are swapped
	//Eg. the main array is 5 3 2 4
	//The first element in the main array is 5, so is the first that is compared with the rest of the array
	//And is compared as this: [5] with [3], [5] is higher than [3], so we apply the swap function
	//Now the main array sets as this [3][5][2][4]
	//Then the [5] is compared with [2], and repeat the process
	for(auto i=0;i<n;i++){
		for(auto j=i;j<n-1;j++){
			if(arre[i]>arre[j+1]){
				//Swap function, just sending the memory values
				Swap(&arre[i],&arre[j+1]);
			}
		}
	}
}
auto main()->int{
	int n;
	cin>>n;
	for(auto i=0;i<n;i++) cin>>arre[i];
	BubbleSort(n);
	for(auto i=0;i<n;i++) cout<<arre[i]<<" ";
}
