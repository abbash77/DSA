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
    int ans = 0;
    void dfs(TreeNode* root , vector<int> temp){
        if(!root){
            return;
        }else{
            temp.push_back(root->val);
            dfs(root->left , temp);
            dfs(root->right , temp);
            if(!root->left && !root->right){
                int curr = 0;int exp = 0;
                for(int i = temp.size() - 1 ; i > -1 ; i--){
                    curr += temp[i]*pow(2 , exp);
                    exp++;
                }
                ans += curr;
            }
            temp.pop_back();
            return;
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> v;
        dfs(root,v);
        return ans;
    }
};