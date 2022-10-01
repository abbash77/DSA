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
   void nextRight(Node* r1, Node* r2){
        r1->next = r2;
        r2->next = NULL;
        
        if(r1->left){
            nextRight(r1->left,r1->right);
            nextRight(r1->right, r2->left);
            nextRight(r2->left, r2->right);
            return;
        }
        else
            return;
    }
    Node* connect(Node* root) {
        if(root){
            nextRight(root, root);
        }
         
        return root;
    }
};