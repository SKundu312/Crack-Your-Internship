class Solution {
public:
    bool isPossible(vector<int>& nums, int m, int mid){
        int sum=0, x=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                x++;
                sum=nums[i];
            }
        }
        if(x<=m) return true;
        else return false;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum=0,maxa=nums[0];
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxa=max(maxa,nums[i]);
        }
        if(nums.size()==m) return maxa;
        int s=maxa,e=sum,res=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(nums,m,mid)){
                res=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return res;
    }
};
