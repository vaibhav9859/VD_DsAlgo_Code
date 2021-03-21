Node<int>* createNode(int data){
    Node<int>* newNode = new Node<int>(data);
    return newNode;
}
void inOrder(BinaryTreeNode<int>* root, vector<int> &output){
    if(!root) return;
	inOrder(root->left, output);
    output.push_back(root->data);
    inOrder(root->right, output);
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    if(!root) return NULL;
    vector<int> output;
	inOrder(root, output);
    Node<int> * head = new Node<int>(output[0]);
    Node<int> *temp = head;
    for(int i=1; i<output.size(); i++){
       	temp->next = createNode(output[i]);
        if(temp->next)temp = temp->next;
        
    }
    
    return head;
}
