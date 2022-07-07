class Solution {
public:
    #define MOD 1000000007
    long long help(int i,int j,int x,int n,vector<vector<vector<long long>>>& dp){
        if(i<0 || j<0 || i>=4 || j>=3 || (i==3 && j!=1)) return 0;
        if(x==n) return 1;
        if(dp[i][j][x]!=-1) return dp[i][j][x];
        dp[i][j][x]=help(i+2, j+1, x+1,n,dp)%MOD+
        help(i+2, j-1, x+1,n,dp)%MOD+
        help(i-2, j+1, x+1,n,dp)%MOD+
        help(i-2, j-1, x+1,n,dp)%MOD+
        help(i-1, j-2, x+1,n,dp)%MOD+
        help(i-1, j+2, x+1,n,dp)%MOD+
        help(i+1, j-2, x+1,n,dp)%MOD+
        help(i+1, j+2, x+1,n,dp)%MOD;
        return dp[i][j][x]%MOD;
    
    }
    int knightDialer(int n) {
        vector<vector<vector<long long>>> dp(5,vector<vector<long long>>(4,vector<long long>(n+1,-1)));
        int ans=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++)
                ans=(ans+help(i,j,1,n,dp))%MOD;
        }
        return ans;
    }
};
