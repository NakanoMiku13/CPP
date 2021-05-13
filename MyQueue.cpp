#include<bits/stdc++.h>
using namespace std;
struct Nodo{
    int Value;
    Nodo* next;
};
struct Stack{
    int Size=0;
    Nodo* Head=nullptr;
    bool Empty(){
        if(Size==0){
            return true;
        }
        return false;
    }
    void Push(int x){
        Size++;
        Nodo* tmp=new Nodo();
        tmp->Value=x;
        if(Head==nullptr){
            Head=tmp;
        }else{
            Nodo* move=Head;
            Head=tmp;
            Head->next=move;
            move=nullptr;
        }
    }
    int Header(){
        return Head->Value;
    }
    void Pop(){
        Size--;
        Nodo* tmp=Head;
        Head=Head->next;
        delete(tmp);
    }
};
int main(){
    Stack x;
    int n;
    cin>>n;
    for(auto i=0;i<n;i++){
        int y;
        cin>>y;
        x.Push(y);
    }
    while(!x.Empty()){
        cout<<x.Header()<<endl;
        x.Pop();
    }
}