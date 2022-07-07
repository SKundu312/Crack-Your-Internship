class Solution {
public:
    int maxa=1;
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j])
                dp[i]=max(dp[i],1+dp[j]);
            }
            maxa=max(maxa,dp[i]);
        }
        return maxa;
    }
};
