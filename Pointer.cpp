//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//Pointer
//The pointer is a type of data in any programming language and is very useful for multiple works
//In a simple way to explain the way of how do the pointers work is this.
//If we remember a variable in this case "int" is a type of data that is stored in the RAM memory.
//And we can say that the vairable "int" has a name, any name, eg. "X", well.
//Now we have a variable int with the name X, and X is stored in the RAM memory.
//Easy right?
//But X has a direction, that determines where is in the RAM memory, for practical purposes we can say that the direction is 0x1
//In this case we have now, type (int), name (X), and direction (0x1) and any value eg (3).
//And this is the same with any vairable or type of data.
//The pointers work in the same way, but do not storage numbers or characters like char, double, int or string.
//The pointer storage Memory directions.
//In this case we have the variable *n (* is used to determine that the variable is a pointer) 
//So, in this case, we are going to see it like this: type (*int), name (n), direction (0x2) and the value could be for example the direction memory of X in this case (0x1).
//If you can see, "n" variable has two memory directions, but one is the value that the variable is saving, and the other is his own memory direction; basically where is the variable on the RAM memory.
#include<bits/stdc++.h>
using namespace std;
auto main()-> int {
    //We have here, both variables, the int X and the pointer n
    //n vairable could be declared as this: int* n; or int *n;
    //Is important that both variables be declared as int or any type of data, but identical (int with int*, char with char*, etc).
    int x,*n;
    //X have the value of 3
    x=3;
    //If you want to see the memory direction of X, you just have to use & before the variable name.
    //In every execution the memory direction value change, this is because is imposible to use the same memory space, because another application or variable could use it.
    cout<<"This is the memory direction of X: "<<&x<<endl;
    //And we can see the value of the variable x
    cout<<"This is the value of the variable X: "<<x<<endl;
    //Now we can use the pointer to attach the variable X to the pointer n, doing this.
    n=&x;
    //Or we can do this: *n=x;
    //Both ways are the same, the differences are that the second is declaring that we are aiming to the value, and n save the memory value of that variable.
    //And the first one, we are saying that n will storage the memory direction of X, if you can see, both are the same.
    //I recommend you allways to use this way: n=&x;
    //This is beacause it exist the possibility of just save the value of X and not the memory direction, but both will work any way.
    //Now we can use n to see the value of X.
    cout<<"This is the value of X using the pointer n: "<<*n<<endl;
    //In the case we use the * to say that we want to see the value of the variable that we have stored the memory direction.
    //If we want to see the memory direction of X stored in n, we have to do this.
    cout<<"This is the memory direction of X stored in n: "<<n<<endl;
    //This is beacause if we remember in any variable we have Name (n), type (int*), direction (0x2) and value (X memory direction).
    //So in this case the value of the variable n is the memory direction of X 
    cout<<"This is the memory direction of n: "<<&n<<endl;
    //If we can see, is the same process if we want to see the memory direction of n like X.
}