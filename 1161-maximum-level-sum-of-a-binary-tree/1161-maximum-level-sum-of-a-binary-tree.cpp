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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
        int sum=0;
        int maxSum=INT_MIN;
        int level=1;
        int ans;
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        if(temp==NULL){
            if(sum>maxSum){
                ans=level;
                maxSum=sum;
            }
            if(!q.empty()){
                q.push(NULL);
            }
            sum=0;
            level++;
        }
        else{
            sum+=temp->val;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
        return ans;
    }
};