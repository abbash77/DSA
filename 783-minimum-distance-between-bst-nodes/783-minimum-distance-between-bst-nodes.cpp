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
    void helper(TreeNode* root,int &min,int& prev,int& c){
    if(root==NULL){
        return;
    }
    helper(root->left,min,prev,c);
    c++;
    if(c!=1){
        if(root->val-prev<min){
            min=root->val-prev;
        }
    }
    prev=root->val;
    helper(root->right,min,prev,c);
}
    int minDiffInBST(TreeNode* root) {
        int c=0;
        int min=INT_MAX;
        int prev;
        helper(root,min,prev,c);
        return min;
    }
};