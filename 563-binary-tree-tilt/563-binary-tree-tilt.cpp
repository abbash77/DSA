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
    int sumi(TreeNode* root,int &sum){
        if(root==NULL){
            return 0;
        }
        int a=sumi(root->left,sum);
        int b=sumi(root->right,sum);
        sum+=abs(a-b);
        return a+b+root->val;
    }
    int findTilt(TreeNode* root) {
        int sum=0;
        int a=sumi(root,sum);
        return sum;
        
    }
};