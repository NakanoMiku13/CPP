#include<iostream>
#include<regex>
#include<vector>
using namespace std;
auto Split(string separator, string content) -> vector<string>{
    //Gramaticas ambiguas y libres de contexto
    vector<string> splits = vector<string>();
    string buffer = "";
    for(int i = 0; i < content.size() ; i++){
        if(content[i] == separator[0]){
            bool complete = true;
            int j = 0;
            for( ; j < separator.size() && j + i < content.size() ; j++)
                if(content[i + j] != separator[j]){
                    complete = false;
                    break;
                }
            if(complete){
                splits.push_back(buffer);
                buffer = "";
                i += j + 1;
            }
        }
        buffer += content[i];
    }
    splits.push_back(buffer);
    return splits;
}
auto Replace(string original, string replace, string text) -> string{
    string buffer = "";
    int j = 0, k = 0;
    for(int i = 0 ; i < text.size() ; i++){
        if(text[i] == original[0]){
            int m = 0;
            for(m = 0 ; m < original.size(); m++) if(original[m] != text[i + m]) break;
            
        }
        buffer 
    }
}
auto main()->int{
    string input = "s";
    //cin>>input;
    vector<string> t = Split("+=", "i += 1 += 2 += 3");
    cout << (regex_match(input, regex("(\\+\\+|\\-\\-).")) ? "Match" : "No Match") << endl;
    for(auto i : t) cout<<i<<endl;
    return 0;
}