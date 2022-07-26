class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1=INT_MAX,min2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min1){
                min2=min1;
                min1=nums[i];}
            else if(nums[i]<min2)
                min2=nums[i];
        }
        int max1=INT_MIN,max2=INT_MIN, max3=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(max1<nums[i]){
                max3=max2;
                max2=max1;
                max1=nums[i];}
            else if(max2<nums[i]){
                max3=max2;
                max2=nums[i];}
            else if(max3<nums[i])
                max3=nums[i];
        }
        return max(min1*min2*max1,max1*max2*max3);
    }
};
