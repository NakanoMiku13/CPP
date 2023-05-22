//#include<bits/stdc++.h>
#include<iostream>
//#include<pair>
using namespace std;
#define null NULL
#define none null
/*template<typename T1, typename T2> class pair{
	public:
		T1 first;
		T2 second;
		pair(T1 first = (T1)null, T2 second = (T2)null): first(first), second(second){}
};*/
template<typename T> using pointer = T*;
template<typename T> class Node{
    private:
        T _value;
        pointer<Node> _next, _prev;
    public:
        Node(T value = null, pointer<Node> next = nullptr, pointer<Node> prev = nullptr) : _value(value), _next(next), _prev(prev){}
        auto SetValue(T value)->void{
            _value = value;
        }
	/*auto &operator->(){
		return &_value;
	}
	auto operator*(){
		return _value;
	}*/
        auto GetValue()->T{
            return _value;
        }
        auto GetNext()->pointer<Node>{
            return _next;
        }
        auto SetNext(pointer<Node> next)->void{
            _next = next;
        }
        auto GetPrev()->pointer<Node>{
            return _prev;
        }
        auto SetPrev(pointer<Node> prev)->void{
            _prev = prev;
        }
};
template<typename T> class List{
    private:
        pointer<Node<T>> _head, _tail;
        size_t _size;
/*	template<typename dataset> class _iterato>
            private:
                pointer<Node<dataset>> _current;
            public:
                _iterator(pointer<Node<dataset>> >
                auto &operator++(){
                    _current = _current->next;
                    return _current;
                }
                auto operator++(int){
                    auto retVal = *this;
                    ++(*this);
                    return retVal;
                }
                auto &operator--(){
                    _current = _current->prev;
                    return _current;
                }
                auto operator--(int){
                    auto retVal = *this;
                    --(*this);
                    return retVal;
                }
		auto *operator->(){
                    return &_current->value;
                }
                auto &operator*(){
                    return _current->value;
                }
                auto operator==(const auto &self){
                    return _current == self->_cur>
                }
                auto operator!=(const auto &self){
                    return _current != self._curr>
                }
                auto dir(){
                    return &_current->value;
                }
        };*/
    public:
        List(initializer_list<T> values = initializer_list<T>()): _head(nullptr), _tail(nullptr), _size(0){
            for(auto i : values) Add(i);
        }
        auto Empty()->bool{
            return (_size == 0) ? true : false;
        }
        auto Add(T value)->void{
            pointer<Node<T>> newNode = new Node<T>(value);
            if(Empty()){
                _head = _tail = newNode;
            }else{
                auto temp = _tail;
                _tail->SetNext(newNode);
                _tail = newNode;
                _tail->SetPrev(temp);
            }
            _size++;
        }
	//auto &operator->(auto aux){ return &aux; }
        auto AddAt(T value, int index){
            pointer<Node<T>> newNode = new Node<T>(value);
            if(Empty()) Add(value);
            else{
                if(index == 0){
                    auto temp = _head;
                    newNode->SetNext(temp);
                    _head = newNode;
                    _size++;
                }else if(index < _size){
                    auto temp = _head;
                    index--;
                    for(int i = 0 ; i < index ; i++, temp = temp->GetNext());
                    auto aux = temp->GetNext();
                    if(temp->GetValue() == (T)null) aux->SetValue(value);
                    else{
                        newNode->SetNext(aux);
                        temp->SetNext(newNode);
                        cout<<endl<<_size<<endl;
                        _size++;
                    }
                }else{
                    // index = 8; size = 6
                    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null -> 8
                    for(auto i = _size ; i < index ; i++) Add((T)null);
                    Add(value);
                }
            }
        }
	auto ReplaceAt(T value, const int index){
		if(Empty()) return;
		else{
			auto move = _head;
			for(int i = 0 ; i < index ; i++, move = move->GetNext());
			move->SetValue(value);
		}
	}
        auto RemoveLast()->void{
            if(Empty()) return;
            else{
                _size--;
                auto t = _tail;
                _tail = _tail->GetPrev();
                _tail->SetNext(nullptr);
            }
        }
        auto PrintList()->void{
            pointer<Node<T>> temp = _head;
            for(auto i = 0 ; i < _size ; i++, temp = temp->GetNext()) if(temp->GetValue() == (T)null) cout<<-1<<" "; else cout<<temp->GetValue()<<" ";
            cout<<endl;
        }
        auto Find(T value){
            auto temp = _head;
            for(auto i = 0 ; i < _size && temp->GetValue() != value ; i++, temp = temp->GetNext());
            return (temp->GetValue() == value) ? temp : nullptr;
        }
        auto At(const int index){
            if(index < _size){
                auto temp = _head;
                for(auto i = 0 ; i < index ; i++, temp = temp->GetNext());
                return temp->GetValue();
            }
            //return null;
        }
};
template<typename T> class AdjacentList{
    private:
        pointer<pair<T,pointer<List<T>>>> _head, _tail;
        List<List<T>> _connections;
        size_t _size;
    public:
        AdjacentList(): _connections(List<T>()), _head(nullptr), _tail(nullptr), _size(0) {}
        auto Empty()->bool{
            return (_size == 0);
        }
        auto Add(pair<T,T> value){
            if(Empty()){
                pointer<pair<T,pointer<List<T>>>> newNode = new pair<T,pointer<List<T>>>();
                newNode->first = value.first;
                List<T> items = List<T>();
                _connections.AddAt(items,value.second);
            }else{
               // _connections.Find
            }
        }
};
auto main()->int{
    List<int> list = List<int>({1,2,3,4,5,6,7,8});
    list.PrintList();
    list.AddAt(9, 15);
    cout<<endl;
    list.PrintList();
    cout<<endl;
    list.AddAt(1230, 13);
    list.PrintList();
    cout<<list.At(1);
	List<List<int>> vals = List<List<int>>({{1,3,4},{7,8,9,0}});
	auto L = vals.At(0);
cout<<endl;
	L.Add(189);
	L.PrintList();
	vals.ReplaceAt(L,0);
	L = vals.At(0);
	cout<<endl;
	L.PrintList();
}
