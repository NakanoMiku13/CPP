#include<bits/stdc++.h>
using namespace std;
string text;
queue<char> list;
auto main()->int{
    cin>>text;
    //remove all before h
    int c=0,i=0;
    while(text[i]!='h' && i<text.size()) i++;
    if(i>=text.size()){
        cout<<"NO";
        return 0;
    }
    //remove repeated h's
    while(text[i]=='h' && text[i+1]=='h' && i<text.size()) i++;
    if(i>=text.size()){
        cout<<"NO";
        return 0;
    }
    c=i; i=0;
    string newString;
    //cleaning string
    for(auto j=c;j<text.size();j++){
        newString+=text[j];
    }
    //remove all before e
    while(newString[i+1]!='e' && i<newString.size()) i++;
    if(i>=newString.size()){
        cout<<"NO";
        return 0;
    }
    i++;
    //remove all repeated e's or other letters
    while(newString[i]=='e' && newString[i+1]=='e' && i<newString.size()) i++;
    if(i>=newString.size()){
        cout<<"NO";
        return 0;
    }
    //cleaning string
    text="";
    text+=newString[0];
    for(auto j=i;j<newString.size();j++)text+=newString[j];
    newString="";
    i=0;
    //remove all before l (first)
    while(text[i+2]!='l' && i<text.size()) i++;
    if(i>=text.size()){
        cout<<"NO";
        return 0;
    }
    i+=2;
    char tmp1=text[i];
    //remove all repeated l's or other letters
    while(text[i+1]=='l' && text[i+2]=='l' && i<text.size()) i++;
    if(i>=text.size()){
        cout<<"NO";
        return 0;
    }
    char tmp2=' ';
    if(text[i+1]=='l') tmp2 = text[i+1];
    if(tmp2==' '){
        //found the second l
        int k=i+1;
        while(text[k]!='l' && k<text.size()) k++;
        if(text[k]!='l' or k>=text.size()){
            cout<<"NO";
            return 0;
        }else{
            tmp2=text[k];
        }
    }
    i+=2;
    //cleaning string;
    string final;
    final+=text[0];
    final+=text[1];
    final+=tmp1;
    final+=tmp2;
    for(int j=i;j<text.size();j++) final+=text[j];
    //remove all before o
    text="";
    i=0;
    if(final.size()>4) {
        while(final[i+4]!='o' && i<final.size()) i++;
        if(i>=final.size()){
            cout<<"NO";
            return 0;
        }
        i+=4;
        text+=final[0]; text+=final[1]; text+=final[2]; text+=final[3]; text+=final[i];
        if(text=="hello") cout<<"YES";
        else cout<<"NO";
        return 0;
    }else{
        if(final[i+3]!='o') cout<<"NO";
        else if (final=="hello") cout<<"YES";
        return 0;
    }
}