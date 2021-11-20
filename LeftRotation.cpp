#include<bits/stdc++.h>
using namespace std;
struct Node{
    int v;
    Node* next,*prev;
};
struct Queue{
    Node* head;
    Node* back;
    Queue(){
        head=nullptr;
        back=nullptr;
    }
    bool empty(){
        if(head==nullptr) return true;
        return false;
    }
    void pushBack(int x){
        auto node=new Node();
        node->v=x;
        if(empty()){
            head=back=node;
        }else{
            auto move = head;
            head=node;
            move->prev=head;
            head->next=move;
            move=nullptr;
        }
    }
    void Swap(){
        int x = back->v;
        back=back->prev;
        pushBack(x);
    }
    void print(){
        auto move =back;
        while(move!=nullptr){
            cout<<move->v<<" ";
            move=move->prev;
        }
        cout<<endl;
    }
    void PopFront(){
        if(!empty()){
            auto tmp = head;
            head=head->next;
            delete(tmp);
        }
    }
};
auto main()-> int {
    Queue xd;
    int n,m;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        xd.pushBack(x);
    }
    for(int i=0;i<m;i++) xd.Swap();
    xd.print();
    
}
