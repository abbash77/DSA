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
    void pre(TreeNode* root,int& sum,bool left){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL&&left){
            sum+=root->val;
            return;
        }
        pre(root->left,sum,true);
        pre(root->right,sum,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        bool left=false;
        pre(root,sum,left);
        return sum;
    }
};