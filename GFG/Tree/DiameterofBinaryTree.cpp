class Solution
{
    public:
    int diameter(Node* root) {
        if(!root) return 0;
        int ans = 1 + height(root->left) + height(root->right);
        int leftSide = diameter(root->left);
        int rightSide = diameter(root->right);
        return max(ans, max(leftSide, rightSide));
        
    }
    int height(Node* root){
        if(!root) return 0;
        return 1+max(height(root->left), height(root->right));
    }

};
