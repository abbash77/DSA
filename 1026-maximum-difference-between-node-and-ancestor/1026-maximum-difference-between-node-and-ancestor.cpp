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
    void helper(TreeNode* root,int min,int max,int &ans,TreeNode* root1){
        if(root==NULL){
            return;
        }
        if(root->val<min){
            min=root->val;
        }
        if(root->val>max){
            max=root->val;
        }
        if(root!=root1){
            int a=abs(root->val-min);
            int b=abs(root->val-max);
            if(b>a&&b>ans){
                ans=b;
            }
            else if(a>=b&&a>ans){
                ans=a;
            }
        }
        helper(root->left,min,max,ans,root1);
        helper(root->right,min,max,ans,root1);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=-1;;
        helper(root,INT_MAX,INT_MIN,ans,root);
        return ans;
    }
};