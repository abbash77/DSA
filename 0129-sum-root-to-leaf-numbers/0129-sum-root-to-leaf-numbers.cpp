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
    void helper(TreeNode* root,vector<long>& v,string& str){
        if(root==NULL){
            return;
        }
        str+=to_string(root->val);
        helper(root->left,v,str);
        helper(root->right,v,str);
        if(root->left==NULL&&root->right==NULL){
            int sum=0;
            int place=0;
            for(int i=str.length()-1;i>=0;i--){
                int a=str[i]-'0';
                sum+=a*pow(10,place);
                place++;
            }
            v.push_back(sum);
        }
        str.pop_back();
        
        
    }
    int sumNumbers(TreeNode* root) {
        vector<long> v;
        string str="";
        helper(root,v,str);
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
        }
        return sum;
        
    }
};