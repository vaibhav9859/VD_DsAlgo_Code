BinaryTreeNode<int>* helper(int *input, int startIndex, int endIndex){
    	if(input == NULL or startIndex > endIndex) return NULL;
    	
        int mid = startIndex + (endIndex - startIndex)/2;
        BinaryTreeNode<int>*root = new BinaryTreeNode<int>(input[mid]);
        root->left = helper(input, startIndex, mid-1);
        root->right = helper(input, mid+1, endIndex);

    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	return helper(input, 0, n-1);
}
