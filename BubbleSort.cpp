#include<bits/stdc++.h>
using namespace std;
int arre[52];
auto Swap(int* a,int* b)->void{
	int x=*a;
	*a=*b;
	*b=x;
}
auto BubbleSort(int n)->void{
	for(auto i=0;i<n;i++){
		for(auto j=i;j<n-1;j++){
			if(arre[i]>arre[j+1]){
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
