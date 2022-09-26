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
    pair<bool,int> pre(TreeNode* root){
        if(root==NULL){
            return make_pair(true,0);
        }
        pair<bool,int> left=pre(root->left);
        pair<bool,int> right=pre(root->right);
        pair<bool,int> ans;
        bool a=left.first;
        bool b=right.first;
        bool c=abs(left.second-right.second)<=1;
        if(a&&b&&c){
            ans.first=true;
            ans.second=max(left.second,right.second)+1;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return pre(root).first;
    }
};