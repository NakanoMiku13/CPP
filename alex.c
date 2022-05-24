#include<stdlib.h>
#include<stdio.h>
int getSize(char* array){
    int i=0;
    while((int)array[i]>=65 && (int)array[i]<=90 || (int)array[i]>=97 && (int)array[i]<=122) i++;
    return i;
}
int search(char* array1, char* array2,int index,int limita1,int limita2){
    int i=index,n=limita1,m=limita2,j=0;
    for(j=0;j<m;i++,j++) if(array1[i]!=array2[j]) return -1;
    return index;
}
int main(){
    char* array1 = (char*)malloc(sizeof(char)*1000);
    char* array2 = (char*)malloc(sizeof(char)*1000);
    gets(array1);
    scanf("%s",array2);
    int i=0,n=getSize(array1),j=0,k=getSize(array2),counter=0;
    while (array1[i] != '\0') {
        if(array1[i]==array2[0]){
            int x = search(array1,array2,i,n,k);
            if(x>-1) printf("%d\n",i);
        }
      i++;
    }
}