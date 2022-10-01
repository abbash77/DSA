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
    void helper(TreeNode* root,vector<int> &all,int level,int &maxLevel){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            if(level>maxLevel){
                all.clear();
                all.push_back(root->val);
                maxLevel=level;
            }
            else if(level==maxLevel){
                all.push_back(root->val);
            }
        }
        helper(root->left,all,level+1,maxLevel);
        helper(root->right,all,level+1,maxLevel);
    }
    TreeNode* help(TreeNode* root,vector<int> all){
        if(root==NULL){
            return NULL;
        }
        if(root->left==NULL&&root->right==NULL){
            for(int i=0;i<all.size();i++){
                if(root->val==all[i]){
                    return root;
                }
            }
            return NULL;
        }
        
        TreeNode* left=help(root->left,all);
        TreeNode* right=help(root->right,all);
        if(left!=NULL&&right==NULL){
            return left;
        }
        else if(left==NULL&&right!=NULL){
            return right;
        }
        else if(left!=NULL&&right!=NULL){
            return root;
        }
        else{
            return NULL;
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxLevel=INT_MIN;
        vector<int> all;
        helper(root,all,0,maxLevel);
        return help(root,all);
        
    }
};