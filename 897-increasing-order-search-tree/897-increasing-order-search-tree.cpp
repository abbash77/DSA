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
    
    void helper(TreeNode* root,TreeNode*& head,TreeNode*& prev){
        if(root==NULL){
            return;
        }
        helper(root->left,head,prev);
        if(prev){
            prev->right=root;
            root->left=NULL;
            prev=prev->right;
        }
        else{
            prev=root;
            head=prev;
        }
        helper(root->right,head,prev);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head=NULL;
        TreeNode* prev=NULL;
        helper(root,head,prev);
        return head;
    }
};