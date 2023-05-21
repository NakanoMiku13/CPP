#include<bits/stdc++.h>
using namespace std;
map<string,int> states = {{"MTY",0},{"DUR",1},{"CDMX",2},{"VER",3},{"CAN",4},{"TLAX",5},{"GDL",6}};
template<typename T> class Node{
    public:
        T from, destiny, weight;
        Node(T from, T destiny, T weight): from(from),destiny(destiny),weight(weight){}
};
template<typename T>
auto CreateMatrix(const int n, vector<Node<T>> nodes)->int**{
    int** matrix = (int**)malloc(sizeof(int*)*n);
    for(int i = 0 ; i < n ; i++){
        matrix[i] = (int*)malloc(sizeof(int)*n);
        for(int j = 0 ; j < n ; matrix[i][j] = 0, j++);
    }
    for(int i = 0 ; i < nodes.size() ; matrix[nodes[i].from][nodes[i].destiny] = 1, i++);
    return matrix;
}
auto toUpper(string str)->string{
    string ret = "";
    for(auto i : str) ret += toupper(i);
    return ret;
}
auto main()->int{
    int nodes = states.size(), connections;
    cout<<states["MTY"];
    cout<<"Type the amount of nodes: ";
    cin>>connections;
    vector<Node<int>> nodes_vector;
    for(int i = 0, weight, initial, destiny ; i < connections ; i++){
        cout<<"Type the initial node, the destiny node: ";
        string from, to;
        cin>>from>>to;
        initial = states[toUpper(from)];
        destiny = states[toUpper(to)];
        cout<<"initial: "<<initial<<" to: "<<destiny<<endl;
        nodes_vector.push_back(Node<int>(initial,destiny,weight));
    }
    auto matrix = CreateMatrix(nodes,nodes_vector);
    cout<<"\n\t";
    string sts[10];
    for(auto i : states) sts[i.second] = i.first;
    for(auto i : sts) cout<<i<<"\t";
    cout<<endl;
    for(int i = 0 ; i < nodes ; i++){
        cout<<sts[i]<<"\t";
        for(int j = 0 ; j < nodes ; j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}