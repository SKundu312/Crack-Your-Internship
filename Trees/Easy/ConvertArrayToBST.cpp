/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* convert(vector<int>& nums, int s,int e){
        if(s<e){
            int mid=(s+e)/2;
            TreeNode* curr=new TreeNode(nums[mid]);
            TreeNode* l=convert(nums,s,mid);
            TreeNode* r=convert(nums,mid+1,e);
            curr->left=l;
            curr->right=r;
            return curr;
        }
        else
            return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root= convert(nums,0,nums.size());
        return root;
    }
};
