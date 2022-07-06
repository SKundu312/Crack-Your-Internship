class Solution {
public:
    int help(vector<vector<int>>& dp,int i,int j,int m ,int n){
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j==n-1) return 1;
        dp[i][j]=help(dp,i+1,j,m,n)+help(dp,i,j+1,m,n);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return help(dp,0,0,m,n);
    }
};
