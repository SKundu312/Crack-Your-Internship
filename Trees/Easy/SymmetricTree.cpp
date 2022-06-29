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
//Method1
class Solution {
public:
    bool isSameTree(TreeNode* r1,TreeNode* r2){
        if(r1==NULL && r2==NULL) return true;
        if(r1==NULL || r2==NULL) return r1==r2;
        if(r1->val!=r2->val) return false;
        return isSameTree(r1->left,r2->left) && isSameTree(r1->right,r2->right);
    }
    TreeNode* invertTree(TreeNode* root){
        if(!root) return NULL;
        TreeNode* r=invertTree(root->left);
        TreeNode* l=invertTree(root->right);
        root->left=l;
        root->right=r;
        return root;
    }
    bool isSymmetric(TreeNode* root) {
        root->left=invertTree(root->left);
        return isSameTree(root->left,root->right);
    }
};

//Method2
class Solution {
public:
    bool SymmChild(TreeNode* r1,TreeNode* r2){
        if(r1==NULL || r2==NULL) return r1==r2;
        if(r1->val!=r2->val) return false;
        return  SymmChild(r1->left,r2->right) &&  SymmChild(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return SymmChild(root->left,root->right);
    }
};

