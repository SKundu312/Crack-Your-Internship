//O(N)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i])
                nums[k++]=nums[i];
        }
        for(int i=k;i<nums.size();i++)
            nums[i]=0;
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i])
               swap(nums[k++],nums[i]);
        }
    }
};
