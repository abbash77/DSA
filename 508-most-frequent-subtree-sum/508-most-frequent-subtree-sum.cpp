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
    int helper(TreeNode* root,map<int,int>& m){
        if(root==NULL){
            return 0;
        }
        int left=helper(root->left,m);
        int right=helper(root->right,m);
        int z=left+right+root->val;
        m[z]++;
        return z;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> v;
        map<int,int> m;
        helper(root,m);
        int max=INT_MIN;
        for(auto i:m){
            if(i.second>max){
                max=i.second;
            }
        }
        v.clear();
        for(auto i:m){
            if(i.second==max){
                v.push_back(i.first);
            }
        }
        return v;
        
    }
};