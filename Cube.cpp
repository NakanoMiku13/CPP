//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//Cube 1.0
#include<bits/stdc++.h>
using namespace std;
int Array[5][5][5];
//This function fills all the array with random numbers between 0 and 10k
auto Fill()->void{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                Array[i][j][k]=rand()%10000;
            }
        }
    }
}
//This function make the addition in the top and bottom columns of the cube, you have to give the x and y position of the column
//to make the correct addition.
auto SumTopBottomCol(int x,int y)->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        //In this case we only have to travel in the Z coordinate just for add the top or bottom values
        Sum+=Array[x][y][5-i];
    }
    return (int)Sum;
}
//This function make the addition in the top and bottom columns of the cube, the same process like the last function.
auto SumTopBottomRow(int y, int z)->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        //Here we just have to travel in the X coordinate of the cube to make the addition of the rows
        Sum+=Array[i][y][z];
    }
    return (int)Sum;
}
//Function to add the the left or right columns of the cube
auto SumColLeftRight(int x,int z)->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        //You only have to travel in the Y coordinate of the cube to get the result
        Sum+=Array[x][i][z];
    }
    return (int)Sum;
}
//Function to add the left or right rows of the cube
auto SumRowLeftRight(int x, int y)->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        //You only have to travel in the Z coordinate
        Sum+=Array[x][y][i];
    }
    return (int)Sum;
}
//Function that add the Front and Back values, both functions are the same (SumColFrontBack and SumColLeftRight), I just add it to have it clear
auto SumColFrontBack(int x,int z)->int{
    size_t Sum = 0;
    for(int i=0;i<5;i++){
        Sum+=Array[x][i][z];
    }
    cout<<endl;
    return (int)Sum;
}
//Function that make the addition othe rows from the front or back of the cube
auto SumRowFrontBack(int y,int z)->int{
    size_t Sum = 0;
    for(int i=0;i<5;i++){
        Sum+=Array[i][y][z];
    }
    return (int)Sum;
}
//This function make the add of the front face of the cube
auto FaceFront()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //You only have to travel as a simple matrix
            Sum+=Array[i][j][0];
        }
    }
    return (int)Sum;
}
//This function make the add of the Right face of the cube
auto FaceRight()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //You have to set the cursor on the last X position, and then you travel like another matrix
            Sum+=Array[5][i][j];
        }
    }
    return (int)Sum;
}
//Function to add the Left Face values
auto FaceLeft()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //You have to travel from the initial X position to the Z last position
            Sum+=Array[0][i][5-j];
        }
    }
    return (int)Sum;
}
//Function that add the back face values
auto FaceBack()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                //Is the opposite of the front face code
                Sum+=Array[5-i][j][5-k];
            }
        }
    }
    return (int)Sum;
}
//Function that add the top values of the cube
auto FaceTop()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //You only have to travel in the top, you must not have to move in the Y coordinate
            Sum+=Array[i][0][j];
        }
    }
    return (int)Sum;
}
//Function that add the bottom values of the cube
auto FaceBottom()->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //The same as the last function, but in this case, you are in the last position of Y coordinate.
            Sum+=Array[i][5][j];
        }
    }
    return (int)Sum;
}
//Main menu to attach all the Face Addition to make it more accessible, you only have to give the number of the face
auto SumFaceMenu(int face)->int{
    switch(face){
        case 1: return FaceFront(); break;
        case 2: return FaceRight(); break;
        case 3: return FaceLeft(); break;
        case 4: return FaceBack(); break;
        case 5: return FaceTop(); break;
        case 6: return FaceBottom(); break;
        default: return 0; break;
    }
}
//Main menu where you make all the decitions of the program, if you want to add the top face, or just a col or row, here you choose.
auto SumMenu(int face)->int{
    int option,x,y,z;
    switch(face) {
        case 1: cout<<"Front Face:\n1) Col Sum\n2) Row sum\n3) Face sum\n"; cin>>option; 
            switch(option){
                case 1: cout<<"Type the X col position and Z col position:\n"; cin>>x>>z; return SumColFrontBack(x,z); break;
                case 2: cout<<"Type the Y row position and Z row position:\n"; cin>>y>>z; return SumRowFrontBack(y,z); break;
                case 3: return SumFaceMenu(1);
                default: return -1;
            } break;
        case 2: cout<<"Right Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"; cin>>option; 
            switch(option){
                case 1: cout<<"Type the X col position and Z col position:\n"; cin>>x>>z; return SumColLeftRight(x,z); break;
                case 2: cout<<"Type the X row position and Y row position:\n"; cin>>x>>y; return SumRowLeftRight(x,y); break;
                case 3: return SumFaceMenu(2); break;
                default: return -1;
            }
        case 3: cout<<"Left Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"; cin>>option; 
            switch(option){
                case 1: cout<<"Type the X col position and Z col position:\n"; cin>>x>>z; return SumColLeftRight(x,z); break;
                case 2: cout<<"Type the X row position and Y row position:\n"; cin>>x>>y; return SumRowLeftRight(x,y); break;
                case 3: return SumFaceMenu(3); break;
                default: return -1;
            }
        case 4: cout<<"Top Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"; cin>>option; 
            switch(option){
                case 1: cout<<"Type the X col position and Y col position:\n"; cin>>x>>y; return SumTopBottomCol(x,y); break;
                case 2: cout<<"Type the Y row position and Z row position:\n"; cin>>y>>z; return SumTopBottomRow(y,z); break;
                case 3: return SumFaceMenu(4); break;
                default: return -1;
            }
        case 5: cout<<"Bottom Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"; cin>>option; 
            switch(option){
                case 1: cout<<"Type the X col position and Y col position:\n"; cin>>x>>y; return SumTopBottomCol(x,y); break;
                case 2: cout<<"Type the Y row position and Z row position:\n"; cin>>y>>z; return SumTopBottomRow(y,z); break;
                case 3: return SumFaceMenu(5); break;
                default: return -1;
            }
        case 6: cout<<"Back Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"; cin>>option; 
            switch(option){
                case 1: cout<<"Type the X col position and Z col position:\n"; cin>>x>>z; return SumColFrontBack(x,z); break;
                case 2: cout<<"Type the Y row position and Z row position:\n"; cin>>y>>z; return SumRowFrontBack(y,z); break;
                case 3: return SumFaceMenu(6); break;
                default: return -1;
            }
        default: return -1;
    }
}
//Single function that invokes the menu and print the result, if the resul is equal to -1 that is an error, you have to choose again.
auto Menu()->void{
    Fill();
    int x,result;
    cout<<"1) Front Face\n2) Right face\n3)Left face\n4)Top face\n5)Bottom face\n6) Back face\n";
    cin>>x;
    result = SumMenu(x);
    cout<<"The result is: "<<result<<endl;
}
//Main Function
auto main()-> int {
    Menu();
}