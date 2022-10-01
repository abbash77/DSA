/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    int level(Node* root){
        int lev=0;
        while(root->left!=NULL){
            root=root->left;
            lev++;
        }
        return lev;
    }
    void helper(Node*& root,map<int,Node*> &m,int level){
        if(root==NULL){
            return;
        }
        helper(root->right,m,level+1);
        root->next=m[level];
        m[level]=root;
        helper(root->left,m,level+1);
    }
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        int lev=level(root);
        map<int,Node*> m;
        for(int i=0;i<=lev;i++){
            m[i]=NULL;
        }
        helper(root,m,0);
        return root;
        
    }
};