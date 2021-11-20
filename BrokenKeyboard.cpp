#include<bits/stdc++.h>
using namespace std;
string text;
vector<char> tmp,tmp2;
void Check(){
    for(int i=0;i<text.length();i++){
        if(text[i]=='['){
            int j=i+1;
            while(text[j]!=']'){
                if(text[j]!='[' && text[j]!=']')tmp.push_back(text[j]);
                j++;
            }
            i+=j;
        }
    }
    for(int j=0;j<tmp.size();j++){
       tmp2.push_back(tmp[j]);
    }
    for(int i=0;i<text.size();i++){
        if(text[i]=='[') i+=tmp.size();
        if(text[i]!='[' && text[i]!=']') tmp2.push_back(text[i]);
    }
    for(int i=0;i<tmp2.size();i++){
        cout<<tmp2[i];
    }
    cout<<endl;
    tmp.clear();
    tmp2.clear();
    text="";
}
int main(){
    while(cin>>text && !cin.eof()) Check();
}