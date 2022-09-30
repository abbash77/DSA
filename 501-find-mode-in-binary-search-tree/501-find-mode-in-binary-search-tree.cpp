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
    void helper(TreeNode* root,int &count,int &maxCount,vector<int> &v,int& prev){
        if(root==NULL){
            return;
        }
        helper(root->left,count,maxCount,v,prev);
        int pre=prev;
        if(prev!=root->val){
            count=0;
            prev=root->val;
        }
        count++;
        if(count>=maxCount){
            if(count>maxCount){
                v.clear();
                v.push_back(root->val);
                maxCount=count;
            }
            else{
                v.push_back(root->val);
            }
        }
        
        helper(root->right,count,maxCount,v,prev);
        
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        int maxCount=INT_MIN;
        int count=0;
        int prev=-37827;
        
        helper(root,count,maxCount,v,prev);
        return v;
    }
};