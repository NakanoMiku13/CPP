#include<iostream>
#include<regex>
using namespace std;
auto main()->int{
    string input;
    cin>>input;
    cout << (regex_match(input, regex("\\_?[a-zA-Z]+(\\_{1}[a-zA-Z]+[a-zA-Z0-9]*|[a-zA-Z0-9]+)*\\s?(\\+\\+|\\-\\-|\\+\\=|\\-\\=|\\*\\*|\\*\\=|\\/\\=)((\\s?\\_?[a-zA-Z]+(\\_{1}[a-zA-Z]+[a-zA-Z0-9]*|[a-zA-Z0-9]+)*)|(0-9)+)?")) ? "Match" : "No Match") << endl;
    return 0;
}