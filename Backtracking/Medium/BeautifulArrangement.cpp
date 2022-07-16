class Solution {
public:
    void backtrack(int n,int i,vector<bool>& vis,int& ans){
        if(i>n){
            ans++;
            return;}
        for(int j=1;j<=n;j++){ 
            if(!vis[j] && (i%j==0 || j%i==0))
                {vis[j]=true;
                backtrack(n,i+1,vis,ans);
                vis[j]=false;}
        }
    }
    int countArrangement(int n) {
        vector<bool> vis(n+1,false);
        int ans=0;
        backtrack(n,1,vis,ans);
        return ans;
    }
};
