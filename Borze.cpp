#include<bits/stdc++.h>
using namespace std;
string input;
queue<char> values;
auto main()->int{
    char tmp=' ';
    cin>>input;
    if(input=="."){
        cout<<"0";
        return 0;
    }else if(input=="-."){
        cout<<"1"; return 0;
    }else if(input=="--"){
        cout<<"2"; return 0;
    }
    for(auto i=0;i<input.size();i++) values.push(input[i]);
    while(!values.empty()){
        if(values.size()==1 && tmp==' ' && values.front()=='.'){
            cout<<"0";
        }else if(tmp==' ' && values.front()=='.'){
            tmp = ' ';
            cout<<"0";
        }else if(tmp==' ' && values.front()=='-'){
            tmp='-';
        }else if(tmp=='.' && values.front()=='-'){
            cout<<"0";
            tmp='-';
        }else if(tmp=='.' && values.front()=='.'){
            cout<<"0";
            tmp=' ';
        }else if(tmp=='-' && values.front()=='.'){
            cout<<"1";
            tmp=' ';
        }else if(tmp=='-' && values.front()=='-'){
            cout<<"2";
            tmp=' ';
        }
        values.pop();
    }
}