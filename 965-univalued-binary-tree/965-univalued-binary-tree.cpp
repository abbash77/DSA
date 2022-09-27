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
class Solution {
public:
    void helper(TreeNode* root,int a,bool& b){
        if(root==NULL){
            return ;
        }
        if(root->val!=a){
            b=false;
        }
        helper(root->left,a,b);
        helper(root->right,a,b);
    }
    bool isUnivalTree(TreeNode* root) {
        int a=root->val;
        bool b=true;
        helper(root,a,b);
        return b;
        
    }
};