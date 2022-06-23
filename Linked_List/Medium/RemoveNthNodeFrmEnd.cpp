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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        if(!head->next)
            return NULL;
        ListNode* head1=head;
        int len=0;
        while(head1){
            len++;
            head1=head1->next;
        }
        int x=len-n-1;
        ListNode* slow=NULL;
        head1=head;
       if(x==-1) {
            head = head->next;
            return head;
        }
        else{
            while(x--){
                head=head->next;
            }
        }
        head->next=head->next->next;
        return head1;
            
    }
};
