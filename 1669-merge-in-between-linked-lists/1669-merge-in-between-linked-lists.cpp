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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr=list1;
        ListNode* temp=list1;
        ListNode* temp1=list1;
        ListNode* temp2=list1;
        int c=0;
        while(curr!=NULL){
            if(a==c+1){
                temp=curr;
            }
            if(b==c){
                temp2=curr;
                temp1=curr->next;
            }
            c++;
            curr=curr->next;
        }
        ListNode* curr1=list2;
        while(curr1->next!=NULL){
            curr1=curr1->next;
        }
        temp->next=list2;
        temp2->next=NULL;
        
        
        curr1->next=temp1;
        return list1;
        
    }
};