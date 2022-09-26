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
    void pre(TreeNode* root,int len,int& minLen){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            if(len<minLen){
                minLen=len;
            }
            return;
        }
        pre(root->left,len+1,minLen);
        pre(root->right,len+1,minLen);
    }
    int minDepth(TreeNode* root){
        int len=1;
        int minLen=INT_MAX;
        if(root==NULL){
            return 0;
        }
        pre(root,len,minLen);
        
        return minLen;
    }
};