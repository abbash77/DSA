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
    TreeNode* helper(vector<int>& preorder,int min,int max,int& a){
        if(a>=preorder.size()){
            return NULL;
        }
        if(preorder[a]>max||preorder[a]<min){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[a++]);
        root->left=helper(preorder,min,root->val,a);
        root->right=helper(preorder,root->val,max,a);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int a=0;
        return helper(preorder,INT_MIN,INT_MAX,a);
    }
};