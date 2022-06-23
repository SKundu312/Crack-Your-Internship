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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        ListNode* h=head;
        ListNode* n=head;
        int len=0;
        while(n){
            ++len;
            n=n->next;
        }
        ListNode* slow=NULL;
        int l=0;
        while(h){
            if(l==(len/2)){
                slow->next=h->next;
                break;
            }
            l++;
            slow=h;
            h=h->next;
        }
        return head;
    }
};
