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
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL){
            temp=temp->next;
            c++;
        }
        return c;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        if(head->next==NULL){
            return head;
        }
        if(head==NULL){
            return NULL;
        }
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        int mid=length(head)/2;
        int z=length(head)%2;
        ListNode* midEle=head;
        int c=1;
        bool ans=true;
        while(c<mid+z){
            midEle=midEle->next;
            c++;
        }
        midEle->next=reverse(midEle->next);
        ListNode* temp=midEle->next;
        ListNode* temp1=head;
        while(temp1&&temp){
            if(temp1->val!=temp->val){
                ans=false;
            }
            temp1=temp1->next;
            temp=temp->next;
        }
        midEle->next=reverse(midEle->next);
        return ans;
        
        
    }
};