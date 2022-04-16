#include<bits/stdc++.h>
using namespace std;
long long int matrix[502][502];
pair<int, int> zeroCoord;
queue<long long int> sumRowColDiag;
auto checkPositionFirstDiagonal(const int n)->bool{
    return true;
}
auto clearQueue(queue<auto> toClear)->void{
    while(!toClear.empty()) toClear.pop();
}
auto checkSum()->int{
    auto x = sumRowColDiag.front();
    while(!sumRowColDiag.empty()){
        sumRowColDiag.pop();
        if(x==sumRowColDiag.front()) continue;
        else return -1;
    }
    return x;
}
auto checkRow(const int n)->long long int{
    clearQueue(sumRowColDiag);
    auto x=0;
    for(auto i=0;i<n;i++){
        if(zeroCoord.first!=i)
            for(auto j=0;j<n;j++)
                x+=matrix[i][j];
        if(x!=0) sumRowColDiag.push(x);
        x=0;
    }
    auto sum=checkSum();
    if(sum!=-1) return sum;
    else return -1;
}
auto checkCol(const int n)->long long int{
    auto x=0;
    for(auto i=0;i<n;i++){
        if(zeroCoord.second!=i)
            for(auto j=0;j<n;j++)
                    x+=matrix[j][i];
        if(x!=0) sumRowColDiag.push(x);
        x=0;
    }
    auto sum=checkSum();

}
auto main()->int{
    int n;
    cin>>n;
    for(auto i=0; i<n; i++) for(auto j=0; j<n; j++){
        cin>>matrix[i][j];
        if(matrix[i][j]==0){
            zeroCoord.first=i;
            zeroCoord.second=j;
        }
    }
    checkRow(n);
    
}