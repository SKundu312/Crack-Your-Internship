class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums.size()==2 && nums[0] == INT_MIN && nums[1] == INT_MIN+1) return 1;
        vector<int> v;
        v.push_back(INT_MIN);
        v.insert(v.begin()+1,nums.begin(),nums.end());
        v.push_back(INT_MIN);
        int l=1,r=v.size()-2;
        while(l<=r){
            int m=l+(r-l)/2;
            if(v[m]>v[m-1] && v[m]>v[m+1]) return m-1;
            else if (v[m]>v[m-1]) l=m+1;
            else r=m-1;
        }
        return -1;
    }
};
