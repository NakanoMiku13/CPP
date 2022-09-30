#include<bits/stdc++.h>
#include <regex>
using namespace std;
map<string,int> letters;
bool doubleLetter = false, lambda = false;
string w1,w2;
auto typeOfRange()->void{
    int n;
    cin>>n;
    switch(n){
        case 1:
        {
            int m = 0;
            do{
                cout<<"Type the number of characters\n";
                cin>>m;
                if(m < 3) cout<<"Try again\n";
            }while(m < 3);
            for(auto i = 0;i < m; i++){
                string tmp;
                cin>>tmp;
                if(tmp.size() == 1 and tmp[0] == (char)157) lambda = true;
                if(tmp.size() > 1) doubleLetter = true;
                letters[tmp] = 1;
            }
            break;
        }
        case 2:
        {
            string range = "";
            cin>>range;
            char begin = range[0],end = range[range.size()-1];
            for(char i = begin; i <= end; i++){
                string tmp = "";
                tmp += i;
                letters[tmp] = 1;
            }
            break;
        }
        default:
            cout<<"Error\n";
            break;
    }
}
auto validateString(const string val)->bool{
    if(!doubleLetter){
        int x = 0;
        for(auto i : val){
            string j = "";
            j += i;
            if(letters[j] != 1) return false;
        }
        return true;
    }else{
        vector<string> tmpLetters;
        string tmp = "";
        for(auto i = 0,j = 0; i < val.size();i++){
            tmp += val[i];
            if(j == 1) tmpLetters.push_back(tmp), j = 0, tmp = "";
            else j++;
        }
        for(auto i : tmpLetters){
            if(letters[i] != 1) return false;
        }
        return true;
    }
}
auto verifyPrefix(auto a, string b)->bool{
    int c = 0;
    for(auto i : a){
        int n = i.size(), k = 0;
        for(auto j = 0; j < n ;j++, k++) if(i[j] != b[j]) break;
        if(k >= n) c++;
    }
    return (c >= 1) ? true : false;
}
auto verifySuffix(auto a,string b)->bool{
    int c = 0;
    for(auto i : a){
        int n = i.size(), k = 0;
        for(auto j = n; j >= 0; j--, k++) if(i[j-1] != b[b.size()-j]) break;
        if(k >= n) c++;
    }
    return (c >= 1) ? true : false;
}
auto defineTypes(string a,string b)->void{
    vector<string> suffixes,prefixes;
    //Prefixes
    auto n = a.size();
    for(auto i = 0; i < n; i++){
        string tmp = "";
        for(auto j = 0; j <= i; j++) tmp += a[j];
        prefixes.push_back(tmp);
    }

    //Suffixes 157 ascii
    for(auto i = n; i > 0 ; i--){
        string tmp = "";
        for(auto j = n; j >= i; j--) tmp += a[j-1];
        suffixes.push_back(tmp);
    }
    if(verifyPrefix(prefixes,b) and !lambda) cout<<"Self Prefix\n";
    if(verifySuffix(suffixes,b) and !lambda) cout<<"Self Suffix\n";
    if(verifyPrefix(prefixes,b) and lambda) cout<<"Prefix\n";
    if(verifySuffix(suffixes,b) and lambda) cout<<"Suffix\n";
    if(verifySuffix(suffixes,b))
        for(auto i : suffixes)
            cout<<i<<" is a substring, subsequence and a combination of the string "<<b<<endl;
    if(verifyPrefix(prefixes,b))
        for(auto i : prefixes)
            cout<<i<<" is a substring, subsequence and a combination of the string "<<b<<endl;
    if(!verifySuffix(suffixes,b) and !verifyPrefix(prefixes,b)) cout<<"Not subsequence, substring, combination, prefixes and suffixes\n";
}
auto getRandomLetter()->string{
    int r = rand() % letters.size();
    auto i = letters.begin();
    for(auto j = 0;i != letters.end() and j < r; i++,j++);
    return i->first;
}
auto createAlphabet(auto numberOfWords,auto length)->vector<string>{
    vector<string> newAlphabet;
    for(auto i = 0; i < numberOfWords; i++){
        string tmp = "";
        for(auto j = 0;j < length; j++){
            tmp += getRandomLetter();
        }
        newAlphabet.push_back(tmp);
    }
    return newAlphabet;
}
auto printLanguages(auto alphabet)->void{
    for(auto i : alphabet) cout<<i<<"\n";
}
auto differenceAlphabets(auto l1,auto l2)->vector<string>{
    vector<string> newAlphabet;
    map<string,int> temp;
    for(auto i : l1){
        for(auto j : l2){
            if(i != j) temp[i] = 1;
            else{
                temp[i] = 0;
                break;
            }
        }
    }
    for(auto i = temp.begin(); i != temp.end();i++) if(i->second == 1) newAlphabet.push_back(i->first);
    cout<<"\nD1\n";
    for(auto i:newAlphabet) cout<<i<<endl;
    return newAlphabet;
}
auto alphabets(){
    int numberOfWords, length;
    cout<<"Type the length of the words in the new alphabet\n";
    cin>>length;
    cout<<"Type the number of words for the alphabet\n";
    cin>>numberOfWords;
    cout<<"Creating alphabet L1\n";
    auto L1 = createAlphabet(numberOfWords,length);
    cout<<"Creating alphabet L2\n";
    auto L2 = createAlphabet(numberOfWords,length);
    cout<<"This is L1:\n";
    printLanguages(L1);
    cout<<"\nThis is L2:\n";
    printLanguages(L2);
    auto D1 = differenceAlphabets(L1,L2);
}
auto convertAlphabet()->string{
    string newAlphabet = "";
    for(auto i = letters.begin(); i != letters.end(); i++) newAlphabet += i->first;
    return newAlphabet;
}
auto alphabetPow()->void{
    int n = 0;
    cout<<"Type the power of the new alphabet\n";
    cin>>n;
    auto tmp = convertAlphabet();
    auto aux = convertAlphabet();
    for(auto i = 0;i<abs(n)-1;i++){
        tmp += aux;
    }
    if(n > 0){
        cout<<tmp;
    }else{
        reverse(tmp.begin(),tmp.end());
        cout<<tmp;
    }
}
auto validateInputs()->void{
    bool allValid = true;
    do{
        if(!validateString(w1)){
            cout<<"Type again w1\n";
            cin>>w1;
        }else if(!validateString(w2)){
            cout<<"Type again w2\n";
            cin>>w2;
        }else if(!validateString(w1) and !validateString(w2)){
            cout<<"Type again w1\n";
            cin>>w1;
            cout<<"Type again w2\n";
            cin>>w2;
        }else{
            allValid = false;
        }
    }while(allValid);
}
auto regexFunction()->void{
    regex re("[0-9]?*1[1-1]?[0-9]?*[1+][0-9]?*|[0-9]?*2[2-2]?[0-9]?*[2+][0-9]?*|[0-9]?*3[3-3]?[0-9]?*[3+][0-9]?*|[0-9]?*4[4-4]?[0-9]?*[4+][0-9]?*|[0-9]?*5[5-5]?[0-9]?*[5+][0-9]?*|[0-9]?*6[6-6]?[0-9]?*[6+][0-9]?*|[0-9]?*7[7-7]?[0-9]?*[7+][0-9]?*|[0-9]?*8[8-8]?[0-9]?*[8+][0-9]?*|[0-9]?*9[9-9]?[0-9]?*[9+][0-9]?*");
    string reg;
    bool validate = false;
    cout<<"Type the number sequence without spaces:\n";
    do{
        cin>>reg;
        validate = regex_match(reg,re);
        if(!validate) cout<<"Try again\n";
    }while(!validate);
    cout<<"It is a valid sequence, you can continue, have a nice day.\n";
}
auto main()->int{
    typeOfRange();
    cout<<"Type w1 and w2\n";
    cin>>w1>>w2;
    validateInputs();
    defineTypes(w1,w2);
    alphabets();
    alphabetPow();
    regexFunction();
    return 0;
}