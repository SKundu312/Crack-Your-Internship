class Solution {
public:
    bool dfs(int i, int j, string s, string p, vector<vector<int>>& dp){
       if(j==p.length())
            return i==s.length();
        if(dp[i][j]>=0) return dp[i][j];
        bool match=i<s.size() && (s[i]==p[j] || p[j]=='.');
        bool ans=0;
        if((j+1)<p.size() && p[j+1]=='*')
           ans=(dfs(i,j+2,s,p,dp) || (match && dfs(i+1,j,s,p,dp)));
        else if(match)
            ans=dfs(i+1,j+1,s,p,dp);
        dp[i][j]=ans;
        return ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
        return dfs(0,0,s,p,dp);
    }
};
