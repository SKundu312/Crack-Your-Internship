//O(N^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>v;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target)
                { v.push_back(i);
                 v.push_back(j);}   
            }
        }
        return v;
    }
};

//O(N)
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }
        // In case there is no solution, we'll just return null
        return null;
    }
}
