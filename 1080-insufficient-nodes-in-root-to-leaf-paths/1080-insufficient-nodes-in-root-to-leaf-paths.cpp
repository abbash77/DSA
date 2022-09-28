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
    TreeNode* helper(TreeNode* root,int limit){
        if(root==NULL){
            return NULL;
        }
        if(root->left==NULL&&root->right==NULL){
            if(root->val<limit){
                return NULL;
            }
            else{
                return root;
            }
        }
        root->left=helper(root->left,limit-root->val);
        root->right=helper(root->right,limit-root->val);
        if(root->left==NULL&&root->right==NULL){
            return NULL;
        }
        return root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int sum=0;
        return helper(root,limit);
    }
};