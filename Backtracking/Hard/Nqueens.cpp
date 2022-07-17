class Solution {
public:
    bool isSafe(vector<string>& row,int n, int r, int col){
        for(int i=r-1;i>=0;i--){                 //checking vertically upwards, row changing, col fixed
        if(row[i][col]=='Q') return false;
    }
    
    for(int i=r-1, j=col-1; i>=0 && j>=0; i--,j--){  //upper left diagonally
        if(row[i][j]=='Q') return false;
    }
    
    for(int i=r-1, j=col+1; i>=0 && j<n ; i--,j++){  //upper right diagonally
        if(row[i][j]=='Q') return false;
    }
    
    return true;
    }
    void backtrack(int n, int r, vector<string>& row, vector<vector<string>>& ans){
        if(r==n) {
            ans.push_back(row);
            return;}
        for(int j=0;j<n;j++){
            if(isSafe(row,n,r,j))
           { row[r][j]='Q';
            backtrack(n,r+1,row,ans);
            row[r][j]='.';}
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> row(n,s);
        backtrack(n,0,row,ans);
        return ans;
    }
};
