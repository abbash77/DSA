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
    void helper(TreeNode* root,int level,int& maxlevel){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            if(level>maxlevel){
                maxlevel=level;
            }
        }
        helper(root->left,level+1,maxlevel);
        helper(root->right,level+1,maxlevel);
    }
    void helper2(TreeNode* root,int &maxlevel,int level,int& ans){
        if(root==NULL){
            return;
        }
        if(level==maxlevel){
            maxlevel=INT_MIN;
            ans=root->val;
        }
        helper2(root->left,maxlevel,level+1,ans);
        helper2(root->right,maxlevel,level+1,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int level=0;
        int maxlevel=INT_MIN;
        helper(root,level,maxlevel);
        int ans;
        helper2(root,maxlevel,0,ans);
        return ans;
        
    }
};