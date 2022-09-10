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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left=head, *right=head, *curr=head;
    int i=1;
    
    while(curr!=NULL){
        if(i<k) left=left->next;
        if(i>k) right=right->next;
        curr=curr->next;
        i++;
    }
    swap(left->val,right->val);
    return head;
        
    }
};