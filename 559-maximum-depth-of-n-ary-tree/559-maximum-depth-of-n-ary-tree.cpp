/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void helper(Node* root,int level,int &maxLevel){
        if(root==NULL){
            return;
        }
        if(level>maxLevel){
            maxLevel=level;
        }
        for(int i=0;i<root->children.size();i++){
            helper(root->children[i],level+1,maxLevel);
        }
    }
    int maxDepth(Node* root) {
        if(root==NULL){
            return 0;
        }
        int level=INT_MIN;
        helper(root,1,level);
        return level;
    }
};