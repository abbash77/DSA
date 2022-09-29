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
    int succ(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left!=NULL&&root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else if(root->left==NULL&&root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else{
                int mini=succ(root->right);
                root->val=mini;
                root->right=deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else{
            root->right=deleteNode(root->right,key);
            return root;
        }
    }
};