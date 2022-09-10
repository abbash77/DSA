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
    int len(ListNode* head){
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        return c;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int s=1;
        ListNode* a=head;
        ListNode* b=head;
        int leni=len(head);
        int z=leni-k;
        while(s<k){
            s++;
            a=a->next;
        }
        s=1;
        while(s<=z){
            s++;
            b=b->next;
        }
        swap(a->val,b->val);
        return head;
        
        
    }
};