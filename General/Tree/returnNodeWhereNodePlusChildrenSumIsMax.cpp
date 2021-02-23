TreeNode<int>* maxSumNode(TreeNode<int>* root, int *maxValue = NULL, TreeNode<int> * ans=NULL) {
    if(!root) {return ans;}
   
    if(maxValue == NULL and ans==NULL){
        maxValue = new int;
        *maxValue =0;
        for(int i=0; i<root->children.size(); i++){
            *maxValue += root->children[i]->data;
        }
        *maxValue += root->data;
        ans = root;
       
    }
    
    for(int i=0; i<root->children.size(); i++){
        ans = maxSumNode(root->children[i], maxValue, ans);
    }
    
    int tempSum=0;
    for(int i=0; i<root->children.size(); i++){
            tempSum += root->children[i]->data;
        }
        tempSum += root->data;
        if(tempSum > *maxValue) {
            ans = root;
            *maxValue = tempSum;
        }
    
    return ans;
    
}
