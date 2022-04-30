#include<bits/stdc++.h>
using namespace std;
map<char,int> numberCards;
auto clean(string cards,const auto n)->string{
    string tmp="";
    for(auto i=0;i<n;i++){
        numberCards[cards[i]]++;
        if(cards[i]!=cards[i+1]) tmp+=cards[i];
    }
    return tmp;
}
auto getCoins(string cards,auto quantityToChoose)->unsigned long long int{
    vector<pair<int,char>> letters;
    for(auto i:cards) letters.push_back({numberCards[i],i});
    sort(letters.begin(),letters.end());
    auto i=letters.size()-1;
    unsigned long long int sum=0;
    while(quantityToChoose>0){
        auto x = letters[i];
        auto y = 0;
        while(x.first>0 && quantityToChoose>0){
            quantityToChoose--;
            x.first--;
            y++;
        }
        if(y>1) sum+= pow (y,2);
        else sum++;
        i--;
    }
    return sum;
}
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    string cards,filter;
    cin>>n>>m>>cards;
    sort(cards.begin(),cards.end());
    filter = clean(cards,n);
    cout<<getCoins(filter,m);
}