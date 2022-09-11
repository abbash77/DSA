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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;
        int m=1;
        ListNode* a=NULL;
        ListNode* b=NULL;
        ListNode* c=NULL;
        ListNode* d=NULL;
        ListNode* e=NULL;
        int l=0;
        while(curr!=NULL){
            l=0;
            if(m>=left&&m<=right){
                if(m==left){
                    a=curr;
                    c=e;
                }
                if(m==right){
                    d=curr;
                    b=curr->next;
                }
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
                l=1;
            }
            e=curr;
            if(l!=1){
                 curr=curr->next;
            }
            
            m++;
        }
        if(c){
            c->next=d;
        }
        else{
            head=prev;
        }
        if(a){
            a->next=b;
        }
        
        
        return head;
        
    }
};