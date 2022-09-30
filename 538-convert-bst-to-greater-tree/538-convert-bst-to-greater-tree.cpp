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
    int sumi(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int a=sumi(root->left);
        int b=sumi(root->right);
        return a+b+root->val;
    }
    void helper(TreeNode*& root,int& sum){
        if(root==NULL){
            return;
        }
        helper(root->left,sum);
        int temp=sum;
        sum=sum-root->val;
        root->val=temp;
        helper(root->right,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=sumi(root);
        helper(root,sum);
        return root;
    }
};