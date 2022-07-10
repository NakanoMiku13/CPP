#include <bits/stdc++.h>

using namespace std;

int main(){

    int* arre = (int*)malloc(sizeof(int)*15);
    for(int i=0;i<15;i++){
        arre[i]=i;
    }
    for(int i=0;i<15;i++){
        cout<<*(arre+i)<<endl;
    }
    int** mat = (int**)malloc(sizeof(int*)*15);
    for(int i=0;i<15;mat[i++]=(int*)malloc(sizeof(int)*15));
    for(int i=0,x=0;i<15;i++){
        for(int j=0;j<15;j++,x++){
            *(*(mat+i)+j)=x;
        }
    }
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            cout<<*(*(mat+i)+j)<<" ";
        }
        cout<<endl;
    }
}