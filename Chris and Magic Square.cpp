#include<bits/stdc++.h>
using namespace std;
int n,matrix[502][502],registry[502];
long long int magicCommon;
queue<long long int> sumCol,sumRow,sumDiag;
pair<int,int> zeroCoord;
//0 = null, 1 = first diagonal, 2 = second diagonal, 3 = mid value
pair<bool,int> isDiagonal={false,0};
auto isInDiagonal()->pair<bool,int>{
    pair<bool,int> tmp;
    //first diagonal
    if(zeroCoord.first==zeroCoord.second && (n/2!=zeroCoord.second && n/2!=zeroCoord.first)){
        tmp.first = true;
        tmp.second = 1;
    }else if(zeroCoord.first==zeroCoord.second && (n%2==0)){
        tmp.first = true;
        tmp.second = 1;
    }else if(zeroCoord.first==zeroCoord.second){
        tmp.first = true;
        tmp.second = 3;
    }else if(registry[zeroCoord.first]==zeroCoord.second){
        tmp.first = true;
        tmp.second = 2;
    }else{
        tmp.first = false;
        tmp.second = 0;
    }
    return tmp;
}
auto checkSumRow()->long long int{
    auto x=sumRow.front();
    sumRow.pop();
    while(!sumRow.empty()){
        if(sumRow.front()==x) sumRow.pop();
        else return -1;
    }
    return x;
}
auto checkSumCol()->long long int{
    //getting the sums
    for(auto i=0;i<n;i++){
        long long int x = 0;
        if(zeroCoord.second!=i) for(auto j=0;j<n;j++) x+=matrix[j][i];
        if(x!=0) sumCol.push(x);
    }
    //check sum columns
    auto x=sumCol.front();
    sumCol.pop();
    while(!sumCol.empty()){
        if(sumCol.front()==x) sumCol.pop();
        else return -1;
    }
    return x;
}
auto checkSumDiag()->long long int{
    //first diagonal
    long long int x=0;
    for(auto i=0;i<n;i++) x+=matrix[i][i];
    //second diagonal
    long long int y=0;
    auto t=n-1;
    for(auto i=0,j=t;i<n && j>=0;j--,i++) y+=matrix[i][j];
    if(x==y) return x;
    else return -1;
}
auto foundMagicNumber(const auto magicCommon)->long long int{
    //check row
    long long int row=0;
    for(auto i=0;i<n;i++) row+=matrix[zeroCoord.first][i];
    row=magicCommon-row;
    //check column
    long long int col=0;
    for(auto i=0;i<n;i++) col+=matrix[i][zeroCoord.second];
    col=magicCommon-col;
    if(!isDiagonal.first){
        auto diag = checkSumDiag();
        if(diag>0 && diag==magicCommon){
            if(row==col && col>0) return row;
            else return -1;
        }else{
            return -1;
        }
    }else{
        long long int sumD1=0,sumD2=0;
        const auto t=n-1;
        switch(isDiagonal.second){
            case 1:
                //getting the sum for the second diagonal
                for(auto i=0,j=t;i<n && j>=0;i++,j--) sumD1+=matrix[i][j];
                if(sumD1==magicCommon){
                    //getting the sum for the first diagonal
                    for(auto i=0;i<n;i++) sumD2+=matrix[i][i];
                    sumD2=magicCommon-sumD2;
                    if(col==row && col==sumD2 && col>0) return col;
                    else return -1;
                }else{
                    return -1;
                }
                break;
            case 2:
                //getting the magic number from the second Diagonal
                for(auto i=0;i<n;i++) sumD1+=matrix[i][i];
                if(sumD1==magicCommon){
                    //getting the sum for the second diagonal
                    for(auto i=0,j=t;j>=0 && i<n;i++,j--) sumD2+=matrix[i][j];
                    sumD2=magicCommon-sumD2;
                    if(col==row && col==sumD2 && col>0) return col;
                    else return -1;
                }else{
                    return -1;
                }
                break;
            case 3:
                //getting the sum on the first diagonal
                for(auto i=0;i<n;i++) sumD1+=matrix[i][i];
                for(auto i=0,j=t;i<n && j>=0;i++,j--) sumD2+=matrix[i][j];
                if(sumD1==sumD2){
                    sumD1=magicCommon-sumD1;
                    sumD2=magicCommon-sumD2;
                    if(sumD1==sumD2 && sumD1==col && sumD2==row && row==col && col>0) return col;
                    else return -1;
                }else return -1;
                break;
            default: return -1;
        }
    }
    return -1;
}
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    if(n==1){
        auto xd=0;
        cin>>xd;
        if(xd==0) cout<<1;
        else cout<<-1;
        return 0;
    }
    auto tmp=n-1;
    for(auto i=0,k=tmp;i<n;i++,k--){
        long long int sumRows=0;
        bool tmp1=false;
        for(auto j=0;j<n;j++){
            auto x=0;
            cin>>x;
            if(x==0){
                zeroCoord.first=i;
                zeroCoord.second=j;
                tmp1=true;
            }
            matrix[i][j]=x;
            sumRows+=x;
        }
        if(!tmp1) sumRow.push(sumRows);
        registry[i]=k;
    }
    isDiagonal=isInDiagonal();
    auto row = checkSumRow();
    //checking row
    if(row>0){
        auto col = checkSumCol();
        //check column
        if(col>0){
            //check if is in diagonal
            if(!isDiagonal.first){
                auto diag = checkSumDiag();
                if(row==col && row==diag && col==diag){
                    //here we found the magicCommon
                    cout<<foundMagicNumber(row);
                    return 0;
                }else{
                    cout<<-1;
                    return 0;
                }
            }else{
                if(row==col) cout<<foundMagicNumber(row);
                else cout<<-1;
                return 0;
            }
        }else{
            cout<<-1;
            return 0;
        }
    }else{
        cout<<-1;
        return 0;
    }

}