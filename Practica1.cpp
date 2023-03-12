#include<bits/stdc++.h>
using namespace std;
auto verifyRange(string range)->int{
    if(range.empty()) return 1;
    else{
        if(range.size() > 3) return 5;
        if(range[0] != ' ' && range[0]==' ') return 2;
        else if(range[0]>range[2] && range[2] != ' ') return 3;
        else if((int)range[0] < 33 or (int)range[2]>125) return 4;
        else if(range[1] != '-') return 5;
        else return 0;
    }
}
auto generateAlphabet()->vector<string>{
    int alphabetLength, option;
    vector<string> alphabet = vector<string>();
    try{
        cout<<"Do you want to define the alphabet? (1) or been generated (2)? ";
        cin>>option;
        switch(option){
            case 1:
            {
                cout<<"Type, how many symbols do you want in your alphabet (higher than 3): ";
                do{
                    cin>>alphabetLength;
                    if(alphabetLength < 3 && alphabetLength > 0) cout<<"The number must be higher than 2"<<endl;
                    else throw 1;
                }while(alphabetLength < 3);
                string symbol;
                for(int i = 0 ; i < alphabetLength ; i++){
                    try{
                        cout<<"Type the symbol ("<<i<<"): ";
                        cin>>symbol;
                        if(symbol.empty()) throw 1;
                        alphabet.push_back(symbol);
                    }catch(int error){
                        switch(error){
                            case 1: cout<<"The symbol can not be null (empty)"<<endl; break;
                            default: throw 505; break;
                        }
                    }
                    catch(...){
                        cout<<"Error not handled"<<endl;
                    }
                }
                if(alphabet.size() == 0) throw 104;
            }
            break;
            case 2:
            {
                string range;
                cout<<"Type the range to define, like (a-z, A-z, 9-a, 0-1) or ASCII Mode (min 33, max 125) like 34-79. (Type 1 for special options): ";
                try{
                    cin>>range;
                    if(range == "1"){

                    }else{
                        if(range .size() == 1) throw 5;
                        int validation = verifyRange(range);
                        if(validation == 0){
                            char begin = range[0], end = range[2];
                            for(auto i = begin ; i <= end ; i++){
                                string symbol = "";
                                symbol += i;
                                alphabet.push_back(symbol);
                            }
                            if(alphabet.size() == 0) throw 104;
                        }else throw validation;
                    }
                }catch(int error){
                    switch(error){
                        case 1: cout<<"The range can not be empty"<<endl; break;
                        case 2: cout<<"The begin or end can not be null"<<endl; break;
                        case 3: cout<<"The begin can not be higher than the end"<<endl; break;
                        case 4: cout<<"The begin or end can not be out of range"<<endl; break;
                        case 5: cout<<"Format error"<<endl; throw 2; break;
                        case 104: throw 104; break;
                        default: throw 505; break;
                    }
                }
                catch(...){
                    cout<<"Error not handled"<<endl;
                }
            }
            break;
            default: throw 2;
        }
    }
    catch(int error){
        switch(error){
            case 1: cout<<"The number can not be zero"<<endl; break;
            case 2: cout<<"Error, option no valid..."<<endl; return vector<string>(); break;
            case 104: cout<<"Error unknown while generating the alphabet"<<endl;
            default: cout<<"Error not handled"<<endl;
        }
    }
    catch(...){
        cout<<"Error not handled"<<endl;
    }
    return alphabet;
}
auto setString(vector<string> alphabet, map<string,bool> verification)->string{
    string str;
    bool check = false;
    cout<<"Type your string to evaluate: ";
    do{
        try{
            cin>>str;
            if(str.size() == 0) throw 1;
            for(auto i : str){
                string symbol = "";
                symbol += i;
                if(!verification[symbol]) throw 2;
            }
            check = true;
        }catch(int error){
            switch(error){
                case 1: cout<<"The string can not be null"<<endl; break;
                case 2: cout<<"The string is not valid"<<endl; break;
                default: cout<<"Error not handled"<<endl; break;
            }
            cout<<"Try again..."<<endl;
        }catch(...){
            cout<<"Error not handled"<<endl;
        }
    }while(!check);
    return str;
}
//Realizar punto 3
auto generateLanguage(vector<string> alphabet)->vector<string>{
    vector<string> language = vector<string>();
    try{
        int length,wordsNumber;
        cout<<"Type the number of words: ";
        cin>>wordsNumber;
        if(wordsNumber == 0) throw 1;
        cout<<"Type the length of the words: ";
        cin>>length;
        if(length == 0) throw 2;
        for(int i = 0, ran ; i < wordsNumber ; i++){
            string word = "";
            for(int j = 0 ; j < length ; j++) word += alphabet[rand()%(alphabet.size())];
            if(word == "") throw 4;
            language.push_back(word);
        }
        if(language.size() == 0) throw 3;
    }catch(int error){
        switch(error){
            case 1: cout<<"The number of words can not be zero"<<endl; break;
            case 2: cout<<"The length of the words can not be zero"<<endl; break;
            case 3: cout<<"Error generating the language..."<<endl; break;
            case 4: cout<<"Error generating a word..."<<endl; break;
            default: cout<<"Error not handled"<<endl;
        }
    }
    catch(...){
        cout<<"Error not handled"<<endl;
    }
    return language;
}
auto differenceBetweenLanguages(vector<string> language1,vector<string> language2)->vector<string>{
    vector<string> difference;
    try{
        if(language1.size() == 0 or language2.size() == 0) throw 1;
        map<string,bool> exist;
        for(auto i : language2) exist[i] = true;
        if(exist.size() == 0) throw 2;
        for(auto i : language1){
            if(i == "") throw 3;
            if(exist[i] == false) difference.push_back(i);
        }
        if(difference.size() == 0) throw 4;
    }catch(int error){
        switch (error){
            case 1: cout<<"Some language is empty..."<<endl; break;
            case 2: cout<<"The map is empty..."<<endl; break;
            case 3: cout<<"While creating the difference a text is empty..."<<endl; break;
            case 4: cout<<"An error ocurred and the difference is empty..."<<endl; break;
            default: cout<<"Error not handled"<<endl;
        }
    }catch(...){
        cout<<"Error not handled"<<endl;
    }
    return difference;
}
auto generateAlphabetPower(vector<string> alphabet)->vector<string>{
    vector<string> ret = vector<string>();
    try{
        int power;
        cout<<"Type the power: ";
        cin>>power;
        if(power > 10) throw 2;
        else if(power < -10) throw 1;
        else if(power == 0) throw 3;
        if(power < 0){
            reverse(alphabet.begin(),alphabet.end());
            power = abs(power);
            for(auto j = 0 ; j < power ; j++)
                for(auto i : alphabet)
                    ret.push_back(i);
        }else
            for(auto j = 0 ; j < power ; j++)
                for(auto i : alphabet)
                    ret.push_back(i);
        if(ret.size() == 0) throw 4;
    }catch(int error){
        switch(error){
            case 1: cout<<"The power can not be lower than -10"<<endl; break;
            case 2: cout<<"The power can not be higher than 10"<<endl; break;
            case 3: cout<<"The power can not be zero..."<<endl; for(auto i : alphabet) cout<<i<<endl; break;
            case 4: cout<<"Error generating the language..."<<endl; break;
            default: cout<<"Error not handled"<<endl;
        }
    }catch(...){
        cout<<"Error not handled"<<endl;
    }
    return ret;
}
auto main()->int{
    srand(time(NULL));
    vector<string> alphabet = generateAlphabet();
    if(alphabet.size() == 0) return 0;
    map<string,bool> verification;
    for(auto i : alphabet) verification[i] = true;
    string string1 = setString(alphabet, verification), string2 = setString(alphabet,verification);
    vector<string> language1 = generateLanguage(alphabet), language2 = generateLanguage(alphabet), difference = differenceBetweenLanguages(language1,language2);
    cout<<"Language 1:\n";
    for(auto i : language1) cout<<i<<" ";
    cout<<"Language 2:\n";
    for(auto i : language2) cout<<i<<" ";
    cout<<"Difference between Language 1 and Language 2:\n";
    for(auto i : difference) cout<<i<<" ";
    vector<string> alphabetPower = generateAlphabetPower(alphabet);
    cout<<"Alphabet powered:\n";
    for(auto i : alphabetPower) cout<<i<<" ";
    return 0;
}