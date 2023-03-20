#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
vector<vector<int>> lab,temp;
int steps, height, width;
auto printMap(vector<vector<int>> lab,int x, int y)->void{
    for(int i = 0 ; i < lab.size() ; i++){
        for(int j = 0 ; j < lab[i].size() ; j++){
            if(i == y && x == j) cout<<"* ";
            else cout<<lab[i][j]<<" ";
        }
        cout<<endl;
    }
}
auto fillEmpty(int h, int w)->void{
    for(int i = 0 ; i < h ; i++) for(int j = 0 ; j < w ; j++) lab[i][j] = 2;
}
auto findExit(const int x,const int y, pair<int,int>* exit,queue<pair<int,int>> flags)->void{
    if(lab[y][x] == 3 or lab[y+1][x] == 3 or lab[y-1][x] == 3 or lab[y][x+1] == 3 or lab[y][x-1] == 3) {
        exit->first = x;
        exit->second = y;
        while(!flags.empty()) flags.pop();
        temp = lab;
        fillEmpty(height,width);
        return;
    }
    else{
        steps++;
        if(lab[y][x] == 1){
            lab[y][x] = 0;
            cout<<"X: "<<x<<" Y: "<<y<<endl;
            cout<<"Flags: "<<flags.size()<<" Steps: "<<steps<<endl;
            printMap(lab,x,y);
            usleep(50000);
            system("clear");
            if(!flags.empty() && lab[y-1][x] != 1 && lab[y+1][x] != 1 && lab[y][x+1] != 1 && lab[y][x-1] != 1){
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
auto createProcedureMap()->vector<vector<int>>{
    vector<vector<int>> labyrinth;
    int height = rand() % 50 + 8, width = height;
    for(int i = 0 ; i < height; i++){
        vector<int> row;
        if(i == 0 or i == height -1) for(int j = 0 ; j < width ; row.push_back(2), j++);
        else{
            row.push_back(2);
            for(int j = 1 ; j < width -1 ; j++) row.push_back(1);
            row.push_back(2);
        }
        labyrinth.push_back(row);
    }
    //Setting exit
    int exitX = rand() % width - 1, exitY = rand() % height - 1;
    labyrinth[exitY][exitX] = 3;
    //Setting other walls
    for(int i = 0 ; i < height ; i++){
        if(i == 0 or i == height) continue;
        else {
            for(int j = 0 ; j < width ;){
                int trap = rand() % 3;
                //if(i != 1 && j != 1)
                switch(trap){
                    case 0: if(labyrinth[i][j] == 1) labyrinth[i][j] = 2; j++; break;
                    case 1: j++; break;
                    default: j++; break;
                }
            }
        }
    }
    if(exitY + 1 < height) labyrinth[exitY+1][exitX] = 1;
    if(exitY - 1 > 0) labyrinth[exitY-1][exitX] = 1;
    if(exitX + 1 < height) labyrinth[exitY][exitX+1] = 1;
    if(exitX - 1 > 0) labyrinth[exitY][exitX-1] = 1;
    if(exitY + 1 < height) if(exitX + 1 < height) labyrinth[exitY+1][exitX+1] = 1;
    if(exitY + 1 < height) if(exitX - 1 > 0) labyrinth[exitY+1][exitX-1] = 1;
    if(exitY - 1 > 0) if(exitX + 1 < height) labyrinth[exitY-1][exitX+1] = 1;
    if(exitX - 1 > 0) if(exitX - 1 > 0) labyrinth[exitY-1][exitX-1] = 1;
    if(labyrinth[1][1] == 2) labyrinth[1][1] = 1;
    return labyrinth;
}
auto main()->int{
    srand(time(NULL));
    lab = createProcedureMap();
    temp = lab;
    width = lab.size(), height = width ;
    pair<int,int> exit = pair<int,int>({0,0});
    queue<pair<int,int>> flags;
    findExit(1,1,&exit,flags);
    if(exit.first == 0 && exit.second == 0){
        cout<<"There no exist exit"<<endl;
        printMap(temp,exit.first,exit.second);
        return 0;
    }
    cout<<"Exit: X: "<<exit.first<<" Y: "<<exit.second<<endl;
    cout<<"Steps: "<<steps<<" Height: "<<height<<" Width: "<<width<<endl;
    printMap(temp,exit.first,exit.second);
    return 0;
}