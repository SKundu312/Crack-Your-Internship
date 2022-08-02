class Solution {
public:
    void dfs(int i, vector<bool>& vis, vector<int> adj[]){
        vis[i]=true;
        for(auto it:adj[i]){
            if(!vis[it])
                dfs(it,vis,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<bool> vis(n,false);
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);}
        }
        return count-1;
    }
};
