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
    bool isLeaf(TreeNode* r){
        if(!r) return false;
        if(r->left==NULL && r->right==NULL) return true;
        else return false; 
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(targetSum==root->val && isLeaf(root)) return true;
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
};
