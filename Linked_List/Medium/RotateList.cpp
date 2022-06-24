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
//O(N^k)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
            return head;
        ListNode* h=head;
        
        while(h->next->next){
            h=h->next;
        }
        ListNode* temp = new ListNode(h->next->val);
        h->next=NULL;
        temp->next=head;
        return rotateRight(temp,k-1);
    }
};
