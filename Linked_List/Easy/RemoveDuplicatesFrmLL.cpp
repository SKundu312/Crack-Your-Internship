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

//iterative
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> m;
        if(!(head && head->next))
            return head;
        ListNode* slow = NULL;
        ListNode* head1=head;
        while(head){
            if(m.find(head->val)!=m.end()){
                ListNode* temp= head;
                slow->next=temp->next;
                head=head->next;
                temp->next=NULL;
            }
            else{
                m.insert({head->val,1});
                slow=head;
                head=head->next;
            }
        }
        return head1;
    }
};

//recursive
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
        if(!(head && head->next))
            return head;
        if(head->val == head->next->val){
            ListNode* temp=head->next;
            head->next=head->next->next;
            temp=NULL;
            deleteDuplicates(head);
        }
        else
            deleteDuplicates(head->next);
        return head;
    }
};
