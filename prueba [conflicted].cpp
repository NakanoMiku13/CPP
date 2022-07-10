#include <bits/stdc++.h>
using namespace std;
auto F(vector<bool> i)->vector<bool>{
    i.push(F(i));
    return F(i);
}
int main()
{
    vector<bool> i;
    auto Fx = F(i);
}