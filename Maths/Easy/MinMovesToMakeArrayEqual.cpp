class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt=0,mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
            mini=min(mini,nums[i]);
        for(int i=0;i<nums.size();i++){
            cnt+=nums[i]-mini;
        }
        return cnt;
    }
};
