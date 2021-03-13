/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

OUTPUT FORMAT:
To print the information of a node with data D, you need to follow the exact format :

           D:L:X,R:Y

Where D is the data of a node present in the binary tree. 
X and Y are the values of the left(L) and right(R) child of the node.
Print -1 if the child doesn't exist.


***********************************************************/

void printLevelWise(BinaryTreeNode<int> *root) {
    
    queue<BinaryTreeNode<int> *> q;
    q.push(root); 
    
    while(!q.empty()){
        cout<<q.front()->data<<":";
        cout<<"L:";
        if(q.front()->left){
            cout<<q.front()->left->data<<",";
            q.push(q.front()->left);
        }
        else cout<<-1<<",";
        
        cout<<"R:";
        if(q.front()->right){
            cout<<q.front()->right->data;
            q.push(q.front()->right);
        }
        else cout<<-1;
        cout<<endl;
        if(!q.empty()) q.pop();
    }
	
}
