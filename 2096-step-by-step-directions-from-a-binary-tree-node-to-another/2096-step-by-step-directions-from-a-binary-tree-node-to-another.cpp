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
    TreeNode* lca(TreeNode* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL){
           return NULL;
       }
       if(root->val==n1||root->val==n2){
           return root;
       }
       TreeNode* left=lca(root->left,n1,n2);
       TreeNode* right=lca(root->right,n1,n2);
       if(left!=NULL&&right!=NULL){
           return root;
       }
       else if(left!=NULL&&right==NULL){
           return left;
       }
       else if(left==NULL&&right!=NULL){
           return right;
       }
       else{
           return NULL;
       }
    }
    void forEnd(TreeNode* root,int q,string &temp,string& pass){
         if(!root){
            return ;
        }
        if(root->val==q){
            temp=pass;
        }
        pass+="L";
        forEnd(root->left,q,temp,pass);
        pass.pop_back();
        pass+="R";
        forEnd(root->right,q,temp,pass);
        pass.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* roo=lca(root,startValue,destValue);
        string fin="";
        string fi="";
        string start="";
        string end="";
        forEnd(roo,startValue,fin,start);
        forEnd(roo,destValue,fi,end);
        for(int i=0;i<fin.length();i++){
            fin[i]='U';
        }
        return fin+fi;
    }
};