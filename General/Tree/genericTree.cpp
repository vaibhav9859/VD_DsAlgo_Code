#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode{
public:    
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }
};

void printList(TreeNode<int>* root){
    if(!root) return;
    cout<<root->data<<": ";
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        printList(root->children[i]);
    }
}

int main() {
    TreeNode<int> * root = new TreeNode<int>(1);
    TreeNode<int> * child1 = new TreeNode<int>(2);
    TreeNode<int> * child2 = new TreeNode<int>(3);
    root->children.push_back(child1);
    root->children.push_back(child2);
    
    printList(root);
    return 0;
}
