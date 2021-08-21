#include<bits/stdc++.h>
using namespace std;
//Variables globales
int Array[5],Array2[2][2],Array3[3][3][3];
int *ptr1,**ptr2,***ptr3;
auto main()-> int {
    int* Arre;
    Arre = (int*)malloc(sizeof(int)*6);
    for(int i=0;i<6;i++) {
        cin>>Arre[i];
    }
    ptr1=Arre;
    cout<<endl;
    for(int i=0;i<6;i++) {
        cout<<*(ptr1+(5-i))<<" ";
        //ptr[x]==ptr+x
    }
    int** Arre2;
    Arre2=(int**)malloc(sizeof(int*)*6);
    for(int i=0;i<6;i++) {
        *(Arre2+i)=(int*)malloc(sizeof(int)*6);
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>*(*(Arre2+i)+j);
            //arre2[i][j]==(ptr+i)+j
        }
    }
    ptr2=Arre2;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<*(*(ptr2+i)+j)<<" ";
        }
        cout<<endl;
    }
    int*** Arre3;
    Arre3= (int***)malloc(sizeof(int**)*3);
    for(int i=0;i<3;i++){
        *(Arre3+i)=(int**)malloc(sizeof(int*)*3);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            *(*(Arre3+i)+j)=(int*)malloc(sizeof(int)*3);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cin>>*(*(*(Arre3+i)+j)+k);
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cout<<*(*(*(Arre3+i)+j)+k)<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    ptr3=Arre3;
}