#include<bits/stdc++.h>
using namespace std;
int matrix[6][6];
pair<int,int> pos;
int MatrixMiddle(int c){
    if(matrix[2][2]==1) return c;
    else{
        if(matrix[pos.first][pos.second]==2 || (pos.first==2 && pos.second==2)) return c;
        else if(pos.first>2){
            int x=pos.first;
            pos.first--;
            swap(matrix[pos.first][pos.second],matrix[x][pos.second]);
            return MatrixMiddle(c+1);
        }else if(pos.second>2){
            int x=pos.second;
            pos.second--;
            swap(matrix[pos.first][pos.second],matrix[pos.first][x]);
            return MatrixMiddle(c+1);
        }else if(pos.first<2){
            int x=pos.first;
            pos.first++;
            swap(matrix[pos.first][pos.second],matrix[x][pos.second]);
            return MatrixMiddle(c+1);
        }else {
            int x=pos.second;
            pos.second++;
            swap(matrix[pos.first][pos.second],matrix[pos.first][x]);
            return MatrixMiddle(c+1);
        }
    }
}
auto main()->int{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            int x;
            cin>>x;
            if(x==1){
                pos.first=i;
                pos.second=j;
            }
            matrix[i][j]=x;
        }
    int x=MatrixMiddle(0);
    cout<<x;
}