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
    TreeNode* recur(TreeNode* &root,unordered_map<int,bool> m,vector<TreeNode*> &ans){
        if(root==NULL){
            return NULL;
        }
        root->left=recur(root->left,m,ans);
        root->right=recur(root->right,m,ans);
        if(m[root->val]){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,bool> m;
        vector<TreeNode*> ans;
        for(int i=0;i<to_delete.size();i++){
            m[to_delete[i]]=true;
        }
        
        recur(root,m,ans);
        if(!m[root->val]){
            ans.push_back(root);
        }
        return ans;
    }
};