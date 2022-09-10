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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return NULL;
        }
        if(head->next==head){
            return head;
        }
        ListNode* s=head;
        ListNode* f=head;
        int a=0;
        while(f!=NULL&&s!=NULL){
            s=s->next;
            f=f->next;
            if(f!=NULL){
                f=f->next;
            }
            if(s==f){
                a=1;
                break;
            }
        }
        if(a==0){
            return NULL;
        }
        s=head;
        while(s!=f){
            s=s->next;
            f=f->next;
        }
        return s;
    }
};