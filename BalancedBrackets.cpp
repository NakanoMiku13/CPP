#include<bits/stdc++.h>
using namespace std;
//Cuonter for the input brackets
int input_counter=0;
auto checkIfInput(char bracket)->bool{
    char inputs[]={'(','{','['};
    if(bracket == inputs[0] || bracket == inputs[1] || bracket == inputs[2]){
        return true;
    }
    return false;
}
auto checkIfOut(char bracket)->bool{
    char outs[]={')','}',']'};
    if(bracket == outs[0] || bracket == outs[1] || bracket == outs[2]){
        return true;
    }
    return false;
}
auto checkInputOutput(pair<char,char> toCheck)->bool{
    pair<char,char> pair1 = {'(',')'};
    pair<char,char> pair2 = {'{','}'};
    pair<char,char> pair3 = {'[',']'};
    if(pair1.first == toCheck.first && pair1.second == toCheck.second){
        return true;
    }else if(pair2.first == toCheck.first && pair2.second == toCheck.second){
        return true;
    }else if(pair3.first == toCheck.first && pair3.second == toCheck.second){
        return true;
    }
    return false;
}
auto checkString(string brackets)->bool{
    stack<char> input_bkt;
    for(auto i=0;i<brackets.size();i++){
        if(checkIfInput(brackets[i])){
            input_counter++;
            input_bkt.push(brackets[i]);
        }else{
            if(checkIfOut(brackets[i])){
                if(input_counter>0){
                    pair<char,char> toCheck = {input_bkt.top(),brackets[i]};
                    if(checkInputOutput(toCheck)){
                        input_counter--;
                        input_bkt.pop();
                        continue;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
    }
    if(input_counter!=0) return false;
    return true;
}

auto main()->int{
    int n=0;
    cin>>n;
    for(auto i=0;i<n;i++){
        string brackets;
        cin>>brackets;
        if(checkString(brackets)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
        input_counter=0;
    }
}