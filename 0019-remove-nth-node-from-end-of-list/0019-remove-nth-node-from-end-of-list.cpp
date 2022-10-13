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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count =0;
        ListNode* prev=NULL;
        ListNode* temp=head;
        
        if(head->next==NULL){
            return NULL;
        }
        
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        temp=head;
        int a=count-n+1;
        
        if(a==1){
            
            ListNode *temp2=temp->next;
            temp->next=NULL;
            head=temp2;
            
            return head;
        }
        
        for(int i=0;i<a-1;i++){
           prev=temp;
           temp=temp->next;
            
        }
        ListNode* temp2=temp->next;
        temp->next=NULL;
        prev->next=temp2;
        
        return head;
        
    }
};