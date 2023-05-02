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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int a=height(root->left);
        int b=height(root->right);
        return max(a,b)+1;
    }
    void recur(TreeNode* root,vector<vector<string>>& v,int s,int e,int level){
        if(root==NULL){
            return;
        }
        if(s>e){
            return;
        }
        int mid=(s+e)/2;
        v[level][mid]=to_string(root->val);
        recur(root->left,v,s,mid-1,level+1);
        recur(root->right,v,mid+1,e,level+1);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h=height(root);
        int r=h;
        int c=pow(2,h)-1;
        vector<vector<string>> v( r , vector<string> (c, ""));
        recur(root,v,0,c-1,0);
        return v;
    }
};