class Solution {
public:
    int help(vector<vector<int>>& dp, int i, int j, vector<vector<int>>& grid){
        if(i==0 && j==0) return dp[i][j]=grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=1e9;
        int left=1e9;
        if(i>=1) up=help(dp,i-1,j,grid)+grid[i][j];
        if(j>=1) left=help(dp,i,j-1,grid)+grid[i][j];
        dp[i][j]=min(up,left);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return help(dp,grid.size()-1,grid[0].size()-1,grid);
    }
};
