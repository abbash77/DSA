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
    void helper(TreeNode* root,long& mini){
        if(root==NULL){
            return ;
        }
        if(root->left&&root->left->val==root->val){
            if(root->right->val<mini&&root->right->val!=root->val){
                mini=root->right->val;
            }
            if(root->right->val==root->val){
                helper(root->left,mini);
                helper(root->right,mini);
            }
            else{
                helper(root->left,mini);
            }
            helper(root->left,mini);
        }
        else if(root->right&&root->right->val==root->val){
            if(root->left->val<mini&&root->left->val!=root->val){
                mini=root->left->val;
            } 
            if(root->left->val==root->val){
                helper(root->left,mini);
                helper(root->right,mini);
            }
            else{
                helper(root->right,mini);
            }
            
        }
       
    }
    int findSecondMinimumValue(TreeNode* root) {
        long mini=LONG_MAX;
        helper(root,mini);
        if(mini==LONG_MAX){
            return -1;
        }
        return mini;
    }
};