/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    TreeNode* pt;
    stack<TreeNode*> s;
	
    void pushStack(TreeNode *node){
        while(node!=nullptr){
            s.push(node);
            node=node->left;
        }
    }
	// pushed the left subtree to the stack
public:
    BSTIterator(TreeNode* root) {
        pt=root;
        pushStack(pt);
    }
    
    int next() {
        TreeNode* temp=s.top();
        s.pop();
        pushStack(temp->right);
        return temp->val;
    }
	
    // We pop the top node return its value 
	// then we push its right subtree to stack to continue inorder traversal
	
    bool hasNext() {
        return !s.empty();
    }
	// if stack is empty then we have already traversed out tree
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */