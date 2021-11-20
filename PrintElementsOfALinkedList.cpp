#include<bits/stdc++.h>
using namespace std;
struct Node{
    int v;
    Node* next;
};
struct LinkedList{
    Node* head;
    int size;
    LinkedList(){
        head=new Node();
        size=0;
    }
    void Add(int x){
        Node* New=new Node();
        New->v=x;
        if(size==0){
            head=New;
        }else{
            Node* move=head;
            for(int i=0;i<size-1;i++,move=move->next);
            move->next=New;
        }
        size++;
    }
    void Print(){
        if(size>0){
            Node* move=head;
            for(int i=0;i<size;i++,move=move->next) printf("%d\n",move->v);
        }
    }
};
auto main()->int{
    LinkedList list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        list.Add(x);
    }
    list.Print();
}