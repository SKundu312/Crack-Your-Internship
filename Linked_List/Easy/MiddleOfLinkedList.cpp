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
    ListNode* middleNode(ListNode* head) {
        ListNode* n=head;
        int l=0;
        while(n!=NULL){
            l++;
            n=n->next;
        }
        n=head;
        for(int i=0;i<l/2;i++){
                n=n->next;
        }
        return n;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=(f->next)->next;
        }
        return s;
    }
};
