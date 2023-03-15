#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
auto printMap(vector<vector<int>> lab,int x, int y)->void{
    for(int i = 0 ; i < lab.size() ; i++){
        for(int j = 0 ; j < lab[i].size() ; j++){
            if(i == y && x == j) cout<<"* ";
            else cout<<lab[i][j]<<" ";
        }
        cout<<endl;
    }
}
vector<vector<int>> lab;
auto findExit(const int x,const int y, pair<int,int>* exit,queue<pair<int,int>> flags)->void{
    if(lab[y][x] == 3 or lab[y+1][x] == 3 or lab[y-1][x] == 3 or lab[y][x+1] == 3 or lab[y][x-1] == 3) {
        cout<<"Exit"<<endl;
        exit->first = x;
        exit->second = y;
        flags = queue<pair<int,int>>();
        return;
    }
    else{
        if(lab[y][x] == 1){
            lab[y][x] = 0;
            cout<<"X: "<<x<<" Y: "<<y<<endl;
            cout<<"Flags: "<<flags.size()<<endl;
            printMap(lab,x,y);
            sleep(1);
            system("clear");
            if(!flags.empty()){
                while(!flags.empty()){
                    auto coords = flags.front();
                    findExit(coords.first,coords.second,exit,flags);
                    flags.pop();
                }
            }
            if(lab[y-1][x] == 1 && lab[y+1][x] == 1 && lab[y][x+1] == 1 && lab[y][x-1] == 1){
                //Up, left, right, down
                flags.push({x-1,y});
                flags.push({x,y+1});
                flags.push({x,y-1});
                findExit(x+1,y,exit,flags);
            }else
            if(lab[y-1][x] == 1 && lab[y+1][x] == 1 && lab[y][x+1]){
                //Up, down, right
                flags.push({x,y+1});
                flags.push({x,y-1});
                findExit(x+1,y,exit,flags);
            }else
            if(lab[y-1][x] == 1 && lab[y+1][x] == 1 && lab[y][x-1]){
                //Up, down, left
                flags.push({x,y+1});
                flags.push({x,y-1});
                findExit(x-1,y,exit,flags);
            }else
            if(lab[y-1][x] == 1 && lab[y][x-1] == 1 && lab[y][x+1]){
                //Right, left, down
                flags.push({x+1,y});
                flags.push({x-1,y});
                findExit(x,y-1,exit,flags);
            }else
            if(lab[y-1][x] == 1 && lab[y][x-1] == 1 && lab[y][x+1]){
                //Right, left, up
                flags.push({x+1,y});
                flags.push({x-1,y});
                findExit(x,y+1,exit,flags);
            }else
            if(lab[y-1][x] == 1 && lab[y+1][x] == 1){
                //Up, down
                flags.push({x,y+1});
                findExit(x,y-1,exit,flags);
            }else
            if(lab[y][x+1] == 1 && lab[y][x-1] == 1){
                //Left, right
                flags.push({x-1,y});
                findExit(x+1,y,exit,flags);
            }else
            if(lab[y+1][x] == 1 && lab[y][x-1] == 1){
                //Down, left
                flags.push({x,y+1});
                findExit(x-1,y,exit,flags);
            }else
            if(lab[y+1][x] == 1 && lab[y][x+1] == 1){
                //Down, right
                flags.push({x,y+1});
                findExit(x+1,y,exit,flags);
            }else
            if(lab[y-1][x] == 1 && lab[y][x-1] == 1){
                //Top, left
                flags.push({x,y-1});
                findExit(x-1,y,exit,flags);
            }else
            if(lab[y-1][x] == 1 && lab[y][x+1] == 1){
                //Top, right
                flags.push({x,y-1});
                findExit(x+1,y,exit,flags);
            }
            if(lab[y-1][x] == 1) findExit(x,y-1,exit,flags);
            else if(lab[y][x+1] == 1) findExit(x+1,y,exit,flags);
            else if(lab[y+1][x] == 1) findExit(x,y+1,exit,flags);
            else if(lab[y][x-1] == 1) findExit(x-1,y,exit,flags);
        }
    }
}
auto main()->int{
    int width = 8, height = 8;
    lab = {
        {2,2,2,2,2,2,2,2},
        {2,1,2,2,1,2,3,2},
        {2,1,1,1,1,1,1,2},
        {2,2,2,1,1,2,1,2},
        {2,1,1,1,2,2,2,2},
        {2,2,1,2,1,1,1,2},
        {2,1,1,1,1,2,1,2},
        {2,2,2,2,2,2,2,2}
    };
    pair<int,int> exit;
    queue<pair<int,int>> flags;
    findExit(1,1,&exit,flags);
    cout<<"Exit: X: "<<exit.first<<" Y: "<<exit.second;
    return 0;
}