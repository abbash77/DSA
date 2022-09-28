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
    void helper(TreeNode* cloned, TreeNode* target,TreeNode*& res){
        if(cloned==NULL){
            return ;
        }
        if(cloned->val==target->val){
            res=cloned;
        }
        helper(cloned->left,target,res);
        helper(cloned->right,target,res);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res=NULL;
        helper(cloned,target,res);
        return res;
    }
};