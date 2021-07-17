#include<bits/stdc++.h>
using namespace std;
auto Recursiva(int ini,int fin)->bool{
	cout<<"Ini="<<ini<<"\nFin="<<fin<<endl;
	if(ini==fin) return true;
	return Recursiva(ini+1,fin);
}
auto main()->int{
	if(Recursiva(0,5)) cout<<"Finalizo";
	else cout<<"Error";
}
