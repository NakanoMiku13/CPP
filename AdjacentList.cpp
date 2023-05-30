#include<iostream>
using namespace std;
#define null NULL
#define none null
template<typename T> using pointer = T*;
template<typename T> class node{
    private:
        T _value;
        pointer<T> _position;
        pointer<node> _next, _prev;
    public:
        node(T value = (T)null) : _value(value), _next(nullptr), _prev(nullptr), _position(nullptr){}
        auto SetValue(T value) {
            _value = value;
        }
        auto SetPosition(pointer<T> position){
            _position = position;
        }
        auto GetPosition(){
            return _position;
        }
        auto GetValue() {
            return &_value;
        }
        auto SetNext(pointer<node> next)  {
            _next = next;
        }
        auto GetNext() {
            return _next;
        }
        auto SetPrev(pointer<node> prev) {
            _prev = prev;
        }
        auto GetPrev() {
            return _prev;
        }
};
template<typename T> class List{
    private:
        pointer<node<T>> _head, _tail;
        size_t _size;
    public:
        List(initializer_list<T> ls = initializer_list<T>()) : _head(nullptr), _tail(nullptr), _size(0){ for(auto i : ls) Add(i);}
        auto Empty() { return (_size == 0) ? true : false; }
        auto &Front() { return *_head->GetValue(); }
        auto &Tail() { return *_tail->GetValue(); }
        auto Add(T value) {
            pointer<node<T>> newNode = new node<T>(value);
            if(Empty()) _head = _tail = newNode;
            else{
                if(value == (T)null) return;
                newNode->SetPrev(_tail);
                _tail->SetNext(newNode);
                _tail = newNode;
            }
            _size++;
        }
        auto Remove() {
            if(Empty()) return;
            else{
                auto temp = _tail;
                _tail = _tail->GetPrev();
                free(temp);
                _size--;
            }
        }
        auto Size() const { return _size; }
        auto Length() const { return Size();}
        auto Print() {
            if(_head != nullptr and !Empty()){
                pointer<node<T>> move = _head;
                for(int i = 0 ; i < _size ; i++, move = move->GetNext()) cout<<*move->GetValue()<<" ";
            }
        }
};
template<typename T> class AdjacentList{
    private:
        pointer<node<List<T>>> _head, _tail;
        size_t _size;
    public:
        AdjacentList(initializer_list<pair<T,T>> initial = initializer_list<pair<T,T>>()): _head(nullptr), _tail(nullptr), _size(0){ for(auto i : initial) Add(i);}
        auto Empty() const{
            return _size == 0;
        }
        auto Front() const {
            return _head->GetValue();
        }
        auto Back() const {
            return _tail->GetValue();
        }
        auto Size(){
            return _size;
        }
        auto Length(){
            return Size();
        }
        auto Find(T value)->pointer<node<List<T>>>{
            if(Empty()) return nullptr;
            else{
                pointer<node<List<T>>> move = _head;
                while(move != nullptr){
                    List<T> val = *move->GetValue();
                    if(val.Front() == value) return move;
                    move = move->GetNext();
                }
                return nullptr;
            }
        }
        auto Add(pair<T,T> value)->void{
            if(value.first == (T)null) return;
            else{
                if(Empty()){
                    pointer<node<List<T>>> newNode = new node<List<T>>({value.first, value.second});
                    newNode->SetPosition(newNode);
                    _head = _tail = newNode;
                    _size++;
                    Add({value.second,(T)null});
                }
                else{
                    auto temp = Find(value.first);
                    if(temp == nullptr){
                        //cout<<value.first<<endl;
                        pointer<node<List<T>>> newNode = new node<List<T>>({value.first, value.second});
                        newNode->SetPrev(_tail);
                        _tail->SetNext(newNode);
                        _tail = newNode;
                        _size++;
                        Add({value.second,(T)null});
                    }else{
                        temp->GetValue()->Add(value.second);
                    }
                }
            }
        }
        auto Print(){
            auto move = _head;
            while(move != nullptr){
                move->GetValue()->Print();
                cout<<endl;
                move = move->GetNext();
            }
        }
};
auto main()->int{
    AdjacentList<int> list = AdjacentList<int>({{1,2},{3,4},{5,6},{7,8},{1,3},{3,4}});
    list.Add({1,5});
    list.Add({5,4});
    list.Add({5,5});
    list.Add({5,12});
    list.Print();
    return 0;
}