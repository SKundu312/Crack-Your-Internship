class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int node, stack<int>& st, vector<bool>& vis, vector<int> adj[]){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it])
            dfs(it,st,vis,adj);
        }
        st.push(node);
    }
    void revDfs(int node, vector<bool>& vis, vector<int> transpose[]){
        vis[node]=true;
        for(auto it:transpose[node]){
            if(!vis[it])
            revDfs(it,vis,transpose);
        }
    }
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<bool> vis(V+1,false);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i])
            dfs(i,st,vis,adj);
        }
        vector<int> transpose(V+1);
        for(int i=0;i<V;i++){
            vis[i]=false;
            for(auto it: adj[i])
            transpose[it]=i;
        }
        int c=0;
        while(!st.empty()){
            int n=st.top();
            st.pop();
            if(!vis[n]){
                revDfs(n,vis,transpose);
                c++;
            }
        }
        return c;
    }
};
