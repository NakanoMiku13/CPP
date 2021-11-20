#include<bits/stdc++.h>
using namespace std;
long cents,dollars;
void CalculateTotal(string tmp,unordered_map<char,int> prices){
    int c=0;
    for(int j=0;j<=tmp.size();j++){
        cents+=prices[tmp[j]];
        if(cents>=100){
            cents-=100;
            dollars++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int arr[5][2];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        unordered_map<char,int> prices(0);
        long wordsCount,paragraphs;
        cin>>wordsCount;
        for(int j=0;j<wordsCount;j++){
            char letter;
            int Price;
            cin>>letter>>Price;
            prices[letter] = Price;
        }
        cin>>paragraphs;
        for(int j=0;j<=paragraphs;j++){
            string tmp;
            getline(cin,tmp);
            CalculateTotal(tmp,prices);
        }
        arr[i][0]=dollars;
        arr[i][1]=cents;
        cents=dollars=0;
    }
    for(int i=0;i<n;i++){
        if(arr[i][1]<10){
            cout<<arr[i][0]<<".0"<<arr[i][1]<<"$"<<endl;
        }else cout<<arr[i][0]<<"."<<arr[i][1]<<"$"<<endl;
    }
}