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
    void helper(TreeNode* root,int x,int y,TreeNode* &parent,int level,int &savedlevel,TreeNode* prev,bool &ans){
        if(root==NULL){
            return;
        }
        if(root->val==x||root->val==y){
            if(!parent){
                parent=prev;
                savedlevel=level;
            }
            else{
                if(prev!=parent&&level==savedlevel){
                    ans=true;
                }
                // else{
                //     ans=false;
                // }
            }
        }
        helper(root->left,x,y,parent,level+1,savedlevel,root,ans);
        helper(root->right,x,y,parent,level+1,savedlevel,root,ans);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        bool ans=false;;
        TreeNode* parent=NULL;
        int savedlevel=-1;
        helper(root,x,y,parent,0,savedlevel,NULL,ans);  
        return ans;
    }
};