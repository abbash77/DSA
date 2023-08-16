//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* findMid(Node* head){
        Node* s=head;
        Node* f=head->next;
        while(f!=NULL&&f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    Node* merge(Node* head1,Node* head2){
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        Node* head=NULL;
        Node* tail=NULL;
        while(head1!=NULL&&head2!=NULL){
            if(head1->data>head2->data){
                if(head==NULL){
                    head=head2;
                    tail=head;
                    head2=head2->next;
                }
                else{
                    tail->next=head2;
                    tail=head2;
                    head2=head2->next;
                }
            }
            else{
                if(head==NULL){
                    head=head1;
                    tail=head;
                    head1=head1->next;
                }
                else{
                    tail->next=head1;
                    tail=head1;
                    head1=head1->next;
                }
            }
        }
        while(head1!=NULL){
            tail->next=head1;
            tail=head1;
            head1=head1->next;
        }
        while(head2!=NULL){
            tail->next=head2;
            tail=head2;
            head2=head2->next;
        }
        return head;
    }
    Node* recur(Node* head){
        if(head->next==NULL){
            return head;
        }
        Node* left=head;
        Node* mid=findMid(head);
        Node* right=mid->next;
        mid->next=NULL;
        left= recur(left);
        right=recur(right);
        Node* ans=merge(left,right);
        return ans;
    }
    Node* mergeSort(Node* head) {
        // your code here
        return recur(head);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends