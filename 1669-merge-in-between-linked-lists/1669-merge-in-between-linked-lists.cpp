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
        ListNode* prev=NULL;
        ListNode* temp1=list1;
        ListNode* temp2=list1;
        
        for(int i=0;i<a;i++){
            prev=temp1;
            temp1=temp1->next;
            
        }
         for(int i=0;i<b;i++){
            temp2=temp2->next; 
        }
        ListNode* temp3=temp2->next;
        temp2->next=NULL;
        
        
        prev->next=NULL;
        
        ListNode* temp11=list2;
        while(temp11->next!=NULL){
            temp11=temp11->next;
        }
        prev->next=list2;
        temp11->next=temp3;
        
        return list1;
        
        
    }
};