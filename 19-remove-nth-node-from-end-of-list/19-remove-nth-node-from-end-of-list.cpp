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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int leni=len(head);
        if(leni==1){
            return NULL;
        }
        int z=leni-n;
        ListNode* prev=NULL;
        ListNode* curr=head;
        int ini=1;
        while(ini<=z){
            prev=curr;
            if(curr!=NULL){
                curr=curr->next;
            }
            ini++;
            
        }
        if(prev==NULL){
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            return head;
        }
        ListNode* c=curr;
        prev->next=curr->next;
        curr->next=NULL;
        delete c;
        return head;
        
    }
};