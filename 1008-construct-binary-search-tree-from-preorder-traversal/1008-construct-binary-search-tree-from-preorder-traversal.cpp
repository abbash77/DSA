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
    TreeNode* create(vector<int>& preorder,int mini,int maxi,int &index){
        if(index>=preorder.size()){
            return NULL;
        }
        if(preorder[index]>=maxi||preorder[index]<=mini){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[index]);
        index++;
        root->left=create(preorder,mini,root->val,index);
        root->right=create(preorder,root->val,maxi,index);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return create(preorder,INT_MIN,INT_MAX,index);
    }
};