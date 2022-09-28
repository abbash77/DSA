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
    pair<double,int> valueSum(TreeNode* root,int &ans){
        if(root==NULL) return {0,0};
	auto left=valueSum(root->left,ans);
	auto right=valueSum(root->right,ans);
	int sum=(left.first+right.first+root->val);
	int n=(left.second+right.second+1);        
	ans+=((sum/n)==root->val);
	return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        valueSum(root,ans);
        return ans;
    }
};