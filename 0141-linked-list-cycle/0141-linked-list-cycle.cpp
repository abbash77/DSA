/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return false;
        }
        if(head->next==head){
            return true;
        }
        ListNode* s=head;
        ListNode* f=head;
        while(f!=NULL&&s!=NULL){
            s=s->next;
            f=f->next;
            if(f!=NULL){
                f=f->next;
            }
            if(s==f){
                return true;
            }
        }
            return false;
    }
};