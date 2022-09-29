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
    void  helper(TreeNode* root,int &ans,int level,int lev){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL&&level==lev){
            ans++;
            return ;
        }
        helper(root->left,ans,level,lev+1);
        helper(root->right,ans,level,lev+1);
        
    }
    int countNodes(TreeNode* root) {
        int level=0;
        int ans=0;
        TreeNode* temp=root;
        if(root==NULL){
            return 0;
        }
        while(temp->left!=NULL){
            temp=temp->left;
            level++;
        }
        int lev=0;
        helper(root,ans,level,lev);
        int z=pow(2,level)-1+ans;
        return z;
        
    }
};