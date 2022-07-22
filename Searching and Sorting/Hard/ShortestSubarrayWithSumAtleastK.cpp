class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long,long>> dq;
        long long sum=0;
        long long mini=INT_MAX;
        for(long long i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>=k) mini=min(mini,(i+1)*1LL);
            pair<long long,long long> curr={INT_MIN,INT_MIN};
            while(!dq.empty() && (sum-dq.front().first)>=k){
                curr=dq.front();
                dq.pop_front();
            }
            if(curr.first!=INT_MIN)
                mini=min(mini,(i-curr.second)*1LL);
           
            while(!dq.empty() && dq.back().first>=sum){
                dq.pop_back();
            }
            dq.push_back({sum,i});
        }
        return mini==INT_MAX?-1:mini;
    }
};
