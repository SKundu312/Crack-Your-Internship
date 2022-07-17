class Solution {
public:
    void backtrack(vector<int>& nums, int i,vector<int>& row,vector<vector<int>>& ans){
        if(i<=nums.size())
            ans.push_back(row);
        if(i>=(nums.size())) return ;
     
        for(int j=i;j<nums.size();j++){   
            row.push_back(nums[j]);
            backtrack(nums,j+1,row,ans);
            row.pop_back();}
        
        // while(i+1 < nums.size() && nums[i]==nums[i+1]) i++;
        // backtrack(nums,i+1,row,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> row;
        backtrack(nums,0,row,ans);
        return ans;
    }
};
