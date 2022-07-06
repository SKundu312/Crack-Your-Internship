class Solution {
public:
    pair<int,int> count(string s){
        pair<int,int> c;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') c.second++;
            else c.first++;
        }
        return c;
    }
    int help(vector<string>& strs, int m, int n, int i){
        if(i==strs.size() || (m+n)==0) return 0;
        pair<int,int> oneZero=count(strs[i]);
        int consider=0,skip=0;
        if(m>=oneZero.second && n>=oneZero.first)
            consider=1+help(strs,m-oneZero.second,n-oneZero.first,i+1);
        else skip=help(strs,m,n,i+1);
        return max(skip,consider);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        return help(strs,m,n,0);
    }
};

class Solution {
public:
    pair<int,int> count(string s){
        pair<int,int> c;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') c.second++;
            else c.first++;
        }
        return c;
    }
    int help(vector<string>& strs, int m, int n, int i,vector<vector<vector<int>>>& dp){
        if(i==strs.size() || (m+n)==0) return 0;
        if(dp[m][n][i]!=-1) return dp[m][n][i];
        pair<int,int> oneZero=count(strs[i]);
        int consider=0,skip=0;
        if(m>=oneZero.second && n>=oneZero.first)
            consider=1+help(strs,m-oneZero.second,n-oneZero.first,i+1,dp);
        skip=help(strs,m,n,i+1,dp);
        return dp[m][n][i]=max(skip,consider);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        return help(strs,m,n,0,dp);
    }
};
