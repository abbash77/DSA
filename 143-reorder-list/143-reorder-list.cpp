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
    ListNode* dummy(ListNode* head,ListNode* tail){
        if(head==NULL){
            return NULL;
        }
        if(head==tail){
            return head;
        }
        if(head->next==tail){
            return head;
        }
        ListNode* dum=head;
        ListNode* next=head->next;
        while(dum->next->next!=NULL){
            dum=dum->next;
        }
        dum->next=NULL;
        head->next=tail;
        tail->next=dummy(next,dum);
        return head;
    }
    void reorderList(ListNode* head) {
        ListNode* tail=head;
         while(tail->next!=NULL){
            tail=tail->next;
        }
        dummy(head,tail);
        
    }
};