#include<bits/stdc++.h>
using namespace std;
stack <pair<int,int>> flags;
int n = 9;
auto bfs(int** lab,int x,int y)->void{
    lab[y][x]=3;
    for(auto i = 0;i<n;i++){
        for(auto j = 0;j<n;j++) cout<<lab[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
    if(lab[y][x+1]==2 or lab[y][x-1]==2 or lab[y+1][x]==2 or lab[y-1][x]==2){
        while(!flags.empty()){
            flags.pop();
        }
        return;
    }else if(lab[y][x+1]!=0 and lab[y][x-1]!=0 and lab[y+1][x]!=0 and lab[y-1][x]!=0){
        if(lab[y][x+1]==2 or lab[y][x-1]==2 or lab[y+1][x]==2 or lab[y-1][x]==2){
            while(!flags.empty()){
                flags.pop();
            }
            return;
        }else if(!flags.empty()){
            while(!flags.empty()){
                auto pp = flags.top();
                flags.pop();
                bfs(lab,pp.first,pp.second);
            }
        }
    }else if(lab[y][x]==0 or lab[y][x]==3){
        if(lab[y][x+1]==0 or lab[y][x-1]==0 or lab[y+1][x]==0 or lab[y-1][x]==0){
            pair<int,int> coords={x,y};
            flags.push(coords);
        }
        if(lab[y-1][x] == 0) bfs(lab,x,y-1);
        else if(lab[y][x+1] == 0) bfs(lab,x+1,y);
        else if(lab[y+1][x] == 0) bfs(lab,x,y+1);
        else if(lab[y][x-1] == 0) bfs(lab,x-1,y);
    }
}
auto main()->int{
    int** lab = (int**)malloc(sizeof(int*)*n);
    for(auto i = 0;i<n;i++) lab[i] = (int*)malloc(sizeof(int)*n);
    int lab2[n][n] = {
                {1,1,1,1,1,1,1,1,1},
                {1,0,1,1,1,1,1,0,1},
                {1,0,0,0,0,1,0,0,1},
                {1,1,0,1,1,1,0,0,1},
                {1,0,0,1,0,0,1,0,1},
                {1,1,0,1,1,1,0,1,1},
                {1,0,0,0,0,0,0,0,1},
                {1,0,1,0,0,1,0,0,1},
                {1,1,1,1,1,1,1,2,1}
                };
    for(auto i = 0;i<n;i++){
        for(auto j = 0;j<n;j++) lab[i][j]=lab2[i][j];
    }
    bfs(lab,1,1);
    cout<<"Complete\n";
    for(auto i = 0;i<n;i++){
        for(auto j = 0;j<n;j++) cout<<lab[i][j]<<" ";
        cout<<endl;
    }
}