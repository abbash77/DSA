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
    void helper(TreeNode* root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    TreeNode* create(vector<int> ans,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode* root= new TreeNode(ans[mid]);
        root->left=create(ans,s,mid-1);
        root->right=create(ans,mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        int s=0;
        int e=ans.size()-1;
        return create(ans,s,e);
        
    }
};