#include<bits/stdc++.h>
using namespace std;
struct Time{
    public:
        int minutes,seconds;
        Time(int min,int sec) : minutes(min), seconds(sec){}
        friend ostream& operator<<(ostream&,const Time&);
        auto operator+=(const Time& t)->Time{
            auto min = this->minutes + t.minutes, sec = this->seconds + t.seconds;
            if(sec>60){
                min++;
                sec-=60;
            }
            this->minutes = min;
            this->seconds = sec;
        }
        auto operator-=(const Time& t)->Time{
            auto min = this->minutes - t.minutes, sec = this->seconds - t.seconds;
            this->minutes = min;
            this->seconds = abs(sec);
        }
};
ostream& operator<<(ostream& os,const Time& time){
    os<<time.minutes<<" : "<<time.seconds;
    return os;
}
struct Cancion{
    public:
        string Nombre, Artista;
        Time Duracion;
        Cancion(string nom,string art,Time dur): Nombre(nom), Artista(art), Duracion(dur){}
        friend ostream& operator<<(ostream&,const Cancion&);
};
ostream& operator<<(ostream& os,const Cancion& cancion){
    os<<"Cancion: "<<cancion.Nombre<<"\nArtista: "<<cancion.Artista<<"\nDuracion:\n"<<cancion.Duracion;
    return os;
}
template<typename data> using pointer = data*;
template<typename data> struct node{
    public:
        data value;
        pointer<node> next;
        node(data value): value{value},next{nullptr}{}
};
template<typename data> struct Queue{
    private:
        pointer<node<data>> head,back;
        size_t _size;
        Time _duration;
        bool _pqEmpty;
        template<typename dataset> struct _SubQueue{
            private:
                pointer<node<dataset>> head,back;
                size_t _size;
                Time _duration;
            public:
                _SubQueue(): head{nullptr},back{nullptr},_size{0},_duration{0,0}{}
            auto empty()->bool{
                return (not head and _size==0) ? true : false;
            }
            auto size()->size_t{
                return _size;
            }
            auto push(dataset value){
                auto newNode = new node<dataset>(value);
                if(empty()) head = back = newNode;
                else{
                    back->next = newNode;
                    back = newNode;
                }
                _duration += newNode->value.Duracion;
                _size++;
            }
            auto showContent(){
                auto move = head;
                for( ; move != nullptr ; move = move->next){
                    cout<<move->value<<endl;
                }
            }
            auto pop(){
                if(!empty()){
                    _duration -= head->value.Duracion;
                    if(head == back){
                        delete head;
                        head = back = nullptr;
                    }else{
                        auto tmp = head;
                        head = head->next;
                        delete tmp;
                    }
                    _size--;
                }
            }
            auto printAll(){
                if(_pqEmpty){
                    showContent();
                }
                else{
                    cout<<"Canciones con prioridad: \n";
                    _queue.showContent();
                    cout<<"Canciones restantes: \n";
                    showContent();
                }
            }
            auto Duration()->Time{
                return _duration;
            }
            auto front()->dataset{
                if(!empty()) return head->value;
            }
        };
        _SubQueue<data> _queue;
    public:
        Queue(): head{nullptr},back{nullptr},_size{0},_pqEmpty{true},_duration{0,0}{}
    auto empty()->bool{
        return (not head and _size==0) ? true : false;
    }
    auto size()->size_t{
        return _size;
    }
    auto push(data value){
        auto newNode = new node<data>(value);
        if(empty()) head = back = newNode;
        else{
            back->next = newNode;
            back = newNode;
        }
        _duration += newNode->value.Duracion;
        _size++;
    }
    auto pop(){
        if(!empty()){
            if(_queue.empty()){
                _duration -= head->value.Duracion;
                if(head == back){
                    delete head;
                    head = back = nullptr;
                }else{
                    auto tmp = head;
                    head = head->next;
                    delete tmp;
                }
                _size--;
            }else{
                _duration -= _queue.front().Duracion;
                _queue.pop();
            }
        }
    }
    auto showContent(){
        auto move = head;
        for( ; move != nullptr ; move = move->next){
            cout<<move->value<<endl;
        }
    }
    auto push_PQueue(data newValue){
        _queue.push(newValue);
        _size += _queue.size();
        _duration += newValue.Duracion;
        _pqEmpty = false;
    }
    auto printAll(){
        if(_pqEmpty){
            showContent();
        }else{
            cout<<"Canciones con prioridad: \n";
            _queue.showContent();
            cout<<"Canciones restantes: \n";
            showContent();
        }
    }
    auto Duration()->Time{
        return _duration;
    }
    auto front()->data{
        return (_pqEmpty or _queue.empty()) ? head->value : _queue.front();
    }
};
auto pushCancion(){
    int minutes,seconds;
    string nom,art;
    cout<<"Ingresa Nombre de la cancion, duracion en minutos, duracion en segundos y el nombre del artista:\n";
    cin>>nom>>minutes>>seconds>>art;
    auto dur = new Time(minutes,seconds);
    auto cancion = new Cancion(nom,art,*dur);
    return *cancion;
    system("cls");
}
auto main()->int{
    int n;
    Queue<Cancion> colaSimple;
    cin>>n;
    for(int i=0;i<n;i++){
        colaSimple.push(pushCancion());
    }
    int input;
    system("cls");
    while(!colaSimple.empty()){
        cout<<"1) Ingresar nueva cancion\n2) Agregar cancion como siguiente\n3) Mostrar cancion actual\n4) Cancion siguiente\n5) Duracion de la playlist\n6) Canciones en la playlist\n";
        cin>>input;
        switch(input){
            case 1:
                colaSimple.push(pushCancion());
            break;
            case 2:
                colaSimple.push_PQueue(pushCancion());
            break;
            case 3:
                cout<<"Cancion actual:\n";
                cout<<colaSimple.front()<<endl;
            break;
            case 4:
                cout<<"Pasando de cancion..."<<endl;
                colaSimple.pop();
            break;
            case 5:
                cout<<"Duracion:\n";
                cout<<colaSimple.Duration()<<endl;
            break;
            case 6:
                cout<<"Todas las canciones:\n";
                colaSimple.printAll();
                cout<<endl;
            break;
            default:
            break;
        }
        system("pause");
        system("cls");
    }
}