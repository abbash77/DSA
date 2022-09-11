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
    int lastNode(ListNode* head){
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        return temp->val;
    }
    int length(ListNode* head){
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL){
            temp=temp->next;
            c++;
        }
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        
        int last=lastNode(head);
        ListNode* curr=head;
        if(k>length(head)){
            k=k%length(head);
        }
        for(int i=0;i<k;i++){
            while(curr!=NULL){
                int a=curr->val;
                curr->val=last;
                last=a;
                curr=curr->next;
            }
            curr=head;
            last=lastNode(head);
        }
        return head;
        
    }
};