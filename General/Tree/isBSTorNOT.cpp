#include<climits>
bool isBST(BinaryTreeNode<int> *root, int min=INT_MIN, int max=INT_MAX) {
	if(!root) return true;
    if(root->data < min or root->data > max) return false;
    
    bool leftSide = isBST(root->left, min, root->data);
    bool rightSide = isBST(root->right, root->data, max);
    
    return leftSide and rightSide;
    
}
