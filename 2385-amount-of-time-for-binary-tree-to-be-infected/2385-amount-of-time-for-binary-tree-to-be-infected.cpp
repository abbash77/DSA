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
    TreeNode* createMapping(TreeNode* root,int start,map<TreeNode*,TreeNode*>& nodeToParent){
        TreeNode* res=NULL;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root]=NULL;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->val==start){
                res=temp;
            }
            if(temp->left){
                nodeToParent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                nodeToParent[temp->right]=temp;
                q.push(temp->right);
            }
        }
        return res;
    }
    int ans(TreeNode* root,map<TreeNode*,TreeNode*> nodeToParent){
        map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root]=true;
        int ans=0;
        while(!q.empty()){
            bool flag=0;
            int n=q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left&&!visited[temp->left]){
                    visited[temp->left]=true;
                    flag=1;
                    q.push(temp->left);
                }
                if(temp->right&&!visited[temp->right]){
                    visited[temp->right]=true;
                    flag=1;
                    q.push(temp->right);
                }
                if(nodeToParent[temp]&&!visited[nodeToParent[temp]]){
                    visited[nodeToParent[temp]]=true;
                    flag=1;
                    q.push(nodeToParent[temp]);
                }
            }
            if(flag==1){
                ans++;
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> nodeToParent;
        TreeNode* target=createMapping(root,start,nodeToParent);
        return ans(target,nodeToParent);
    }
};