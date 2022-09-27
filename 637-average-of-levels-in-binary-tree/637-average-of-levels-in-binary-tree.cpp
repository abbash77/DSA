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
    void helper(TreeNode* root,int level, map<int,vector<int>>& m){
        if(root==NULL){
            return;
        }
        m[level].push_back(root->val);
        helper(root->left,level+1,m);
        helper(root->right,level+1,m);
        
    }
    vector<double> averageOfLevels(TreeNode* root) {
       map<int,vector<int>> m;
        int level=0;
        vector<double> ans;
        helper(root,level,m);
        for(auto i:m){
            double sum=0;
            for(int j=0;j<i.second.size();j++){
                sum+=i.second[j];
            }
            sum=sum/i.second.size();
            ans.push_back(sum);
        }
        return ans;
        
    }
};