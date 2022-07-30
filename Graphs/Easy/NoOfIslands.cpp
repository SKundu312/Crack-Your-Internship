//bfs
class Solution {
public:
    bool isValid(int i,int j, vector<vector<char>>& grid){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size()) return true;
        else
            return false;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                        vis[i][j]=1;
                        ans++;
                        queue<pair<int,int>> q;
                        q.push({i,j});
                        while(!q.empty()){
                            pair<int,int> ele=q.front();
                            q.pop();
                            for(int k=0;k<4;k++){
                                int x=ele.first+dx[k];
                                int y=ele.second+dy[k];
                                if(isValid(x,y,grid) && !vis[x][y] && grid[x][y]=='1'){
                                    q.push({x,y});
                                    vis[x][y]=1;
                                }
                            }
                        }
                    
                }
            }
        }
        return ans;
    }
};
