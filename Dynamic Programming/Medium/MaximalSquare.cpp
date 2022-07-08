//same as count all square submatrices with all ones
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int maxa=0;
        for(int i=0;i<matrix.size();i++){
            dp[i][0]=matrix[i][0]-'0';
           // c+=dp[i][0];
             maxa=max(dp[i][0],maxa);
        }
        for(int i=1;i<matrix[0].size();i++){
            dp[0][i]=matrix[0][i]-'0';
         //   c+=dp[0][i];
             maxa=max(dp[0][i],maxa);
        }
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(matrix[i][j]-'0')
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                //c+=dp[i][j];
                maxa=max(dp[i][j],maxa);
            }
        }
        return maxa*maxa;
    }
};
