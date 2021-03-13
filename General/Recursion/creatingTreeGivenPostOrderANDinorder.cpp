BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    if(postLength<=0 or inLength<=0) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>( *(postorder+postLength-1) );
    int inIndex;
    for(int i=0; i<inLength; i++){
        if(inorder[i] == root->data){
          inIndex = i; break;
        }
    }
    root->left = buildTree(postorder, inIndex, inorder, inIndex);
    root->right = buildTree(postorder+inIndex, inLength-inIndex-1, inorder+inIndex+1, inLength-inIndex-1);
    
    return root;
}
