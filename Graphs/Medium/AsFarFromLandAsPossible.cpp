class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size()) return true;
        else return false;
    }
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j])
                    q.push({i,j});
            }
        }
        int ans=-1;
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        while(!q.empty()){
            int size=q.size();
            ans++;
            while(size--){
                pair<int,int> ele=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x=ele.first+dx[i];
                    int y=ele.second+dy[i];
                    if(isValid(x,y,grid) && grid[x][y]==0){
                        q.push({x,y});
                        grid[x][y]=1;
                    }
                }
            }
        }
        return ans==0?-1:ans;
    }
};
