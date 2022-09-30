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
    void merge(vector<int> v1,vector<int> v2,vector<int> &v){
        int i=0;
        int j=0;
        while(i<v1.size()&&j<v2.size()){
            if(v1[i]>=v2[j]){
                v.push_back(v2[j]);
                j++;
            } 
            else{
                v.push_back(v1[i]);
                i++;
            }
        }
        while(i<v1.size()){
            v.push_back(v1[i]);
            i++;
        }
        while(j<v2.size()){
            v.push_back(v2[j]);
            j++;
        }
    }
    void inorder(TreeNode* root,vector<int> &v){
        if(root==NULL){
            return ;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        inorder(root1,v1);
        inorder(root2,v2);
        vector<int> g;
        merge(v1,v2,g);
        return g;
    }
};