/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* head1=new Node(head->val);
        Node* saveHead=head;
        Node* prev=NULL;
        prev=head1;
        head=head->next;
        
        unordered_map<Node*,Node*> m;
        while(head!=NULL){
            Node* temp=new Node(head->val);
            prev->next=temp;
            prev=temp;
            head=head->next;
        }
        // while(head1!=NULL){
        //     cout<<head1->val<<" ";
        //     head1=head1->next;
        // }
         head=saveHead;
        Node* head1New=head1;
        while(head!=NULL){
            m[head]=head1New;
            head=head->next;
            head1New=head1New->next;
            
        }
        head=saveHead;
        head1New=head1;
        while(head!=NULL){
            m[head]->random=m[head->random];
            head=head->next;
        }
        return head1;
    }
};