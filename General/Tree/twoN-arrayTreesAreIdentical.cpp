bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    bool x;
    for(int i=0; i<root1->children.size() and i<root2->children.size(); i++){
        
    	 x = areIdentical(root1->children[i], root2->children[i]);
         if(x==false) return false;
    }
    
    if(root1->data == root2->data){
        if(root1->children.size() == root2->children.size()){
            return true;
        }
        else return false;
    }
    else return false;
    
    return true;
}
