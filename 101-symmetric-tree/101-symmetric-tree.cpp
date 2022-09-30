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
    void abc(TreeNode* root1,TreeNode* root2,bool &ans){
        if(root1==NULL&&root2==NULL){
            return ;
        }
        if(root1!=NULL&&root2==NULL){
            ans =false;
        }
        if(root1==NULL&&root2!=NULL){
            ans= false;
        }
        
        if(root1&&root2&&root1->val==root2->val){
            abc(root1->left,root2->right,ans);
            abc(root1->right,root2->left,ans);
        }
        else if(root1&&root2&&root1->val!=root2->val){
            ans=false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        bool ans=true;
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        if(root->left==NULL&&root->right!=NULL){
            return false;
        }
        else if(root->left!=NULL&&root->right==NULL){
            return false;
        }
        else{
            abc(root->left,root->right,ans);
            return ans;
        }
        
    }
};