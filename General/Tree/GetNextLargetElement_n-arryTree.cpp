TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x, TreeNode<int> * ans = NULL) {
    if(ans == NULL and root->data > x) ans =root;
    else if(ans != NULL and root->data > x and root->data < ans->data){
        ans = root;
    }
    
    for(int i=0; i<root->children.size(); i++){
        ans = getNextLargerElement(root->children[i], x, ans);
    }
    return ans;
}
