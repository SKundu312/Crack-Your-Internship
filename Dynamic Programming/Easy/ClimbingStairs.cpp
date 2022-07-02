class Solution {
public:
    int fn(int n, vector<int>& dp){
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        else dp[n]=fn(n-1,dp)+fn(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(46,-1);
        return fn(n,dp);
    }
};
