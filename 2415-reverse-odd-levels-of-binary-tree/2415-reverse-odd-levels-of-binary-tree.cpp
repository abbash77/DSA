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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level=0;
        map<int,vector<int>> m;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                reverse(m[level].begin(),m[level].end());
                level++;
            }
            else{
                if(level%2==1){
                    m[level].push_back(temp->val);
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        // for(auto i:m){
        //     reverse(i.second.begin(),i.second.end());
        // }
        q.push(root);
        q.push(NULL);
        level=0;
        int val=0;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                level++;
                val=0;
            }
            else{
                if(level%2==1){
                    temp->val=m[level][val++];
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return root;
        
    }
};