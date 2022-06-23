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
    void insert(ListNode** root, int item)
{
    ListNode* temp = new ListNode();
    ListNode* ptr;
    temp->val= item;
    temp->next = NULL;
 
    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
    ListNode* createList(vector<int>& v3){
        ListNode* root=NULL;
        for(int i=0;i<v3.size();i++){
            insert(&root,v3[i]);
        }
        return root;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1,v2,v3;
        while(l1){
            v1.push_back(l1->val);
            l1=l1->next;
        }
        reverse(v1.begin(),v1.end());
        while(l2){
            v2.push_back(l2->val);
            l2=l2->next;
        }
        reverse(v2.begin(),v2.end());
        int carry=0,sum=0;
        int maxa=max(v1.size(),v2.size())-1;
        int mini=min(v1.size(),v2.size())-1;
        int j=0;
        for(int i=0;i<=mini;i++){
            sum=v1[v1.size()-1-i]+v2[v2.size()-1-i] +carry;
            v3.push_back(sum%10);
            carry=sum/10;
        }
        if(v1.size()>v2.size())
        for(int i=(maxa-mini-1);i>=0;i--){
            sum=v1[i]+carry;
            v3.push_back(sum%10);
            carry=sum/10;
         
        }
        else{
             for(int i=(maxa-mini-1);i>=0;i--){
            sum=v2[i]+carry;
            v3.push_back(sum%10);
            carry=sum/10; 
            
        }
        }
        if(carry)
            v3.push_back(carry);
        return createList(v3);
    }
};
