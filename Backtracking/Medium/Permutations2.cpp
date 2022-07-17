class Solution {
public:
    void backtrack(vector<int>& nums,map<int,int>& m, vector<int>& row, vector<vector<int>>& ans){
        if(row.size()==nums.size()){
            ans.push_back(row);
            return;
        }
        for(auto &i: m){
            if(i.second>0)
                {i.second--;
                row.push_back(i.first);
                backtrack(nums,m,row,ans);
                row.pop_back();
                i.second++;
                }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        vector<int> row;
        backtrack(nums,m,row,ans);
        return ans;
    }
};
