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
        while(temp!=NULL){
            temp=temp->next;
            c++;
        }
        return c;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int quo=length(head)/k;
        int rem=length(head)%k;
        int z;
        ListNode* curr=head;
        vector<ListNode*> ans;
        if(k>=length(head)){
            ListNode* temp=head;
           for(int i=0;i<k;i++){   
               ans.push_back(curr);
               if(curr){
                   temp=curr->next;
                    curr->next=NULL;
                    curr=temp;
               }
               
           } 
        }
        else{
            while(curr!=NULL){
            if(rem!=0){
                z=quo+1;
                rem--;
            }
            else{
                z=quo;   
            }
            ListNode* start=curr;
            ListNode* temp=curr;
            for(int i=0;i<z-1;i++){
                curr=curr->next;
                temp=temp->next;
            }
            temp=temp->next;
            curr->next=NULL;
            ans.push_back(start);
            curr=temp;
            
            }
        }
        
        return ans;
        
        
    }
};