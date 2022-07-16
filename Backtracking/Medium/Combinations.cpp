class Solution {
public:
    void backtrack(int n, int i,int k,vector<int>& row,vector<vector<int>>& ans){
        if(k==0) ans.push_back(row);
        if(k<=0) return;
        for(int j=i;j<=n;j++){
            row.push_back(j);
            backtrack(n,j+1,k-1,row,ans);
            row.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> row;
        backtrack(n,1,k,row,ans);
        return ans;
    }
};
