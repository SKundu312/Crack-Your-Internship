/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p) return p;
        else if(root==q) return q;
        else if(root->val > min(p->val,q->val) && root->val<max(p->val,q->val)) return root;
        else if(root->val< min(p->val,q->val)) return lowestCommonAncestor(root->right,p,q);
        else return lowestCommonAncestor(root->left,p,q);
    }
};

//iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(root==p) return p;
        else if(root==q) return q;
        else if(root->val > min(p->val,q->val) && root->val<max(p->val,q->val)) return root;
        else if(root->val< min(p->val,q->val)) root=root->right;
        else root=root->left;
        }
        return root;
    }
};
