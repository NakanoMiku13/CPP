#include<stdio.h>
#include<stdlib.h>
typedef struct list list,*function;
struct Node{
    int value;
    struct Node* next;
};
struct list{
    struct Node* head;
    size_t size;
    function (*ctr)(list*),(*add)(list*,int),(*remove)(list*);
};
function ctr(list*),add(list*,int);
function remove(list*);
int main(){

}
function ctr(list* lst){
    lst->head=(struct Node*)malloc(sizeof(struct Node));
    lst->size=0;
}
function add(list* lst, int value){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->value=value;
    if(lst->size==0 || lst->head==NULL){
        lst->head=new;
    }else{
        int i=0;
        struct Node* move = lst->head;
        for(i=0;i<lst->size-1;i++,move=move->next);
        move->next=new;
    }
    lst->size++;
}
function remove(list* lst){
    if(lst->size>0 && lst->head!=NULL){
        struct Node* move = lst->head;
        int i=0;
        for(i=0;i<lst->size;i++,move=move->next);
        free(move);
        lst->size--;
    }
}
