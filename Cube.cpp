#include<bits/stdc++.h>
using namespace std;
int Array[5][5][5];
auto Fill()->void{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                Array[i][j][k]=rand()%10;
            }
        }
    }
}
auto SumCol(int x,int z)->int{
    size_t Sum = 0;
    for(int i=0;i<5;i++){
        Sum+=Array[x][i][z];
    }
    cout<<endl;
    return (int)Sum;
}
auto SumRow(int y,int z)->int{
    size_t Sum = 0;
    for(int i=0;i<5;i++){
        cout<<Array[i][y][z]<<" ";
        Sum+=Array[i][y][z];
    }
    cout<<endl;
    return (int)Sum;
}
auto FaceFront()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            Sum+=Array[i][j][0];
        }
    }
    return (int)Sum;
}
auto FaceRight()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            Sum+=Array[4][i][j];
        }
    }
    return (int)Sum;
}
auto FaceLeft()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            Sum+=Array[0][i][4-j];
        }
    }
    return (int)Sum;
}
auto FaceBack()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                Sum+=Array[4-i][j][4-k];
            }
        }
    }
    return (int)Sum;
}
auto FaceTop()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            Sum+=Array[i][0][j];
        }
    }
    return (int)Sum;
}
auto FaceBottom()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            Sum+=Array[i][4][j];
        }
    }
    return (int)Sum;
}
auto SumFaceMenu(int face)->int{
    size_t Sum=0;
    switch(face){
        case 1: return FaceFront(); break;
        case 2: return FaceRight(); break;
        case 3: return FaceLeft(); break;
        case 4: return FaceBack(); break;
        case 5: return FaceTop(); break;
        case 6: return FaceBottom(); break;
        default: return 0; break;
    }
}
auto PrintArray()->void{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                cout<<Array[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
auto main()-> int {
    Fill();
    cout<<SumFaceMenu(1)<<endl;
    PrintArray();
}