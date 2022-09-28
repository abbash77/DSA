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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level=0;
        int ev=1;
        int od=1;
        int prevev=INT_MIN;
        int prevod=INT_MAX;
        bool a=true;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                level++;
                prevev=INT_MIN;
                prevod=INT_MAX;
            }
            else{
                if(level%2==0){
                    if(front->val%2==1&&prevev<front->val){
                        prevev=front->val;
                    }
                    else{
                        a=false;
                    }
                }
                else{
                    if(front->val%2==0&&prevod>front->val){
                        prevod=front->val;
                    }
                    else{
                        a=false;
                    }
                }
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        return a;
    }
};