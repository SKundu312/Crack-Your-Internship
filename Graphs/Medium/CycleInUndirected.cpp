class Solution {
  public:
  bool checkCycle(int node, vector<bool>& vis, vector<int> adj[]){
      queue<pair<int,int>> q;
      vis[node]=true;
      q.push({node,-1});
      while(!q.empty()){
          int n=q.front().first;
          int par=q.front().second;
          q.pop();
          for(auto it:adj[n]){
              if(!vis[it]){
                  vis[it]=true;
                  q.push({it,n});
              }
              else if(it!=par)
              return true;
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V+1,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i,vis,adj))
                return true;
            }
        }
        return false;
    }
};
