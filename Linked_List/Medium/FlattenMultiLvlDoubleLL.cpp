/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* head1 =head;
        while(head){
            if(head->child){
                Node* curr1=head->child;
                Node* curr=curr1;
                while(curr->next){
                    curr=curr->next;
                }
                if(head->next)
               { curr->next=head->next;
                head->next->prev=curr;}
                head->next=curr1;
                curr1->prev=head;
                head->child=NULL;
            }
            head=head->next;
        }
        return head1;
    }
};
