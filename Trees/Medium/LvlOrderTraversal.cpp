class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
       
       // int i=0;
        vector<int>row;
         row.push_back(root->val);
        ans.push_back(row);
        //ans[i].push_back(root->val);
        while(!q.empty()){
            row.clear();
           int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                if(curr->left)
                    {q.push(curr->left);
                    row.push_back(curr->left->val);}
                 if(curr->right)
                    {q.push(curr->right);
                    row.push_back(curr->right->val);}
                  q.pop();
            }if(row.size())
            ans.push_back(row);
        }
        return ans;
    }
};
