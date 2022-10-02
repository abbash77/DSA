/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
   TreeNode* helper(ListNode* head){
       if(head==NULL){
           return NULL;
       }
       if(head->next==NULL){
           TreeNode* root=new TreeNode(head->val);
           return root;
       }
       if(head->next->next==NULL){
           TreeNode* r=new TreeNode(head->val);
           TreeNode* a=new TreeNode(head->next->val);
           a->left=r;
           return a;
       }
       ListNode* slow=head;
       ListNode* fast=head;
       ListNode* prev=NULL;
       while(fast!=NULL&&fast->next!=NULL){
           prev=slow;
           slow=slow->next;
           fast=fast->next->next;
       }
       if(prev){
            prev->next=NULL;
       }
      
       TreeNode* root=new TreeNode(slow->val);
       root->left=helper(head);
       root->right=helper(slow->next);
       return root;
   }
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head);
    }
};