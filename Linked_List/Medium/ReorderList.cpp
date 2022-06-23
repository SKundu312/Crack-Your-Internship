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
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        ListNode* last=head;
        ListNode* prev=NULL;
        if(head ==NULL || head->next==NULL)
            return;
        while(last->next){
            prev=last;
            last=last->next;
        }
        prev->next=NULL;
        last->next=head->next;
        head->next=last;
        reorderList(head->next->next);
    }
};
