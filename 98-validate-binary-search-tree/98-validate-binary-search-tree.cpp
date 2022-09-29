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
    bool helper(TreeNode* root,long min,long max){
        if(root==NULL){
            return true;
        }
        if(min>=root->val||root->val>=max){
            return false;
        }
        
        bool a=helper(root->left,min,root->val);
        bool b=helper(root->right,root->val,max);
        if(a&&b){
            return true;
        }
        else{
            return false;
        }
        
        
    }
    bool isValidBST(TreeNode* root) {
        bool a=helper(root,LONG_MIN,LONG_MAX);
        return a;
    }
};