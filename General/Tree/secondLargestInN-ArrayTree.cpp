TreeNode<int>* getLargest(TreeNode<int>* root, TreeNode<int>* ans){
    if(ans == NULL) ans = root;
    else if(ans != NULL and root->data > ans->data){
        ans = root;
    }
    for(int i=0; i<root->children.size(); i++){
        ans= getLargest(root->children[i], ans);
    }
    return ans;
}

TreeNode<int>* getSecondLargestHelper(TreeNode<int>* root, int x, TreeNode<int> * ans = NULL) {
    if(ans == NULL and root->data < x) ans =root;
    else if(ans != NULL and root->data < x and root->data > ans->data){
        ans = root;
    }
    
    for(int i=0; i<root->children.size(); i++){
        ans = getSecondLargestHelper(root->children[i], x, ans);
    }
    return ans;
}


TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(!root) return root;
    TreeNode<int> * largest = getLargest(root, NULL);
    return getSecondLargestHelper(root, largest->data);
}
