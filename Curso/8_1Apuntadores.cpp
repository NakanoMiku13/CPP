#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    int x = 5;
    int* y = &x;
    cout<<"Decimos que X esta alojado en la casa: "<<&x<<endl;
    cout<<"Y decimos que X tiene el valor: "<<x<<endl;
    cout<<"Decimos que Y sabe que X vive en: "<<y<<endl;
    cout<<"Ahora le pedimos a Y que le pregunte a X su valor: "<<*y<<endl;
    cout<<"Sin embargo, Y vive en esta casa: "<<&y<<endl;
}