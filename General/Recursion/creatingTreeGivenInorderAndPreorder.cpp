BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    if(preLength <=0 or inLength <=0) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(*preorder);
    int inIndex;
    for(int i=0; i<inLength; i++){
        if(inorder[i] == root->data) {
            inIndex = i; break;
        }
    }
    
    root->left = buildTree(preorder+1, inIndex, inorder, inIndex);
    root->right = buildTree(preorder+(inIndex+1), preLength-inIndex-1 , inorder+inIndex+1, inLength-inIndex-1);
        
    return root;
}
