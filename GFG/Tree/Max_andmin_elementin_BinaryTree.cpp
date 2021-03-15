// Returns maximum value in a given Binary Tree
int findMax(struct node* root)
{
    if(!root) return INT_MIN;
    return max ( root->data ,max(findMax(root->left), findMax(root->right) ) );
}

// Returns minimum value in a given Binary Tree
int findMin(struct node* root)
{
    if(!root) return INT_MAX;
    return min(root->data, min(findMin(root->left), findMin(root->right) ) );
}
