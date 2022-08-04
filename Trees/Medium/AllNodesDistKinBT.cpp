/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(unordered_map<TreeNode*,TreeNode*>& parent_map, TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    parent_map[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    parent_map[curr->right]=curr;
                    q.push(curr->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*> parent_map;
        markParent(parent_map, root);
        
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        queue<TreeNode*> q;
        q.push(target);
        int lvl=0;
        while(!q.empty()){
            int size=q.size();
            if(lvl==k) break;
            lvl++;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent_map[curr] && !vis[parent_map[curr]]){
                    q.push(parent_map[curr]);
                    vis[parent_map[curr]]=true;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            TreeNode* curr=q.front();
            ans.push_back(curr->val);
            q.pop();
        }
        return ans;
        
    }
};
