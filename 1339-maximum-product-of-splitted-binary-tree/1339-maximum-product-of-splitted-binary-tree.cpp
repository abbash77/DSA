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
    long long sumi(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        long long left=sumi(root->left);
        long long right=sumi(root->right);
        return left+right+root->val;
    }
    int helper(TreeNode* root,long long sum,long long& maxi){
        if(root==NULL){
            return 0;
        }
        long long left=helper(root->left,sum,maxi);
        long long right=helper(root->right,sum,maxi);
        long long z=left+right+root->val;
        maxi=max(maxi,(sum-z)*z);
        return left+right+root->val;
    }
    int maxProduct(TreeNode* root) {
        const long long mod=1e9+7;
        long long sum=sumi(root);
        long long maxi=INT_MIN;
        helper(root,sum,maxi);
        return maxi%mod;
    }
};