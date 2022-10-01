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
    int help(vector<int>& nums,int s,int e){
        int maxi=INT_MIN;
        int maxIndex;
        for(int i=s;i<=e;i++){
            if(nums[i]>maxi){
                maxIndex=i;
                maxi=nums[i];
            }
        }
        return maxIndex;
    }
    TreeNode* helper(vector<int>& nums,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=help(nums,s,e);
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(nums,s,mid-1);
        root->right=helper(nums,mid+1,e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
        
    }
};