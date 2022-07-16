class Solution {
public:
    void backtrack(vector<int>& cts, int i, int target,vector<int>&row, vector<vector<int>>& ans){ 
        if(target==0) 
            ans.push_back(row);
        if(target<=0) return ;
        int prev=-1;
        for(int j=i;j<cts.size();j++){
            if(prev==cts[j])
                continue;
            row.push_back(cts[j]);
            backtrack(cts,j+1,target-cts[j],row,ans);
            row.pop_back();
            prev=cts[j];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cts, int target) {
        vector<vector<int>> ans;
        sort(cts.begin(),cts.end());
        vector<int> row;
        backtrack(cts,0,target,row,ans);
        return ans;
    }
};
