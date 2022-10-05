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
    class info
{
   public:
   int maxi;
   int mini;
   bool isBST;
   int sum;
};
    info helper(TreeNode* root,int &sumi,int &maxSum){
        if(root == NULL)
            return {INT_MIN, INT_MAX, true, 0};
        info left = helper(root->left,sumi,maxSum);
        info right = helper(root->right,sumi,maxSum);
        info currNode;
        currNode.sum = left.sum + right.sum + root->val;
        currNode.maxi = max(root->val, right.maxi);
        currNode.mini = min(root->val, left.mini);
        if(left.isBST && right.isBST && (root->val> left.maxi && root->val < right.mini))
            currNode.isBST = 1;
        else
            currNode.isBST = 0;
        if(currNode.isBST){
            sumi =currNode.sum;
            maxSum=max(maxSum,sumi);
        }
        else{
            sumi=0;
        }
            
        return currNode;
    }
    int maxSumBST(TreeNode* root) {
        int sumi=0;
        int maxSum=INT_MIN;
        helper(root,sumi,maxSum);
        if(maxSum<0){
            return 0;
        }
        return maxSum;
    }
};