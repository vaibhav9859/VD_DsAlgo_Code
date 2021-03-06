#include <iostream>
#include <vector>
using namespace std;

//Creating a template

template <typename T>
class TreeNode{
public:    
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }
};

TreeNode<int>* takeInput(){
    int x; cout<<"Enter node data"<<endl; cin>>x;
    TreeNode<int> * node= new TreeNode<int>(x);

    int n; cout<<"How many children does "<<x<<" has?"<<endl;
    cin>>n; 
    for(int i=0; i<n; i++){   
        TreeNode<int> * child = takeInput();
        node->children.push_back(child);
    }
    return node;
}

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
    TreeNode<int> * root = takeInput();
    printList(root);
    return 0;
}
