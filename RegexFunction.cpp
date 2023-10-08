#include<iostream>
#include<vector>
#include<map>
using namespace std;
auto Split(char character, string text, int steps = 10000)->vector<string>{
    vector<string> items = vector<string>();
    string temp = "";
    for(auto i : text){
        if(steps == 0){
            temp += i;
        }else{
            if(i != character){
                temp+=i;
            }else{
                    items.push_back(temp);
                    temp = "";
                    if(steps > 0) steps--;
            }
        }
    }
    items.push_back(temp);
    return items;
}
auto Contains(string subsequence, string text)->bool{
    int count = 0, length = subsequence.length(), x = 0;
    for (auto i : text){
        if(count == length) return true;
        if(subsequence[x] == i){
            x++;
            count ++;
        }
        else{
            count = 0;
            x = 0;
        }
        if(count == length) return true;
    }
    return false;
}
auto RemoveCharacter(char character, string text)->string{
    string newString = "";
    for(auto i : text) if(i != character) newString += i;
    return newString;
}
auto main()->int{
        string text = "int variable = 0;", text2 = "int variable2 = myFunction(arg1, arg2);", text3 = "void function(){";
        map<string, bool> reservedWords = map<string,bool>();
        reservedWords["int"] = true;
        reservedWords["float"] = true;
        reservedWords["double"] = true;
        reservedWords["long"] = true;
        reservedWords["string"] = true;
        reservedWords["char"] = true;
        reservedWords["unsigned"] = true;
        reservedWords["void"] = true;
        vector<string> items = Split(' ', text2, 1);
        int openKey = 0;
        for(auto i : items) {
            if(reservedWords[i]) cout<<"RW ";
            else{
                if(Contains(";", i)){
                    cout<<"VARIABLE ";
                    vector<string> items2 = (vector<string>)(Contains("=", i) ? Split('=', RemoveCharacter(' ', i)) : vector<string>());
                    if(items2.size() == 2 or items2.size() == 3){
                        cout<<"SCH ";
                        if(Contains("(",items2[1]) and Contains(")",items2[1])){
                            cout<<"FUNCTION OCH ";
                            string temp = RemoveCharacter(';',RemoveCharacter(')',(string)Split('(', items2[1])[1]));
                            vector<string> items3 = (vector<string>)Split(',',RemoveCharacter(' ',temp));
                            if(items3.size() > 0) for(auto j : items3) cout<<"ARG ";
                            cout<<"CCH SPC\n";
                        }else if(!Contains("(",items2[1]) and !Contains(")",items2[1])){
                            cout<<"VALUE SPC\n";
                        }
                    }
                }else{
                    if(Contains("{", i)){
                        openKey ++;
                        if(Contains("(", i) and Contains(")", i)){
                            cout<<"FUNCTION ";
                        }
                    }
                    if(Contains("}", i)){
                        openKey --;
                    }
                }
            }
        }
        return 0;
}