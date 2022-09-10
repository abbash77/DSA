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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        int a=1;
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->next&&curr->val==curr->next->val){
               
                ListNode* temp=curr->next;
                curr->next=curr->next->next;
                temp->next=NULL;
                delete temp;
                a=0;
            }
            else{
                if(a==0){
                    if(curr==head){
                        ListNode* y=curr;
                        head=head->next;
                        curr->next==NULL;
                        delete y;
                        curr=head;
                        a=1;
                    }
                    else{
                        ListNode* z=curr->next;
                        ListNode* m=curr;
                        prev->next=curr->next;
                        curr->next=NULL;
                        delete m;
                        curr=z;
                        a=1;
                    }
                    
                }
                else{
                    prev=curr;
                    curr=curr->next;
                }
                
                
            }
            
        }
        return head;
    }
};