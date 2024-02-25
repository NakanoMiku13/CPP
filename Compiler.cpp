#include<bits/stdc++.h>
#include<regex>
#include <fstream>
#include <filesystem>
using namespace std;
using namespace filesystem;
const string variableExpression = "\\_?[a-zA-Z]+(\\_{1}[a-zA-Z]+[a-zA-Z0-9]*|[a-zA-Z0-9]+)*",
boolAssignments = "1|0|(true)|(false)",
charAssignments = "\\'.{1}\\'|\\(\\s?char\\s?\\)\\s?([0-9][0-9]|1[0-9][0-9]|2[0-5][0-5])",
numberAssignment = "\\-?\\d+(\\.\\d+)?([e|E]\\d+)?",
stringAssignment = "\".*\"";
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

},
reservedWords = {
    pair<string, bool>("while", true),
    pair<string, bool>("for", true),
    pair<string, bool>("if", true),
    pair<string, bool>("else", true),
    pair<string, bool>("switch", true),
    pair<string, bool>("case", true),
    pair<string, bool>("break", true),
    pair<string, bool>("endl", true),
    pair<string, bool>("using", true),
    pair<string, bool>("namespace", true),
    pair<string, bool>("class", true),
    pair<string, bool>("struct", true),
    pair<string, bool>("template", true)
},
controlStructures = {
    pair<string, bool>("while", true),
    pair<string, bool>("for", true),
    pair<string, bool>("if", true),
    pair<string, bool>("else", true),
    pair<string, bool>("switch", true)
};
stack <map<string,string>> tempVariables = stack<map<string,string>>();
map<string,string> variablesDeclaration = map<string, string>();
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
auto SplitByString(string base, string text, int steps = 10000)->vector<string>{
    vector<string> items = vector<string>();
    
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
auto ExistTempVariable(string name, string datatype) -> bool{
    stack <map<string,string>> tempVariables2 = tempVariables;
    while(!tempVariables2.empty()){
        map<string,string> variables = tempVariables2.top();
        if(variables[name] != "" and (variablesDeclaration[name] != "" and (variablesDeclaration[name] != datatype or variablesDeclaration[name] == datatype or reservedWords[name]))) return true;
        tempVariables2.pop();
    }
    if(tempVariables.size() > 0){
        map<string,string> variables = tempVariables.top();
        variables[name] = datatype;
        tempVariables.pop();
        tempVariables.push(variables);
    }else{
        map<string,string> variables = map<string,string>();
        variables[name] = datatype;
        tempVariables.push(variables);
    }
    return false;
}
auto VariableExists(string assign, string datatype, int funcEval = 0)->bool{
    if(variablesDeclaration[assign] != "" and (variablesDeclaration[assign] != datatype or variablesDeclaration[assign] == datatype or reservedWords[assign])) return true;
    if(funcEval == 0) variablesDeclaration[assign] = datatype;
    else if(funcEval == 1) return ExistTempVariable(assign, datatype);
    return false;
}
auto IsCasted(string datatype, string expectedDatatype) -> bool{
    map<string, bool> casted = {
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
        pair<string, bool>("bool", true),
        pair<string, bool>("long double", true)
    }, casted1 = {
        pair<string, bool>("string", true)
    }, casted2 = {
        pair<string, bool>("char", true)
    };
    return (casted1[datatype] and casted1[expectedDatatype]) or (casted2[datatype] and casted2[expectedDatatype]) or (casted[datatype] and casted[expectedDatatype]);
}
auto ExistTempVariable2(string name, string expectedDatatype) -> bool {
    stack <map<string,string>> tempVariables2 = tempVariables;
    while(!tempVariables2.empty()){
        map<string,string> variables = tempVariables2.top();
        if(variables[name] != "" and !reservedWords[name] and IsCasted(variables[name], expectedDatatype)) return true;
        tempVariables2.pop();
    }
    return false;
}
auto ExistVariable(string name) -> bool{
    if(variablesDeclaration[name] != "") return true;
    else{
        stack <map<string,string>> tempVariables2 = tempVariables;
        while(!tempVariables2.empty()){
            map<string,string> variables = tempVariables2.top();
            if(variables[name] != "" and !reservedWords[name]) return true;
            tempVariables2.pop();
        }
    }
    return false;
}
auto ContainsOperator(string line) -> bool{
    
}
auto VerifyAssignment(string line, string datatype, string regexExpression, int lineNumber, int funcEval = 0) -> string{
    if(Contains(",", line)){
        //Have multiple assignments
        vector<string> assignments = Split(',', RemoveCharacter(';',RemoveCharacter(' ', line)));
        for(auto assign : assignments){
            if(assign != "") if(Contains("=", assign)){
                if(reservedWords[assign] or datatypes[assign]) return "Error in line: "+to_string(lineNumber)+"\nYou can not use reserved word as a variable name\n";
                //Evaluate all expression and value
                vector<string> temp = Split('=', RemoveCharacter(' ', RemoveCharacter(';', assign)));
                if(!regex_match(temp[0], regex(variableExpression))) return "Error in line: "+to_string(lineNumber)+"\nThe variable name do not correspond to the rules\n";
                if(!regex_match(temp[1], regex(regexExpression)))
                    if(!ExistTempVariable2(temp[1], datatype) and variablesDeclaration[temp[1]] != datatype and !IsCasted(variablesDeclaration[temp[1]],datatype)) return "Error in line "+to_string(lineNumber)+"\nThe assignment do not correspond to a "+datatype+" datatype\n";
                if (ExistTempVariable2(temp[0], datatype) or VariableExists(temp[0], datatype, funcEval)) return "Error in line: "+to_string(lineNumber)+"\nThe variable "+temp[0]+" already exists\n";
            }else{
                if(reservedWords[assign] or datatypes[assign]) return "Error in line: "+to_string(lineNumber)+"\nYou can not use reserved word as a variable name\n";
                //Evaluate variable name
                if(!regex_match(assign, regex(variableExpression))) return "Error in line: "+to_string(lineNumber)+"\nThe variable name do not correspond to the rules\n";
                else if(ExistTempVariable2(assign, datatype) or VariableExists(assign, datatype, funcEval)) return "Error in line: "+to_string(lineNumber)+"\nThe variable "+assign+" already exists\n";
            }
        }
    }else{
        //Single assignment
        if(Contains("=", line)){
            // Value assignation
            vector<string> temp = Split('=', RemoveCharacter(' ', RemoveCharacter(';', line)));
            if(reservedWords[temp[0]] or datatypes[temp[0]]) return "Error in line: "+to_string(lineNumber)+"\nYou can not use reserved word as a variable name\n";
            if(!regex_match(temp[0], regex(variableExpression))) return "Error in line: "+to_string(lineNumber)+"\nThe variable name do not correspond to the rules\n";
            if(!regex_match(temp[1], regex(regexExpression)))
                if(!ExistTempVariable2(temp[1], datatype) and variablesDeclaration[temp[1]] != datatype and !IsCasted(variablesDeclaration[temp[1]],datatype)) return "Error in line "+to_string(lineNumber)+"\nThe assignment do not correspond to a "+datatype+" datatype\n";
            if (ExistTempVariable2(temp[0], datatype) or VariableExists(temp[0], datatype, funcEval))  return "Error in line: "+to_string(lineNumber)+"\nThe variable "+temp[0]+" already exists\n";
        }else{
            // Without assignation
            string line2 = RemoveCharacter(';', line);
            if(reservedWords[line2] or datatypes[line2]) return "Error in line: "+to_string(lineNumber)+"\nYou can not use reserved word as a variable name\n";
            if(!regex_match(line2, regex(variableExpression))) return "Error in line: "+to_string(lineNumber)+"\nThe variable name do not correspond to the rules\n";
            if(ExistTempVariable2(line2, datatype) or VariableExists(line2, datatype, funcEval))  return "Error in line: "+to_string(lineNumber)+"\nThe variable "+line2+" already exists\n";
        }
    }
    return "";
}
auto VerifyAssignmentValueIntegersFloats(string line, string datatype) -> string{
    line = RemoveCharacter(';',RemoveCharacter(' ',line));
    if(Contains("=", line)){
        vector<string> valueV = Split('=', line, 1);
        string valueS = valueV[1];
        if(Contains(".", valueS)){
            long double value = stod(valueS.c_str());
            if(datatype == "float"){
                int capacity = pow(2,(sizeof(float) * 8)) / 2;
                return (capacity > value and (-1)*capacity < value) ? "" : "The value is higher than expected (+-"+to_string(capacity)+")";
            }else if(datatype == "double"){
                int capacity = (int)(pow(2,(sizeof(double) * 8)) / 2);
                return (capacity > value and (-1)*capacity < value and ((Contains("-", valueS)) ? (valueS.size() <= 10) : (valueS.size() <= 11))) ? "" : "The value is higher than expected (+-"+to_string(capacity)+")";
            }
        }else{
            long long int value = atoi(valueS.c_str());
            if(datatype == "short"){
                int capacity = pow(2,(sizeof(short) * 8)) / 2;
                return (capacity > value and (-1)*capacity < value) ? "" : "The value is higher than expected (+-"+to_string(capacity)+")";
            }else if(datatype == "int" or datatype == "long"){
                int capacity = (int)(pow(2,(sizeof(int) * 8)) / 2);
                return (capacity > value and (-1)*capacity < value and ((Contains("-", valueS)) ? (valueS.size() <= 10) : (valueS.size() <= 11))) ? "" : "The value is higher than expected (+-"+to_string(capacity)+")";
            }
        }
    }
    return "";
}
auto VerifyVariableExpression(string line, string datatype, int lineNumber, int funcEval = 0) -> pair<bool, string> {
    if(datatypes[datatype]){
        if(datatype == "bool"){
            string output = VerifyAssignment(line, datatype, boolAssignments, lineNumber, funcEval);
            if(output != "") return pair<bool, string>(false, output);
        }else if(datatype == "char"){
            string output = VerifyAssignment(line, datatype, charAssignments, lineNumber, funcEval);
            if(output != "") return pair<bool, string>(false, output);
        }else if(datatype == "unsigned char"){

        }else if(datatype == "unsigned short"){

        }else if(datatype == "short" or datatype == "int" or datatype == "long" or datatype == "float" or datatype == "double"){
            string output = VerifyAssignment(line, datatype, numberAssignment, lineNumber, funcEval);
            if(output != "") return pair<bool, string>(false, output);
            output = VerifyAssignmentValueIntegersFloats(line, datatype);
            if(output != "") return pair<bool, string>(false, "Error in line: "+to_string(lineNumber)+" "+ output);
        }else if(datatype == "unsigned int"){

        }else if(datatype == "unsigned long"){

        }else if(datatype == "unsigned long long"){
        }else if(datatype == "long double"){

        }else if(datatype == "wchar_t"){

        }else if(datatype == "string"){
            string output = VerifyAssignment(line, datatype, stringAssignment, lineNumber, funcEval);
            if(output != "") return pair<bool, string>(false, output);
        }else{
            return pair<bool,string>(false, "Error in line "+to_string(lineNumber)+"\nThe datatype do not correspond to a variable datatype\n");
        }
    }else{
        return pair<bool,string>(false, "Error in line "+to_string(lineNumber)+"\nThe datatype do not correspond to a variable datatype\n");
    }
    return pair<bool,string>(true, "");
}
auto EraseWhileExists(const string line, const char delimiter) -> string{
    int i = 0;
    string newString = "";
    while(line[i] == delimiter and i < line.size()) i++;
    for(int j = i ; j < line.size() ; newString += line[j], j++);
    return newString;
}
auto VerifyFunctionArguments(string arguments, const int lineNumber) -> pair<bool,string>{
    arguments = RemoveCharacter('{', RemoveCharacter(')', arguments));
    vector<string> args = Split(',', arguments);
    tempVariables = stack<map<string,string>>();
    map<string, string> variables = map<string,string>();
    for(auto i : args){
        string argument = EraseWhileExists(i, ' ');
        vector<string> elements = Split(' ', argument);
        string datatype = elements[0], variableName = elements[1];
        if(Contains("=",argument)){

        }else{
            string err = VerifyAssignment(variableName, datatype, variableExpression, lineNumber, 1);
            if(err != "") return pair<bool,string>(false, err);
        }
    }
    return pair<bool,string>(true, "");
}
auto VerifyBlankLine(const string line) -> bool{
    int count = 0;
    for(auto i : line) if ( i == ' ' or i == '\n' or i == '\t' or i == NULL ) count ++;
    return count == line.size();
}
auto ContainsMultipleOperators(string line) -> bool{
    int count = 0;
    for(auto let : line){
        if(count >= 2) return true;
        switch(let){
            case '+': count++; break;
            case '-': count++; break;
            case '*': count++; break;
            case '/': count++; break;
            case '%': count++; break;
        }
    }
    return false;
}
auto VerifyComplexAssignation(string line) -> bool{
    return (Contains("/=", line) or Contains("+=", line) or Contains("*=", line) or Contains("-=", line) or Contains("%=", line));
}
auto GetDatatype(string line)->string{
    string datatype = "";
    if(regex_match(line, regex(boolAssignments))) datatype = "bool";
    else if(regex_match(line, regex(charAssignments))) datatype = "char";
    else if(regex_match(line, regex(stringAssignment))) datatype = "string";
    else if(Contains(".", line) and line.size() < 16) datatype = "float";
    else if(Contains(".", line) and line.size() > 16) datatype = "double";
    else if(regex_match(line, regex(numberAssignment)) and line.size() <= 10) datatype = "int";
    else if(regex_match(line, regex(numberAssignment)) and line.size() > 10) datatype = "long";
    else{
        // Verify variable datatype
        if(tempVariables.size() > 0){
            // Is on a function
            if(variablesDeclaration[line] != "") datatype = variablesDeclaration[line];
            else{
                stack <map<string,string>> tempVariables2 = tempVariables;
                while(!tempVariables2.empty()){
                    map<string,string> variables = tempVariables2.top();
                    if(variables[line] != "" and !reservedWords[line]){
                        datatype = variables[line];
                        break;
                    }
                    tempVariables2.pop();
                }
            }
        }else{
            // Is not on a function
            if(variablesDeclaration[line] != "") datatype = variablesDeclaration[line];
        }
    }
    return datatype != "" ? datatype : "null";
}
auto VerifySingleOperation(string var1, string var2, char operand) -> bool{
    string datatype1 = GetDatatype(var1), datatype2 = GetDatatype(var2);
    return IsCasted(datatype1,datatype2);
}
auto VerifyIncrement(string line) -> string{
    line = RemoveCharacter(';', line);
    string begin = "(\\+\\+|\\-\\-)"+variableExpression, end = variableExpression+"(\\+\\+|\\-\\-)";
    string var = "";
    if(regex_match(line, regex(begin))) var = Contains("-", line) ? EraseWhileExists(line, '-') : EraseWhileExists(line, '+');
    else if(regex_match(line, regex(end))) var = Contains("-", line) ? RemoveCharacter('-', line) : RemoveCharacter('+', line);
    string datatype = GetDatatype(var);
    if(datatype == "null") return "There is no a valid datatype";
    else return ExistVariable(var) and (VerifySingleOperation(var, "1", '+') or VerifySingleOperation(var, "1", '-')) ? "" : "Is not a variable to make the operation";
}
auto SplitByString(string separator, string content) -> vector<string>{
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
auto VerifyStructControl(string line) -> pair<string, bool>{
    if(Contains("if(", line)) return pair<string, bool>("if", true);
    if(Contains("for(", line)) return pair<string, bool>("for", true);
    if(Contains("while(", line)) return pair<string, bool>("while", true);
    if(Contains("switch(", line)) return pair<string, bool>("switch", true);
    return pair<string, bool>("", false);
    //if(Contains("if(")) return pair<string, bool>("if", true);
}
auto EvaluateStructControl(string line) -> string{
    if(line == "if"){
        // Evaluate condition
        line = 
        if(Contains("{", line)){
            
        }else{

        }
    }
    return "";
}
auto ReadFile(string fileName) -> bool{
    bool existMain = false, isFunction = false;
    int line = 1, openKey = 0;
    try{
        if(!Contains(".cpp",fileName)) throw runtime_error("The file have to be with extention .cpp");
        ifstream file(fileName);
        if(!file) throw runtime_error("Cannot open the file: " + fileName);
        else{
            bool comment = false;
            string output;
            while(getline(file, output)){
                output = RemoveCharacter('\t', RemoveCharacter('\n',output));
                if(output.size() > 0){
                    // Verifying if exist a libary
                    if(!Contains("//", output) and !comment){
                        // Verify if its a library
                        if(Contains("/*", output)) comment = true;
                        else{
                            output = EraseWhileExists(output, ' ');
                            cout << output <<endl;
                            if(!isFunction){
                                if(regex_match(output, regex("#\\s?include\\s?\\<\\w+(\\.h)?\\>"))){
                                    if(!libraries[RemoveCharacter(' ', output)]){
                                        throw runtime_error("Error in line "+to_string(line)+"\nThe library "+output+" must exist on the repository");
                                    }
                                }else{
                                    // Two cases variables or functions
                                    if(Contains(";", output)){
                                        // Global Variables
                                        vector<string> split = Split(' ',output,1);
                                        if(datatypes[split[0]]){
                                            auto t = VerifyVariableExpression(split[1], split[0], line);
                                            if(!t.first) throw runtime_error(t.second);
                                        }else{
                                            throw runtime_error("Error in line "+to_string(line)+"\nThe datatype: "+split[0]+" do not exists");
                                        }
                                    }else if(Contains("{", output)){
                                        // Functions
                                        vector<string> split = Split(' ',output,1);
                                        if(datatypes[split[0]]){
                                            // Separate () from the function and get the name
                                            vector<string> iter = Split('(', split[1]);
                                            string args = iter[1], funcName = iter[0];
                                            auto t = VerifyVariableExpression(funcName, split[0], line);
                                            if(!t.first) throw runtime_error(t.second);
                                            t = VerifyFunctionArguments(args, line);
                                            if(!t.first) throw runtime_error(t.second);
                                            isFunction = true;
                                            openKey ++;
                                        }else{
                                            // Evaluate control structures
                                            throw runtime_error("Error in line "+to_string(line)+"\nThe datatype: "+split[0]+" do not exists");
                                        }
                                    }else{

                                    }
                                }
                            }else{
                                // Evaluate control structures
                                pair<string, bool> control = VerifyStructControl(output);
                                if(control.second){
                                    string controlName = control.first;
                                    if(controlName == "if"){
                                        if(Contains("{", output)){

                                        }else{

                                        }
                                    }
                                }
                                // Evaluate content of a function
                                else if(Contains(";", output)){
                                    // Local Variables
                                    // Verify in variable assignments that can match with the variables declared previously on the stack
                                    vector<string> split = Split(' ',output,1);
                                    if(datatypes[split[0]]){
                                        auto t = VerifyVariableExpression(split[1], split[0], line, 1);
                                        if(!t.first) throw runtime_error(t.second);
                                    }else{
                                        // Verify if its a simple assignation
                                        if(Contains("=", output)){
                                            if(VerifyComplexAssignation(output)){
                                                // Complex Assignation
                                                /*if(Contains("+=", output)) split = SplitByString("+=", output);
                                                else if( Contains("-=", output)) split = SplitByString("-=", output);
                                                else if( Contains("*=", output)) split = SplitByString("*=", output);
                                                else if( Contains("/=", output)) split = SplitByString("/=", output);
                                                else if( Contains("%=", output)) split = SplitByString("\\%=", output);
                                                else split = vector<string>();*/
                                            }else{
                                                split = Split('=', RemoveCharacter(' ', RemoveCharacter(';', output)), 1);
                                                string var1 = split[0], var2 = split[1];
                                                if(!ExistVariable(var1)) throw runtime_error("Error in line "+to_string(line)+"\nOne of the variables do not exists or is incorrect");
                                                else{
                                                    // Verify possible operations
                                                    if(Contains("+", var2) or Contains("-", var2) or Contains("/", var2) or Contains("*", var2) or Contains("%", var2)){
                                                        // Simple / Complex operations
                                                        if(ContainsMultipleOperators(var2)){
                                                            // Complex operations
                                                            cout << "Complex" <<endl;
                                                        }else{
                                                            // Simple operation
                                                            vector<string> operands = vector<string>();
                                                            char _operator = 'N';
                                                            if(Contains("+", var2)) {operands = Split('+', var2); _operator = '+';}
                                                            else if(Contains("-", var2)) {operands = Split('-', var2); _operator = '-';}
                                                            else if(Contains("*", var2)) {operands = Split('*', var2); _operator = '*';}
                                                            else if(Contains("/", var2)) {operands = Split('/', var2); _operator = '/';}
                                                            else if(Contains("%", var2)) {operands = Split('%', var2); _operator = '%';}
                                                            if(!VerifySingleOperation(operands[0], operands[1], _operator)) throw runtime_error("Error in line "+to_string(line)+"\nThe operation is incorrect, must be casted");
                                                        }
                                                    }else{
                                                        // Basic assignation
                                                        if(!ExistVariable(var2)) throw runtime_error("Error in line "+to_string(line)+"\nOne of the variables do not exists or is incorrect");
                                                    }
                                                }
                                            }
                                        }else{
                                            // Verify variable operations ++ --
                                            // Verify outputs or inputs
                                            if(Contains("cout", output)){
                                                if(!Contains("<<", output)) throw runtime_error("Error in line "+to_string(line)+"Must have << operand");
                                                else{
                                                    // Verify content of cout instance
                                                }
                                            }else if(Contains("cin", output)){
                                                if(!Contains(">>", output)) throw runtime_error("Error in line "+to_string(line)+"Must have >> operand");
                                                else{
                                                    // Verify content of cin instance
                                                }
                                            }else{
                                                if(Contains("++", output) or Contains("--", output)){
                                                    string sample = VerifyIncrement(output);
                                                    if(sample.size() > 0) throw runtime_error("Error in line "+to_string(line)+": "+sample);
                                                }else{
                                                    throw runtime_error("Error in line "+to_string(line)+"\nThe datatype: "+split[0]+" do not exists");
                                                }
                                            }
                                        }
                                    }
                                }else if(Contains("{", output)){
                                    // Functions
                                    vector<string> split = Split(' ',output,1);
                                    if(datatypes[split[0]]){
                                        // Separate () from the function and get the name
                                        vector<string> iter = Split('(', split[1]);
                                        string args = iter[1], funcName = iter[0];
                                        auto t = VerifyVariableExpression(funcName, split[0], line);
                                        if(!t.first) throw runtime_error(t.second);
                                        t = VerifyFunctionArguments(args, line);
                                        if(!t.first) throw runtime_error(t.second);
                                        isFunction = true;
                                        openKey ++;
                                    }else{
                                        // Evaluate control structures | Reserved words | simple assignations
                                        throw runtime_error("Error in line "+to_string(line)+"\nThe datatype: "+split[0]+" do not exists");
                                    }
                                }else{

                                }
                            }
                        }
                    }
                    else{
                        if(Contains("//", output)){}
                        if(Contains("*/", output)) comment = false;
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
    int c = 0;
    while(!tempVariables.empty()){
        cout << "Dict: " << c++ << endl;
        for(auto i : tempVariables.top()){
            cout << i.first << " " << i.second << endl;
        }
        tempVariables.pop();
    }
    return 0;
}
