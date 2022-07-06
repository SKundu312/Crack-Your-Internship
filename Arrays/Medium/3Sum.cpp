class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i && nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            int sum=0-nums[i];
            while(j<k){
                if(nums[j]+nums[k]==(sum)){
                    vector<int>row;
                    row.push_back(nums[j]);
                    row.push_back(nums[k]);
                    row.push_back(nums[i]);
                    ans.push_back(row);
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]<(sum))
                    j++;
                else
                    k--;
                
            }
        }
        return ans;
    }
};
