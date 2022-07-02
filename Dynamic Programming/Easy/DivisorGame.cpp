//O(2^n)
class Solution {
public:
    int help(int n){
        if(n==1) return 0;
        else{
            for(int i=1;i<n;i++){
                if(n%i==0){
                    if(help(n-i)==0) return 1;
                }
            }
            return 0;
        }
    }
    bool divisorGame(int n) {
        if(help(n)) return true;
        else return false;
    }
};

//O(n^2)
class Solution {
    int dp[1001];
public:
    int help(int n){
        if(n==1) return 0;
        if(dp[n]!=-1) return dp[n];
        else{
            for(int i=1;i<n;i++){
                if(n%i==0){
                    if(help(n-i)==0) return dp[n]=1;
                }
            }
            return dp[n]=0;
        }
    }
    bool divisorGame(int n) {
        memset(dp,-1,sizeof(dp));
        if(help(n)) return true;
        else return false;
    }
};

//O(n^3/2)
class Solution {
    int dp[1001];
public:
    int help(int n){
        if(n==1) return 0;
        if(dp[n]!=-1) return dp[n];
        else{
            for(int i=1;i*i<=n;i++){
                if(n%i==0){
                    if(help(n-i)==0) return dp[n]=1;
                    if(i!=1 && help(n-(n/i))==0) return dp[n]=1; 
                }
            }
            return dp[n]=0;
        }
    }
    bool divisorGame(int n) {
        memset(dp,-1,sizeof(dp));
        if(help(n)) return true;
        else return false;
    }
};

//O(1)
class Solution {
public:
    bool divisorGame(int n) {
        if(n%2==0) return true;
        else return false;
    }
};
