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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        vector<int> a;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                v.push_back(-111111);
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                v.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]!=-111111){
                a.push_back(v[i]);
            }
            else{
                
                ans.push_back(a);
                a.clear();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};