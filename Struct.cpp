//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//struct
#include<bits/stdc++.h>
using namespace std;
//Struct is a very useful data structure that allow us to storage multiple types of data, like int, string, etc in the same "Variables"
//We can say as a very simple way that is a array of multiple data
//You can see that in the struct below we have an id, a name, and another data to make a distinction on the structure
//This can be very useful for multiple works, eg: creating a "Database" of a school
//In the struct we can have functions and this function can work with the variables of the struct and variables outside of the struct.
struct Data{
    int id;
    string Name;
    int Age;
    bool Active;
    //We can see that we have a function that says if the user is active or not, so, this is a very simple function
    //But we can have more and very complex functions like this.
    auto IsActive()->bool{
        if(Active) return true;
        else return false;
    }
    auto SetStatus(int x)->void{
        if(IsActive() || x==1){
            Active=true;
        }else{
            Active=false;
        }
    }
    auto PrintAgeAndName()->void{
        cout<<"The name is: "<<Name<<"\nAnd is "<<Age<<" years old\n";
    }
}TmpData[1000];
//We can make arrays of structures, and is very easy to do it.
//We have two ways. The first and the ones that I prefer
//You have to declare your structure, and at the end you add [] and the size
//EG:
//struct Tmp{
//    ....
//}TmpArray[1000];
//Or you can do it declaring again.
//Tmp ArrayTmp[100];
//In this case I'm going to do both with the struct Data
//And we can work with both arrays, the differences are that both are different arrays but with the same type of data
Data TmpDataArray[1000];
auto main()->int{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        //You can see that we can acces to the data just using a dot after the arrays name
        cin>>TmpData[i].Name>>TmpData[i].Age;
        TmpData[i].id=i;
        TmpData[i].Active=true;
    }
    for(int i=0;i<n;i++){
        //And we can invoke the functions in the same way
        TmpData[i].PrintAgeAndName();
    }
}