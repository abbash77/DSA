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
    TreeNode* create(vector<int>& preorder, vector<int>& inorder,int small,int big,int &index,unordered_map<int,int> &inorderMap){
        if(index>=preorder.size()||small>big){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[index]);
        int pos=inorderMap[preorder[index]];
        index++;
        root->left=create(preorder,inorder,small,pos-1,index,inorderMap);
        root->right=create(preorder,inorder,pos+1,big,index,inorderMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderMap;
        for(int i=0;i<inorder.size();i++){
            inorderMap[inorder[i]]=i;
        }
        int small=0;
        int big=preorder.size()-1;
        int index=0;
        return create(preorder,inorder,small,big,index,inorderMap);
    }
};