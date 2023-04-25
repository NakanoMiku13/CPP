

//Buscar árbol multicamino


#include<bits/stdc++.h>
using namespace std;
template<typename T> using pointer = T*;
template<typename T> class TreeNode{
    public:
        T value;
        pointer<T> right, left;
        TreeNode(T value = NULL) : value(value){}
        auto operator<(const TreeNode<T> compare){
            return value < compare.value;
        }
};
template<typename T> class BinaryTree{
    private:
        TreeNode<T> _root;
        size_t _size;
    public:
        BinaryTree(T value = NULL) {
            _size = 0;
            this->_root = TreeNode<T>(value);
        }
        auto GetRootValue() -> T { return _root.value; }
        auto GetRoot()-> TreeNode<T> { return _root; }
        auto GetInOrder(TreeNode<T> root, vector<T> ret) -> vector<T>{
            if(root == nullptr) {return ret;}
            else{
                if(root.right == nullptr && root.left == nullptr) ret.push_back(root.value);
                else{
                    return (root.left != nullptr) ? GetInOrder(root.left, ret) : GetInOrder(root.left, ret);
                }
            }
        }
        auto Add(T value)->void{
            TreeNode<T> newNode = TreeNode<T>(value);
            if(_root == NULL) _root = newNode;
            else{
                if(_root < newNode){
                    TreeNode<T> temp = _root; 
                    newNode.left = temp;
                    _root = newNode;
                }else{
                    auto temp = _root;
                    newNode.right = temp;
                    _root = newNode;
                }
            }
        }
};
auto main()->int{
    BinaryTree<int> tree = BinaryTree<int>();
    tree.Add(1);
    tree.Add(2);
    tree.Add(3);
}