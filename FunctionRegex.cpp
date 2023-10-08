#include<regex>
#include<iostream>
#include<string>
using namespace std;
auto main()->int{
    while(true){
        string expression = "int\\s[A-Za-z]+[A-Za-z0-9]*(\\_{1}[A-Za-z]+[A-Za-z0-9]*)*(\\(\\)|((\\(\\s?[A-Za-z]+[A-Za-z0-9]*(\\_{1}[A-Za-z]+[A-Za-z0-9]*)*\\)))|((\\(\\s?[A-Za-z]+[A-Za-z0-9]*(\\_{1}[A-Za-z]+[A-Za-z0-9]*)*(\\s?\\,[A-Za-z]+[A-Za-z0-9]*(\\_{1}[A-Za-z]+[A-Za-z0-9]*)*)*\\))))";
        string evaluate = "";
        getline(cin,evaluate);
        bool match = regex_match(evaluate,regex(expression));
        if(match) cout<<"Match"<<endl;
        else cout<<"Fail"<<endl;
    }
}