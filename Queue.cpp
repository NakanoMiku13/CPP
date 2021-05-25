#include<bits/stdc++.h>
using namespace std;
struct Node{
    int Value;
    Node* Next;
};
struct Queue{
    Node* Head=nullptr;
    Node* Front=nullptr;
    Node* End=nullptr;
    int Size=0;
    bool Empty(){
        if(Head==nullptr) return true;
        return false;
    }
    int PFront(){
        return Front->Value;
    }
    int PEnd(){
        return End->Value;
    }
    void Push(int x){
        Node* tmp=new Node();
        tmp->Value=x;
        if(Head==nullptr){
            Head=tmp;
            Front=Head;
            End=Head;
        }else{
            Size++;
            Node* move=Head;
            Head=tmp;
            Head->Next=move;
            End=Head;
            move=nullptr;
        }
    }
    void Pop(){
        if(Head!=nullptr){
            Size--;
            if(Front==Head && Front==End){
                Front=nullptr;
                End=nullptr;
                delete(Head);
            }else{
                Node* tmp = Front;
                Node* move = Head;
                while(move->Next!=tmp){
                    move=move->Next;
                }
                Front=move;
                move=nullptr;
                delete(tmp);
            }
        }
    }
};
int main(){
    Queue data;
    for(int i=1;i<=150;i++){
        data.Push(i);
        cout<<data.PEnd()<<endl;
    }
    cout<<data.PFront()<<endl;
    data.Pop();
    for(int i=0;i<15;i++) data.Pop();
    cout<<data.Size<<" "<<data.PFront();
}
