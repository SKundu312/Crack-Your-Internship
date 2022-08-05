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
    void inorder(TreeNode* root, vector<TreeNode*>& v){
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root,v);
        bool check=false;
        TreeNode *first, *last;
        for(int i=0;i<v.size();i++){
            if((i>0 && (v[i]->val<v[i-1]->val)) || (i<v.size()-1 &&(v[i]->val>v[i+1]->val))){
                if (!check){
                    check = true;
                    first = v[i];
                }
                else{
                    last =v[i]; 
                }
            }
        }
        swap(first->val, last->val);
    }
};
