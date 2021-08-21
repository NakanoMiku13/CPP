//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//Cube 2.0
#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
using namespace std;
int Array[5][5][5];
int gmode,gdriver=DETECT;
auto InitGraphMode()->void{
    initgraph(&gdriver,&gmode,"");
}
auto CloseGraph()->void{
    getch();
    closegraph();
}
auto PrintError()->void{
    InitGraphMode();
    setcolor(RED);
    outtextxy(300,300,"Error... try again.");
    CloseGraph();
}
auto PrintFace()->void{
    for(int i=0,top=10,bottom=60;i<5;i++,top+=60,bottom+=60){
        for(int j=0,right=60,left=10;j<5;j++,right+=60,left+=60){
            rectangle(left,top,right,bottom);
        }
    }
}
auto PrintFaceBackFront(int Result,int x)->void{
    InitGraphMode();
    PrintFace();
    char Number[5];
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+x)+i)+(4-k));
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            setcolor(GREEN);
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
auto PrintColFrontBack(int Result,int x,int z)->void{
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    for(int i=0,j=0;i<5;i++,j++){
        *(number+j)=*(*(*(Array+x)+i)+z);
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+x)+i)+k);
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    setcolor(WHITE);
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
auto PrintRowFrontBack(int Result,int x,int y)->void{
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    number=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++){
        *(number+i)=*(*(*(Array+x)+y)+i);
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+x)+i)+(5-k));
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    setcolor(WHITE);
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
auto PrintFaceLeftRight(int Result,int z)->void{
    InitGraphMode();
    PrintFace();
    char Number[5];
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+i)+k)+z);
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
auto PrintRowLeftRight(int Result, int y,int z)->void{
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    number=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++){
        *(number+i)=*(*(*(Array+i)+y)+z);
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+i)+k)+z);
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    setcolor(WHITE);
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
auto PrintColLeftRight(int Result,int x,int z)->void{
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    number=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++){
        *(number+i)=*(*(*(Array+x)+i)+z);
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+x)+i)+k);
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    setcolor(WHITE);
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
auto PrintFaceTopBottom(int Result,int y)->void{
    InitGraphMode();
    PrintFace();
    char Number[5];
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+(4-i)+y)+(5-k)));
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
auto PrintRowTopBottom(int Result,int x,int y)->void{
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    number=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++){
        *(number+i) =*(*(*(Array+x)+y)+(5-i));
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+(4-i)+y)+(5-k)));
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
auto PrintColTopBottom(int Result,int y,int z)->void{
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    number=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++){
        *(number+i) =*(*(*(Array+(4-i))+y)+z);
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+(5-i)+y)+(5-k)));
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
//This function fills all the array with random numbers between 0 and 10k
auto Fill()->void{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                Array[i][j][k]=rand()%100;
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
        //This is equal to Sum+=Array[x][y][5-i]
        Sum+=*(*(*(Array+x)+y)+(5-i));
    }
    return (int)Sum;
}
//This function make the addition in the top and bottom columns of the cube, the same process like the last function.
auto SumTopBottomRow(int y, int z)->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        //Here we just have to travel in the X coordinate of the cube to make the addition of the rows
        Sum+=*(*(*(Array+i)+y)+z);
    }
    return (int)Sum;
}
//Function to add the the left or right columns of the cube
auto SumColLeftRightFrontBack(int x,int z)->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        //You only have to travel in the Y coordinate of the cube to get the result
        Sum+=*(*(*(Array+x)+i)+z);
    }
    return (int)Sum;
}
//Function to add the left or right rows of the cube
auto SumRowLeftRight(int y, int z)->int{
    size_t Sum=0;
    for(int i=0;i<5;i++){
        //You only have to travel in the Z coordinate
        Sum+=*(*(*(Array+i)+y)+z);
    }
    return (int)Sum;
}
//Function that make the addition othe rows from the front or back of the cube
auto SumRowFrontBack(int x,int y)->int{
    size_t Sum = 0;
    for(int i=0;i<5;i++){
        Sum+=*(*(*(Array+x)+y)+i);
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
            Sum+=*(*(*(Array+i)+j)+0);
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
            Sum+=*(*(*(Array+5)+i)+j);
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
            Sum+=*(*(*(Array+0)+i)+(5-j));
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
                Sum+=*(*(*(Array+(5-i))+j)+(5-k));
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
            Sum+=*(*(*(Array+i)+0)+j);
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
            Sum+=*(*(*(Array+i)+5)+j);
        }
    }
    return (int)Sum;
}
//Main menu to attach all the Face Addition to make it more accessible, you only have to give the number of the face
auto SumFaceMenu(int face)->int{
    switch(face){
        case 1:
            return FaceFront();
            break;
        case 2:
            return FaceRight();
            break;
        case 3:
            return FaceLeft();
            break;
        case 4:
            return FaceBack();
            break;
        case 5:
            return FaceTop();
            break;
        case 6:
            return FaceBottom();
            break;
        default:
            PrintError();
            break;
    }
}
//Main menu where you make all the decitions of the program, if you want to add the top face, or just a col or row, here you choose.
auto SumMenu(int face)->void{
    int option,x,y,z;
    switch(face) {
        case 1:
            cout<<"Front Face:\n1) Col Sum\n2) Row sum\n3) Face sum\n"; 
            cin>>option;
            switch(option){
                case 1:
                    cout<<"Type the X col position and Z col position:\n"; 
                    cin>>x>>z; 
                    PrintColFrontBack(SumColLeftRightFrontBack(x,z),x,z); 
                    break;
                case 2:
                    cout<<"Type the X row position and Y row position:\n"; 
                    cin>>x>>y; 
                    PrintRowFrontBack(SumRowFrontBack(x,y),x,y); 
                    break;
                case 3:
                    cout<<"Type the front face number that you want to see:\n"; 
                    cin>>x;
                    PrintFaceBackFront(SumFaceMenu(1),x); 
                    break;
                default: 
                    PrintError(); 
                    break;
            } 
        break;
        case 2:
            cout<<"Right Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"; 
            cin>>option;
            switch(option){
                case 1:
                    cout<<"Type the X col position and Z col position:\n"; 
                    cin>>x>>z; 
                    PrintColLeftRight(SumColLeftRightFrontBack(x,z),x,z); 
                    break;
                case 2:
                    cout<<"Type the Y row position and Z row position:\n"; 
                    cin>>y>>z; 
                    PrintRowLeftRight(SumRowLeftRight(y,z),y,z); 
                    break;
                case 3:
                    cout<<"Type the Right face number that you want to see:\n"; 
                    cin>>z;
                    PrintFaceLeftRight(SumFaceMenu(2),z); 
                    break;
                default: 
                    PrintError(); 
                    break;
            }
        break;
        case 3:
            cout<<"Left Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"; 
            cin>>option;
            switch(option){
                case 1:
                    cout<<"Type the X col position and Z col position:\n"; 
                    cin>>x>>z; 
                    PrintColLeftRight(SumColLeftRightFrontBack(x,z),x,z); 
                    break;
                case 2:
                    cout<<"Type the Y row position and Z row position:\n"; 
                    cin>>y>>z; 
                    PrintRowLeftRight(SumRowLeftRight(y,z),y,z); 
                    break;
                case 3:
                    cout<<"Type the Left face number that you want to see:\n"; 
                    cin>>z;
                    PrintFaceLeftRight(SumFaceMenu(2),z); 
                    break;
                default: 
                    PrintError(); 
                    break;
            }
        break;
        case 4:
            cout<<"Top Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"; 
            cin>>option;
            switch(option){
                case 1:
                    cout<<"Type the X col position and Y col position:\n"; 
                    cin>>x>>y;
                    PrintColTopBottom(SumTopBottomCol(x,y),x,y); 
                    break;
                case 2:
                    cout<<"Type the Y row position and Z row position:\n"; 
                    cin>>y>>z;
                    PrintRowTopBottom(SumTopBottomRow(y,z),y,z); 
                    break;
                case 3:
                    cout<<"Type the Top face number that you want to see:\n"; 
                    cin>>y;
                    PrintFaceTopBottom(SumFaceMenu(4),y); 
                    break;
                default: 
                    PrintError(); 
                    break;
            }
        break;
        case 5:
            cout<<"Bottom Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"; 
            cin>>option;
            switch(option){
                case 1:
                    cout<<"Type the X col position and Y col position:\n"; 
                    cin>>x>>y;
                    PrintColTopBottom(SumTopBottomCol(x,y),x,y); 
                    break;
                case 2:
                    cout<<"Type the Y row position and Z row position:\n"; 
                    cin>>y>>z;
                    PrintRowTopBottom(SumTopBottomRow(y,z),y,z); 
                    break;
                case 3:
                    cout<<"Type the Bottom face number that you want to see:\n"; 
                    cin>>y;
                    PrintFaceTopBottom(SumFaceMenu(4),y); 
                    break;
                default: 
                    PrintError(); 
                    break;
            }
        break;
        case 6:
            cout<<"Back Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"; 
            cin>>option; 
            switch(option){
                case 1:
                    cout<<"Type the X col position and Z col position:\n"; 
                    cin>>x>>z; 
                    PrintColFrontBack(SumColLeftRightFrontBack(x,z),x,z); 
                    break;
                case 2:
                    cout<<"Type the X row position and Y row position:\n"; 
                    cin>>x>>y; 
                    PrintRowFrontBack(SumRowFrontBack(x,y),x,y); 
                    break;
                case 3:
                    cout<<"Type the back face number that you want to see:\n"; 
                    cin>>x;
                    PrintFaceBackFront(SumFaceMenu(1),x); 
                    break;
                default: 
                    PrintError(); 
                    break;
            }
        break;
        default: PrintError(); 
        break;
    }
}
//Single function that invokes the menu and print the result, if the resul is equal to -1 that is an error, you have to choose again.
auto Menu()->void{
    Fill();
    int x,result;
    cout<<"1) Front Face\n2) Right face\n3)Left face\n4)Top face\n5)Bottom face\n6) Back face\n";
    cin>>x;
    SumMenu(x);
}
auto Print()->void{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<endl;
            for(int k=0;k<5;k++){
                cout<<Array[i][j][k]<<" ";
            }
        }
        cout<<endl;
    }
}
//Main Function
auto main()-> int {
    Menu();
}