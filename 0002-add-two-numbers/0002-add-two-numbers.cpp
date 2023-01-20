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
    
  int length(ListNode* lengthchecker){
        int count =0;
        while(lengthchecker!=NULL){
            lengthchecker=lengthchecker->next;
            count++;
        }
        return count;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 =l1;
        ListNode* ptr2 =l2;
        int a=length(l1);
        int b=length(l2);
        if(a>=b){
            int carry=0;
            ListNode* prev=NULL;
            while(ptr1!=NULL && ptr2!=NULL){
                int c=ptr1->val+ptr2->val+carry;
                carry =c/10;
                int sum=c%10;
                ptr1->val=sum;
                prev=ptr1;
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            
            while(ptr1!=NULL){
                
                int c=ptr1->val+carry;
                carry =c/10;
                int sum=c%10;
                ptr1->val=sum;
                prev=ptr1;
                ptr1=ptr1->next;
            }
            if(carry!=0){
                ListNode* abc=new ListNode(carry);
                prev->next=abc;
            }
            return l1;
            
            
        }
        else{
              int carry=0;
            ListNode* prev=NULL;
            while(ptr1!=NULL && ptr2!=NULL){
                int c=ptr1->val+ptr2->val+carry;
                carry =c/10;
                int sum=c%10;
                ptr2->val=sum;
                prev=ptr2;
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            
            while(ptr2!=NULL){
                int c=ptr2->val+carry;
                carry =c/10;
                int sum=c%10;
                ptr2->val=sum;
                prev=ptr2;
                ptr2=ptr2->next;
            }
            if(carry!=0){
                ListNode* abc=new ListNode(carry);
                prev->next=abc;
            }
            return l2;
        }
        
        
           
    }
};