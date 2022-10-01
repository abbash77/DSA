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
    void helper(TreeNode* root,int level,int &maxlevel,int &sum){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            if(level>maxlevel){
                maxlevel=level;
                sum=root->val;
            }
            else if(level==maxlevel){
                sum+=root->val;
            }
        }
        helper(root->left,level+1,maxlevel,sum);
        helper(root->right,level+1,maxlevel,sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        int maxlevel=INT_MIN;
        int sum=0;
        helper(root,0,maxlevel,sum);
        return sum;
    }
};