//O(N^2)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++)
                if(nums[i]==nums[j])
                    return nums[i];
        }
    return nums[nums.size()-1];
    }
};

//O(Nlog N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
                return nums[i];
        }
        return nums[nums.size()-1];
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto count = [&](int curr){
            int c=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=curr)
                    c++;
            }
            return c;
        };
        int l=0,h=nums.size()-1;
        int dup=-1;
        while(l<=h){
            int cur=l+(h-l)/2;
            if(count(cur)>cur){
                dup=cur;
                h=cur-1;
            }
            else
                l=cur+1;
        }
        return dup;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++) { //O(N)
            int n=s.size();
            s.insert(nums[i]); //O(log N)
        int m=s.size();
        if(n==m)
            return nums[i];}
        return nums[nums.size()-1];
    }
};

//O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int hash[n-1];
        memset( hash, -1, sizeof(hash) );
        for(int i=0;i<nums.size();i++){
            if(hash[nums[i]-1]>0)
                return nums[i];
            else
                hash[nums[i]-1]=1;
        }
        return nums[nums.size()-1];
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int turtoise1=nums[0];
        int hare=nums[0];
        do{
            turtoise1=nums[turtoise1];
            hare=nums[nums[hare]];
        }while(turtoise1!=hare);
        int turtoise2=nums[0];
        while(turtoise1!=turtoise2){
            turtoise1=nums[turtoise1];
            turtoise2=nums[turtoise2];
        }
        return turtoise2;
    }
};

