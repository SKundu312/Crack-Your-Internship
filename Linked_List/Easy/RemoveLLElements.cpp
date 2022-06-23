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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* slow =  NULL;
        while( head && head->val==val){
            head=head->next;       
        }
        ListNode* head1=head;
        while(head){
            if(head->val==val){
                ListNode* temp;
                temp=head;
                slow->next=temp->next; 
                head=head->next;
                temp->next=NULL;
            }
            else
                {slow=head;
                head=head->next;
            }
            
        }
        return head1;
    }
};
