// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    int j=0;
                    ans.push_back(t);
                    while(j<adj[i].size()){
                        
                    }
                }
            }
        }
    }
};
