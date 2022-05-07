#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

long I(long vA,int n);
long D(long vA,int n);
long digitos(long vA);
long PDyV(long A, long B, int n);

int main(){
char A[100],B[100];
int n;
long vA,vB;

cout<<"Ingrese el valor entero de A: ";
cin.getline(A,100,'\n');
cout<<"Ingrese el valor entero de B: ";
cin.getline(B,100,'\n');

n=strlen(A);
vA=atol(A);
vB=atol(B);

cout<<"La multiplicaci"<<(char)162<<"n es: "<<PDyV(vA,vB,n)<<endl;

system("pause");
return 0;
}

long PDyV(long vA,long vB,int n){
long int IA,IB,DB,DA,P1,P2,P3,P4,R;
if(n==1)
return vA*vB;
else {
IA=I(vA,n);
DA=D(vA,n);
IB=I(vB,n);
DB=D(vB,n);

P1=PDyV(IA,IB,n/2);
P2=PDyV(IA,DB,n/2);
P3=PDyV(DA,IB,n/2);
P4=PDyV(DA,DB,n/2);

R=pow(10,n)*P1+pow(10,n/2)*P2+pow(10,n/2)*P3+P4;
return R;
}
}