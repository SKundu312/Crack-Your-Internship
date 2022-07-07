class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        for(int i=0;i<dp.size();i++)
            dp[i][0]=0;
        for(int j=0;j<dp[0].size();j++)
            dp[0][j]=10e5;
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(coins[i-1]>j) dp[i][j]=dp[i-1][j];
                else 
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
        }
        return dp[coins.size()][amount]>1e4?-1:dp[coins.size()][amount];
    }
};
