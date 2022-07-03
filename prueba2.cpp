#include<bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int rands = rand()%1000;
    do{
        cout<<rands<<endl;
    }while((rands*=(rand()%4)+1)<(rand()%10000));

    return 0;
}