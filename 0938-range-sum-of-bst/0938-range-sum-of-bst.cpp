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
    void helper(TreeNode* root,int &sum,int low,int high){
        if(root==NULL){
            return;
        }
        if(low<=root->val&&root->val<=high){
            sum+=root->val;
        }
        helper(root->left,sum,low,high);
        helper(root->right,sum,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        helper(root,sum,low,high);
        return sum;
    }
};