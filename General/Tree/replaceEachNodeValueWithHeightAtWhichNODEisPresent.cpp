void replaceWithDepthValue(TreeNode<int>* root, int depth=0) {
    root->data = depth;
    for(int i=0; i<root->children.size(); i++){
        replaceWithDepthValue(root->children[i], depth+1 );
    }
}
