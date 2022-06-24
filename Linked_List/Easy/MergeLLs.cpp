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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* n = l1;
        
        if(l1->val<=l2->val){
            l1=l1->next;
        }else{
            n=l2;
            l2=l2->next;
        }
        ListNode* ans=n;
        while(l1 && l2){
            if(l1->val<l2->val){
                //ListNode* temp=new ListNode(l1->val);
                n->next=l1;
                l1=l1->next;
            }
            else{
                //ListNode* temp=new ListNode(l2->val);
                n->next=l2;
                l2=l2->next;
            }
            n=n->next;
        }
        if(!l1)
            n->next=l2;
        else
            n->next=l1;
        return ans;
    }
};


//recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
       if(l1 -> val <= l2 -> val){
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		else{
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
    }
};
