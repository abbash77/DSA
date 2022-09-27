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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        queue<pair<TreeNode*,int>> q;
        map<int,int> m;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<TreeNode*,int> p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int level=p.second;
            m[level]=node->val;
            if(node->left){
                q.push(make_pair(node->left,level+1));
            }
            if(node->right){
                q.push(make_pair(node->right,level+1));
            }
        }
        for(auto i:m){
            v.push_back(i.second);
        }
        return v;
    }
};