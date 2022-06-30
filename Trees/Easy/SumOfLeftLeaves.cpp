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
    bool isLeaf(TreeNode* root){
        if(!root) return false;
        if(root->left==NULL && root->right==NULL) return true;
        else return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(isLeaf(root) || !root) 
            return 0;
        if(isLeaf(root->left))
          return root->left->val+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        else
            return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};
