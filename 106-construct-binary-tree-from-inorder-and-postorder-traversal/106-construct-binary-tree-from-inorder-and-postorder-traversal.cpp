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
     TreeNode* ok(vector<int> &in,vector<int> &po,int &idx,int st,int ed,unordered_map<int,int> &mymap){
        if(idx<0 || st>ed){
            return NULL;
        }
        
        int mid=mymap[po[idx]];
        
        TreeNode* root=new TreeNode(po[idx--]);
        
        root->right=ok(in,po,idx,mid+1,ed,mymap);
        
        root->left=ok(in,po,idx,st,mid-1,mymap);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        
        int index=postorder.size()-1;
        
        return ok(inorder,postorder,index,0,inorder.size()-1,m);
    }
};