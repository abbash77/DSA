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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* root1=new TreeNode(val);
            return root1;
        }
        if(val>root->val){
            TreeNode* root1=new TreeNode(val);
            root1->left=root;
            return root1;
        }
        root->right=insertIntoMaxTree(root->right,val);
        return root;
    }
};