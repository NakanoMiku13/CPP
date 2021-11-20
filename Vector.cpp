//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//Vector
#include<bits/stdc++.h>
using namespace std;
//A vector is a type of data and is identical to the array, we can say that both are twins
//But in my point of view, both have a very clear difference
//Vector data is a real dynamic array, instead of an array that is not a real dynamic array.
//With this, I want say that both can complete the same work, but, if we want to save memory, a vector could be a best option.
//Eg. If we want to make a dynamic array, we declare the array after the variable that says the size.
//int n;
//cin>>n;
//int Array[n+2];
//This is the common way to make a "dynamic array", why I use ""? Because is not a real dynamic array.
//Because if we want to add more values to the array, we have to make to many process to make it work.
//And a dynamic array, a real one, does not need nothing, just add the value.
//So a Vector can complete this.
//We can add values to the vector, and does not matter the initial size 
//This is the way to declare a vector:
//vector<type of data> name;
//If we want to set a limit in the vector, we can do it:
//vector<type of data> name (size, index);
//vector<int> VectorArray(50,0);
//We are saying that VectorArray have a length of 50 elements and it begins on the index 0.
//For the Vectors, we have too many functions to work, but in this case, we are going to use just 5
//.push_back();
//.pop_back();
//.size();
//.empty();
//.back();
//.push_back(); is used as the name say, to add a value to the array at the end.
//If we have a vector like this (1,2,3) and we use the function .push_back(4), we add the 4 at the end, so now we have (1,2,3,4) 
//.pop_back(); is a function used to delete the last value of the array.
//Using the last example, we use the function .pop_back(); from this (1,2,3,4) we have this (1,2,3)
//.size(); as the name say, this one return the number of elements in the array.
//Using the last example, using the function .size(); the function returns the number 3.
//.empty(); is used to know if the array is empty.
//.back(); is used to know the last element in the array.
vector<int> arre;
auto main()-> int {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        //Here we apply the .push_back Function to add the values to the array.
        arre.push_back(x);
    } 
    cout<<"This is the size of the array: "<<arre.size()<<endl;
    //You can see that we can use it as a normal array, printing the values of the array.
    for(int i=0;i<n;i++) cout<<arre[i]<<" ";
    cout<<endl;
    //But if we want to clear the array and throw the elements, we can do it like this.
    int i=0;
    //Declaring while the array is not empty will repeat the process.
    while(!arre.empty()){
        //Printing the last value of the array.
        cout<<arre.back()<<" ";
        //Deleting th value to clear the array.
        arre.pop_back();
    }
}