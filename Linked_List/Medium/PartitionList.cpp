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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode();
        ListNode* small_dum=small;
        ListNode* big=new ListNode();
        ListNode* big_dum=big;
        while(head){
            ListNode* temp=new ListNode(head->val);
            if(head->val<x){
                small->next=temp;
                small=small->next; 
            }
            else{
                big->next=temp;
                big=big->next;
            }
            head=head->next;
        }
        small->next=big_dum->next;
        return small_dum->next;
    }
};
