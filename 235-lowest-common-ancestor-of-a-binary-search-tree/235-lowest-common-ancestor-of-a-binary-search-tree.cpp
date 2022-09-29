/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return NULL;
        }
       TreeNode* left=NULL;
        TreeNode* right=NULL;
        if(root->val>p->val&&root->val>q->val){
            left=helper(root->left,p,q);
        }
         if(root->val<p->val&&root->val<q->val){
            right=helper(root->right,p,q);
        }
        
        if(left&&!right){
            return left;
        }
        if(!left&&right){
            return right;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};