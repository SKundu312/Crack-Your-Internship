//O(N)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        int powerTwo=1;
        for(int i=1;i<=n;i++){ 
            if(powerTwo*2==i) powerTwo=i;
            ans[i]=1+ans[i-powerTwo];
       }
        return ans;
    }
};
