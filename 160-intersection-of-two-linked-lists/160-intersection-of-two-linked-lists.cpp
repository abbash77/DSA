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
    int length(ListNode* head){
        int c=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            c++;
        }
        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=length(headA);
        int b=length(headB);
        if(b>a){
            int z=b-a;
            while(z>0){
                headB=headB->next;
                z--;
            }
        }
        else if(a>b){
            int z=a-b;
            while(z>0){
                headA=headA->next;
                z--;
            }
        }
        while(headA!=NULL||headB!=NULL){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};