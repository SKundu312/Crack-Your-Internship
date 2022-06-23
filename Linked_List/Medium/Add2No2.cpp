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
    
    ListNode* createList(vector<int>& v){
        ListNode* curr=new ListNode(-1);
        ListNode* curr1=curr;
        for(int i=0;i<v.size();i++){
            ListNode* temp = new ListNode(v[i]);
            curr->next=temp;
            curr=curr->next;
        }
        curr->next=NULL;
        return curr1->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1,v2,v3;
        while(l1){
            v1.push_back(l1->val);
            l1=l1->next;
        }
        while(l2){
            v2.push_back(l2->val);
            l2=l2->next;
        }
        int maxa=max(v1.size(),v2.size());
        int mini=min(v1.size(),v2.size());
        int carry=0;
        if(v1.size()>v2.size()){
        for(int i=0;i<v2.size();i++){
            int sum=v1[v1.size()-1-i]+v2[v2.size()-1-i]+carry;
            v3.push_back(sum%10);
            carry=sum/10;
        }
         for(int i=(maxa-mini-1);i>=0;i--){
            int sum=v1[i]+carry;
            v3.push_back(sum%10);
            carry=sum/10;
        }     
        }
        else{
            for(int i=0;i<v1.size();i++){
            int sum=v1[v1.size()-1-i]+v2[v2.size()-1-i]+carry;
            v3.push_back(sum%10);
            carry=sum/10;
        }
             for(int i=(maxa-mini-1);i>=0;i--){
            int sum=v2[i]+carry;
            v3.push_back(sum%10);
            carry=sum/10;
        }
        }
        if(carry)
            v3.push_back(carry);
            reverse(v3.begin(),v3.end());
        return createList(v3);
    }
};
