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
    TreeNode* create(vector<int>& postorder, vector<int>& inorder,int small,int big,int &index,unordered_map<int,int> &inorderMap){
        if(index<0||small>big){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[index]);
        int pos=inorderMap[postorder[index]];
        index--;
         root->right=create(postorder,inorder,pos+1,big,index,inorderMap);
        root->left=create(postorder,inorder,small,pos-1,index,inorderMap);
       
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderMap;
        for(int i=0;i<inorder.size();i++){
            inorderMap[inorder[i]]=i;
        }
        int small=0;
        int big=postorder.size()-1;
        int index=postorder.size()-1;
        return create(postorder,inorder,small,big,index,inorderMap);
    }
};