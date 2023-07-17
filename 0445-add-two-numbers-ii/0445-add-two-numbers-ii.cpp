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
    int length(ListNode* head){
        int c=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            c++;
        }
        return c;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l11=reverse(l1);
        ListNode* l22=reverse(l2);
        int len1=length(l11);
        int len2=length(l22);
        ListNode* head=NULL;
        int carry=0;
        if(len1>len2){
            head=l11;
        }
        else{
            head=l22;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(l11&&l22){
            int a=l11->val;
            int b=l22->val;
            int c=(a+b+carry)%10;
            carry=(a+b+carry)/10;
            curr->val=c;
            prev=curr;
            curr=curr->next;
            l11=l11->next;
            l22=l22->next;
        }
        while(l11){
            int c=(carry+l11->val)%10;
            carry=(carry+l11->val)/10;
            curr->val=c;
            l11=l11->next;
            prev=curr;
            curr=curr->next;
        }
        while(l22){
            int c=(carry+l22->val)%10;
            carry=(carry+l22->val)/10;
            curr->val=c;
            l22=l22->next;
            prev=curr;
            curr=curr->next;
        }
        if(carry!=0){
            ListNode* dummy=new ListNode(carry);
            prev->next=dummy;
        }
        ListNode* ans=reverse(head);
        return ans;
    }
};