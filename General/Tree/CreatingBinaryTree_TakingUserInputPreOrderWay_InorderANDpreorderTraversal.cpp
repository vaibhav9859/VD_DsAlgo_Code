#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

void printNodes(BinaryTreeNode<int>* root){
    if(!root) return;
    cout<<root->data<<": ";
    if(root->left) cout<<"L"<<root->left->data;
    if(root->right) cout<<"R"<<root->right->data;
    cout<<endl;
    printNodes(root->left);
    printNodes(root->right);
}

void printInorder(BinaryTreeNode<int>* root){
    if(!root) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

BinaryTreeNode<int> * takeInput(){
    cout<< "Put data "<<endl;
    int data;
    cin>>data; if(data ==-1) return NULL;
    BinaryTreeNode<int> * node = new BinaryTreeNode<int>(data);
    node->left = takeInput();
    node->right = takeInput();
    return node;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    printNodes(root);
    cout<<endl;
    printInorder(root);
    
    return 0;
}
