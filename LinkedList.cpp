//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//Linked List
#include<bits/stdc++.h>
using namespace std;
//A linked list is a very useful data structure 'cause with this we can create very useful tools or functions like Stack and Queue
//To create a linked list, we need a node, that is the center of our data that the linked list contains.
//In a simple way, we can say that the node is the cell in our array.
struct Node{
    //In this case the Node only manage one type of data, but this can be of any type of data 
    int Value;
    //We need a pointer to the next value, we can say that is a chain, if we lose one of the nodes in the travel, we lose the rest of nodes that where after this.
    Node* Next;
    //The constructor of the Node, to initialize the values as null and take care of garbage values.
    Node(): Value{NULL}, Next{nullptr}{}
};
//The main LinkedList structure
struct LinkedList {
    //To create a successful LinkedList we need a header node that is the head of the "chain", if we lose this node, we lose the rest
    Node* Header;
    //The variables of a struct or a class that have a "_" is declared as a "private variable", is not a real private variable, but is a way to say that is private
    size_t _size;
    //The constructor
    LinkedList(): Header{nullptr}, _size{0}{}
    //This function let us know if the LinkedList is empty or not
    auto IsEmpty()->bool{
        if(Header==nullptr || _size==0) return true;
        return false;
    }
    //This is a function that add a new value to the linked list
    auto Add(int x)->void{
        //We have to create a temporary node that will save the value for us
        //Here, we instantiate the tmp node to save the memory
        Node* tmp = new Node();
        tmp->Value=x;
        //Checking if the LinkedList is empty, if is empty, the tmp value is set as the head
        if(IsEmpty()) Header=tmp;
        //Else we move the Head, to the next position, and the new value is set as the new head
        //I'm making this to make more efficient the linkedlist
        //If you add the new value at the end, you have to check every position in the list, and this could be very long
        //And with this we just make 2 movements, and we do not have to travel around the linked list to find the position
        else{
            //We need a tmp node called "move", that help us to make the movement that I have told you
            //And save the memory direction of the head on the move node
            Node* move = Header;
            //Here we set the tmp value, that is the new value on the linked list as the new head
            Header=tmp;
            //And the old head is set as the Next of the header
            Header->Next=move;
            //And finally we clear the move node, that is a temporary node
            move=nullptr;
        }
        //Increasing the size count
        _size++;
    }
    //The pop function is used to remove the head value, and move the header next value, as the new head value
    //EG. if we have 5 numbers into the linked list as this: 5 4 3 2 1
    //The head is 5, so we apply the pop function, and the 5 is removed from the linked list, and now we have
    //4 3 2 1, and 4 is the new head
    auto Pop()->void{
        //Checking if the List is empty, if is empty we skip the pop function
        if(IsEmpty()) return;
        //Else, we make the same movement as the add function
        else{
            //But in this case, we delete the tmp node,'cause the tmp node is saving the memory direction of the head
            Node* tmp=Header;
            //And the next Header value is set as the new header
            Header=Header->Next;
            //Is important to use the delete function to clear the memory direction of the variable, in this case tmp node
            delete(tmp);
            //Decreasing the size
            _size--;
        }
    }
    //A simple function to print the header value
    auto PrintHeader()->void{
        cout<<Header->Value<<endl;
    }
    //A function to print the linkedlist
    auto PrintList()->void{
        while(!IsEmpty()){
        PrintHeader();
        Pop();
    }
    }
};
auto main()-> int {
    //Invoking the LinkedList structure
    LinkedList List;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        //Adding values to the linked list
        List.Add(x);
    }
    //Printing the list
    //The unique "detail" is that the values will be printed from the back to the Front
    //Eg. if we add the values as this 1 2 3 4 5, the values will be printed as this: 5 4 3 2 1
    //This is for the way as we add the values
    List.PrintList();
}