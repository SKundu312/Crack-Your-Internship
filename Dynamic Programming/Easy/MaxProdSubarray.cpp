class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int minDp[n];
        int maxDp[n];
        minDp[0]=nums[0];
        maxDp[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==0) {
                minDp[i]=1;
                maxDp[i]=1;
            }
            minDp[i]=min(nums[i],min(nums[i]*maxDp[i-1],nums[i]*minDp[i-1]));
            maxDp[i]=max(nums[i],max(nums[i]*maxDp[i-1],nums[i]*minDp[i-1]));
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,maxDp[i]);
        }
        return ans;
    }
};
