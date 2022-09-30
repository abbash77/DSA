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
    void helper(TreeNode* root,vector<pair<TreeNode*,TreeNode*>> &v,TreeNode*& prev){
        if(root==NULL){
            return;
        }
        helper(root->left,v,prev);
        if(prev&&root->val<prev->val){
            v.push_back({prev,root});
        }
            prev=root;
        helper(root->right,v,prev);
    }
    void recoverTree(TreeNode* root) {
        vector<pair<TreeNode*,TreeNode*>> v;
        TreeNode* prev=NULL;
        helper(root,v,prev);
        if(v.size()==1)
            swap(v[0].first->val,v[0].second->val);
        if(v.size()==2)
            swap(v[0].first->val,v[1].second->val);
        
    }
};