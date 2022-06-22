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
    int getDecimalValue(ListNode* head) {
        vector<int>v;
        while(head){
            int d=head->val;
            v.push_back(d);
            head=head->next;
        }
        int x=0,i=0;
        while(i<v.size()){
            x=x*2+v[i++];
        }
        return x;
    }
};
