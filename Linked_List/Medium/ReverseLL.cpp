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
    ListNode* reverse(ListNode* head){
        ListNode* d = NULL;
        ListNode* p;
        while(head){
             p = head->next;
            head->next=d;
            d=head;
            head=p;
        }
        return d;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* first = head;
        ListNode* dummy1;
        dummy1=first;
        int i=1;
        ListNode* sec;
        if(left==1){
         sec=head;
            i--;
        }
        else{
        while(i<(left-1)){
            dummy1=dummy1->next;
            i++;
        }
         sec=dummy1->next;
        dummy1->next=NULL;
        }
        ListNode* dummy2=sec;
        while(i<(right-1)){
            dummy2=dummy2->next;
            i++;
        }
        ListNode* third=dummy2->next;
        dummy2->next=NULL;
        ListNode* sec1=reverse(sec);
        ListNode* ans;
        if(left!=1){
         ans=first;
        while(first->next){
            first=first->next;
        }
        first->next=sec1;}
        else
            ans=sec1;
        while(sec1->next){
            sec1=sec1->next;
        }
        sec1->next=third;
        return ans;
    }
};
