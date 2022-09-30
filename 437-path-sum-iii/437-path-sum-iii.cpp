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
    void helper(TreeNode* root,int targetSum,int &ans,vector<long> v){
        if(root==NULL){
            return;
        }
        v.push_back(root->val);
        helper(root->left,targetSum,ans,v);
        helper(root->right,targetSum,ans,v);
        int n=v.size();
        long sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=v[i];
            if(sum==targetSum){
                ans++;
            }
        }
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        vector<long> v;
        helper(root,targetSum,ans,v);
        return ans;
    }
};