//O(N^2)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int c=0;
        for(int i=0;i<nums.size();i++){
            int s=0;
            for(int j=i;j<nums.size();j++){
                s+=nums[j];
                if(!(s%k))
                    c++;
            }
        }
        return c;
    }
};

//O(N)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>m;
        int sum=0,rem=0,ans=0;
        m.insert({0,1});
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem=sum%k;
            if(rem<0)
                rem+=k;
            if(m.find(rem)!=m.end())
                ans+=m[rem];
            m[rem]++;
        }
        return ans;
    }
};
