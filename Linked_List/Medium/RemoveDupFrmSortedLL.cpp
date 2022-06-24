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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* n=head;
        ListNode* sentinel = new ListNode(0, head);
        ListNode* prev=sentinel;
        while(n){
            if(n->next!=NULL && n->val==n->next->val){
                while(n->next!=NULL && n->val==n->next->val){
                    n=n->next;
                }
                prev->next=n->next;
            }else
                prev=n;
            n=n->next;
        }
        return sentinel->next;
    }
};
