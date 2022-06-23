/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//iterative
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        ListNode *s=head;
        ListNode *f=head;
        while(f->next!=NULL && f->next->next!=NULL){
            s=s->next;
            f=f->next->next;
            if(s==f)
                return true;
        }
        return false;
    }
};

//recursive
class Solution {
public:
    bool help(ListNode*s, ListNode* f){
        if(f->next!=NULL && f->next->next!=NULL){
            s=s->next;
            f=f->next->next;
            if(s==f)
                return true;
            return help(s,f);
        }
        return false;
    }
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        ListNode *s=head;
        ListNode *f=head;
        return help(s,f);
    }
};
