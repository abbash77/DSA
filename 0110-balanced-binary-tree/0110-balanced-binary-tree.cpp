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
    pair<bool,int> balance(TreeNode* root){
        
        if(root==NULL){
            pair<bool,int> p;
            p=make_pair(true,0);
            return p;
        }
       pair<bool,int> left= balance(root->left);
       pair<bool,int> right= balance(root->right);
        pair<bool,int> ans;
        if(left.first==true && right.first==true && abs(left.second-right.second)<2){
            ans=make_pair(true,max(left.second,right.second)+1);
        }
        else{
            ans=make_pair(false,0);
            //we could have written height but it wont even matter
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
      pair<bool,int> c=  balance(root);
        return c.first;
    }
};