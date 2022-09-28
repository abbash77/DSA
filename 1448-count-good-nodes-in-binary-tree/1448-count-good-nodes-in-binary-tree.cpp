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
    void helper(TreeNode* root,int max,int &ans){
        if(root==NULL){
            return;
        }
        if(root->val>=max){
            ans++;
            max=root->val;
        }
        helper(root->left,max,ans);
        helper(root->right,max,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        int max=root->val;
        helper(root,max,ans);
        return ans;
    }
};