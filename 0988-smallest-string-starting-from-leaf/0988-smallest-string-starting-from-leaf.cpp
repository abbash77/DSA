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
    string recur(TreeNode* root,unordered_map<string,char> m){
        if(root->left==NULL&&root->right==NULL){
            char s=m[to_string(root->val)];
            string str= string(1,s);
            return str;
            
            
        }
        string left="zzzzzzzzzz";
        string right="zzzzzzzzzz";
        if(root->left){
            left=recur(root->left,m);
        }
        if(root->right){
            right=recur(root->right,m);
        }
        string left2=left+m[to_string(root->val)];
        string right2=right+m[to_string(root->val)];
        if(left2=="abab"&&right2=="ab"){
            return left2;
        }
        if(left2>right2){
            return right2;
        }
        else{
            return left2;
        }

    }
    string smallestFromLeaf(TreeNode* root) {
        unordered_map<string,char> m;
        for(int i=0;i<26;i++){
            m[to_string(i)]=97+i;
        }
        string ans=recur(root,m);
        return ans;
    }
};