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
    void insertAtTail(ListNode * &tail , ListNode *curr){
        tail->next = curr;
        tail = curr;
    }
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(-1);
        ListNode *moreHead = new ListNode(-1);
        ListNode *lessTail = lessHead;
        ListNode *moreTail = moreHead;
        
        ListNode *temp = head;
        
        while(temp != NULL){
            if(temp->val < x){
                insertAtTail(lessTail , temp);
            }
            else
                insertAtTail(moreTail , temp);
            
            temp = temp->next;
        }
        
        if(lessHead->next == NULL){
            head = moreHead->next;
            moreTail->next = NULL;
        }
        else{
            lessTail->next = moreHead->next;
            moreTail->next = NULL;
            head = lessHead->next;
        }
        delete(lessHead);
        delete(moreHead);
        return head;
    }
};