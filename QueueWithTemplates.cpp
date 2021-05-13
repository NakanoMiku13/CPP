#include<bits/stdc++.h>
using namespace std;
//Setting this line code you can change the type of  data that is using our Node
//You can set it as string or int, any type of data
//In this case you just need to invoke Node as this: "Node N=new Node<string>();"
//This apply the same with the int or float, etc etc.
template<typename T>
//We can made the same with pointers, down this the implementation. Both methods works fine, just this one is more explicit to declare in what we are working
using pointer = T*;
template<typename T>
struct Node{
	T value;
	pointer<Node> next;
	//This is a constructor
	Node(T value): value{value},next{nullptr}{}
	//This is a constructor
	//Node(){ value=0; next=nullptr; }
};
//To create a Queue you can do it with class or structs
//Working with class on CPP every item is private, with struct every item is public
template<typename T>
class Queue{
	//To make a private variable just add a "_" before the name of the variable "_tmp" is just the name 
	pointer<Node<T>>_front,_back;
	//This type of data is a container used on smart structures as this one, to know the size of the structure 
	//This type of data auto converts depending on the size of himself (int to long long)
	size_t _size;
	//This is the way to how to do a public data in a class
	//This is the class constructor
	public:
		Queue(): _front{nullptr}, _back{nullptr}, _size{0}{}
	//This is how you can make a profesional function on cpp, work as same as a normal one (bool empty(){})
	auto empty()->bool{
		//This is the same as use If(_front==nullptr and _back==nullptr)
		return not _front and not _back;
	}
	auto Push(T value)->void{
		auto n = new Node<T>(value);
		if(empty()){
			_front=_back=n;
		}else{
			_back->next=n;
			_back=n;
		}
		_size++;
	}
	auto Pop()->void{
		if(empty()) return;
		auto n = _front;
		_front=_front->next;
		delete n;
		_size--;
	}
	auto Front() -> T{
		return _front->value;
	}
	auto Back() -> T{
		return _back->value;
	}
	auto Size()->size_t{
		return _size;
	}
};
auto main()-> int {
	Queue<int>q;
	for(int i=0;i<15;i++){
	 	q.Push(i);
	}
	while(!q.empty()){
		cout<<q.Front()<<endl;
		q.Pop();
	}
}
