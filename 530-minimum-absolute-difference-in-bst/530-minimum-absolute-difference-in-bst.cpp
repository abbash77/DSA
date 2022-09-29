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
    TreeNode* prev=NULL;
    void helper(TreeNode* root,int &ans){
        if(root==NULL){
            return;
        }
        helper(root->left,ans);
        if(prev != NULL){
			ans = min(ans, abs(prev->val - root->val));       
		}
		prev = root;
        
        helper(root->right,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        helper(root,mini);
        return mini;
    }
};