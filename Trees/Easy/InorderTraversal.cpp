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
//iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode* > st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }  
            root=st.top();
            ans.push_back(root->val);
            st.pop();
            root=root->right;
        }
        return ans;
    }
};

//recursive
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&ans){ 
      if(root==NULL)
            return ;    
      inorder(root->left,ans);
      ans.push_back(root->val);
      inorder(root->right,ans);     
      return;
    } 
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>ans;
       inorder(root,ans);
       return ans;
    }
};
