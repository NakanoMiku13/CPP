#include<bits/stdc++.h>
#include<regex>
#include <fstream>
#include <filesystem>
using namespace std;
using namespace filesystem;
map<string, bool> libraries = {
    pair<string, bool>("#include<cassert>", true),
    pair<string, bool>("#include<cwctype>", true),
    pair<string, bool>("#include<cstdarg>", true),
    pair<string, bool>("#include<csetjmp>", true),
    pair<string, bool>("#include<csignal>", true),
    pair<string, bool>("#include<cstddef>", true),
    pair<string, bool>("#include<cctype>", true),
    pair<string, bool>("#include<ctime>", true),
    pair<string, bool>("#include<cmath>", true),
    pair<string, bool>("#include<cstring>", true),
    pair<string, bool>("#include<cstdlib>", true),
    pair<string, bool>("#include<cstdio>", true),
    pair<string, bool>("#include<atomic>", true),
    pair<string, bool>("#include<initializer_list>", true),
    pair<string, bool>("#include<new>", true),
    pair<string, bool>("#include<exception>", true),
    pair<string, bool>("#include<typeinfo>", true),
    pair<string, bool>("#include<memory>", true),
    pair<string, bool>("#include<array>", true),
    pair<string, bool>("#include<tuple>", true),
    pair<string, bool>("#include<future>", true),
    pair<string, bool>("#include<thread>", true),
    pair<string, bool>("#include<chrono>", true),
    pair<string, bool>("#include<random>", true),
    pair<string, bool>("#include<regex>", true),
    pair<string, bool>("#include<bitset>", true),
    pair<string, bool>("#include<iostream>", true),
    pair<string, bool>("#include<iomanip>", true),
    pair<string, bool>("#include<fstream>", true),
    pair<string, bool>("#include<sstream>", true),
    pair<string, bool>("#include<cmath>", true),
    pair<string, bool>("#include<cstdlib>", true),
    pair<string, bool>("#include<ctime>", true),
    pair<string, bool>("#include<cstring>", true),
    pair<string, bool>("#include<cctype>", true),
    pair<string, bool>("#include<vector>", true),
    pair<string, bool>("#include<list>", true),
    pair<string, bool>("#include<queue>", true),
    pair<string, bool>("#include<stack>", true),
    pair<string, bool>("#include<map>", true),
    pair<string, bool>("#include<set>", true),
    pair<string, bool>("#include<algorithm>", true),
    pair<string, bool>("#include<iterator>", true),
    pair<string, bool>("#include<functional>", true),
    pair<string, bool>("#include<numeric>", true),
    pair<string, bool>("#include<utility>", true)
},
datatypes = {
    pair<string, bool>("bool", true),
    pair<string, bool>("char", true),
    pair<string, bool>("unsigned char", true),
    pair<string, bool>("short", true),
    pair<string, bool>("unsigned short", true),
    pair<string, bool>("int", true),
    pair<string, bool>("unsigned int", true),
    pair<string, bool>("long", true),
    pair<string, bool>("unsigned long", true),
    pair<string, bool>("long long", true),
    pair<string, bool>("unsigned long long", true),
    pair<string, bool>("float", true),
    pair<string, bool>("double", true),
    pair<string, bool>("long double", true),
    pair<string, bool>("wchar_t", true),
    pair<string, bool>("string", true)

};
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
        if(count >= length) return true;
    }
    return false;
}
auto RemoveCharacter(char character, string text)->string{
    string newString = "";
    for(auto i : text) if(i != character) newString += i;
    return newString;
}
auto SearchFunction(string line) -> bool{

}
auto SearchVariable(string line) -> bool{

}
auto ReadFile(string fileName) -> bool{
    bool existMain = false;
    int line = 0;
    try{
        if(!Contains(".cpp",fileName)) throw runtime_error("The file have to be with extention .cpp");
        ifstream file(fileName);
        if(!file) throw runtime_error("Cannot open the file: " + fileName);
        else{
            string output;
            while(getline(file, output)){
                cout<<output<<endl;
                // Verifying if exist a libary
                if(!Contains("//", output)){
                    // Verify if its a library
                    if(regex_match(output, regex("#\\s?include\\s?\\<\\w+(\\.h)?\\>"))){
                        if(!libraries[RemoveCharacter(' ', output)]){
                            throw runtime_error("Error in line "+to_string(line)+"\nThe library "+output+" must exist on the repository");
                        }
                    }else{
                        // Two cases variables of functions
                        if(regex_match(output, regex(""))){
                            // Global Variables
                        }else if(regex_match(output, regex(""))){
                            // Functions
                        }
                    }
                }
                line++;
            }
        }
        return existMain ? true : false;
    }catch(const exception& ex){
        cerr << ex.what() << endl;
    }
    return false;
}
auto main(int args, char* arguments[])->int{
    for(int i = 0; i < args ; i++){
        system("clear");
        if(ReadFile(arguments[i])) cout << "Compilation success\n";
        else cout << "Error while compiling\n";
    }
    return 0;
}
