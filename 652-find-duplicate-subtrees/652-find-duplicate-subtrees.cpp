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
    unordered_map<string,int> dp ;
    vector<TreeNode*> ans ;
    
    string solve(TreeNode * root){
        if(!root) return "" ;
        
        string left = solve(root->left) ;
        string right = solve(root->right) ;
        
        string code = to_string(root->val)  +" " +left+ " "+ right ;
        if(dp[code] == 1) ans.push_back(root) ;
        dp[code]++ ;
        
        return code ;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string dummy = solve(root) ;
        return ans ;
    }
};