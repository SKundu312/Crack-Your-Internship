class Solution {
public:
    int bfs(queue<pair<int,int>>& q, vector<vector<bool>>&vis, int &ans, vector<vector<int>>& grid){
        int dist=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                pair<int,int> ele=q.front();
                q.pop();
                vector<int> dx={-1,0,1,0};
                vector<int> dy={0,1,0,-1};
                for(int k=0;k<4;k++){
                    int x=dx[k]+ele.first;
                    int y=dy[k]+ele.second;
                    if(isValid(x,y,grid) && grid[x][y]==0 && !vis[x][y]){
                        q.push({x,y});
                        vis[x][y]=true;
                    }
                    if(isValid(x,y,grid) && grid[x][y]==1 && !vis[x][y])
                      {  ans=min(dist,ans);
                      }
                }
            }
            ++dist;
        }
        return ans;
    }
    bool isValid(int i, int j, vector<vector<int>>& grid){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size()) return true;
        else return false;
    }
    void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<int>>& grid, queue<pair<int,int>>& q){
        vis[i][j]=true;
        q.push({i,j});
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(isValid(x,y,grid) && grid[x][y]==1 && !vis[x][y]){
                vis[x][y]=true;
                q.push({x,y});
                dfs(x,y,vis,grid,q);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        bool fl=false;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,vis,grid,q);
                    fl=true;
                    break;
                }
            }
            if(fl) break;
        }
        return bfs(q,vis,ans,grid);
    }
};
