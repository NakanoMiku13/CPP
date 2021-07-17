#include<bits/stdc++.h>
using namespace std;
struct Node{
    int Value;
    Node* Next=nullptr;
};
struct Queue{
    Node* Head=nullptr;
    Node* Front=nullptr;
    Node* End=nullptr;
    int Size=0;
    int OnTop(){
        return Front->Value;
    }
    bool IsEmpty(){
        if(Head==nullptr && Size==0) return true;
        return false;
    }
    void Push(int x){
        Size++;
        Node* tmp=new Node();
        tmp->Value=x;
        if(Head==nullptr){
            Head=tmp;
            Front=Head;
            End=Head;
        }else{
            Node* move=Head;
            Head=tmp;
            Head->Next=move;
            End=Head;
            move=nullptr;
        }
        delete(tmp);
    }
    void Pop(){
        if(!IsEmpty()){
            if(Front==Head && Front==End){
                Front=nullptr;
                End=nullptr;
                Head=nullptr;
                Size--;
            }else{
                Size--;
                Node* tmp=Front;
                Node* move = Head;
                while (move->Next!=Front)
                {
                    move=move->Next;
                }
                Front=move;
                move=nullptr;
                delete(move);
                delete(tmp);
            }
        }
    }
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    Queue canguros;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x;
        char z;
        cin>>z;
        switch(z){
            case 'N':
                canguros.Push(z+1);
                break;
            case 'A':
                n-=canguros.OnTop();
                canguros.Pop();
                break;
            case 'C':
                cout<<canguros.Size<<"\n";
                break;
            case 'R':
                cout<<n<<"\n";
                break;
        }
    }
}