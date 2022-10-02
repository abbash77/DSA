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
    int widthOfBinaryTree(TreeNode* root) {
        long long int ans=INT_MIN;
        queue<pair<TreeNode*,int>>q;
        q.push(make_pair(root,0));


        while(!q.empty())
        {
            int size=q.size();

            int start=q.front().second;
            int end=q.back().second;

            if((end-start+1)>ans)
            ans=(end-start+1);

            for(int i=0;i<size;i++)
            {
               TreeNode* temp=q.front().first;
               long long int idx=q.front().second;
               q.pop();

               if(temp->left!=NULL)
               q.push(make_pair(temp->left,2*idx+1));

               if(temp->right!=NULL)
               q.push(make_pair(temp->right,2*idx+2));       	
            }
        }
        return ans;
    }
};