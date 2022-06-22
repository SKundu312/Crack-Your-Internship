//O(K)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sm=0;
        for(int i=n-1;i>=n-k;i--){
            sm+=cardPoints[i];
        }
        int i=1,j=n-k,maxa=sm;
        if(k==n)
            return sm;
        while(i<=k){
            sm-=cardPoints[j++];
            sm+=cardPoints[i-1];
            maxa=max(sm,maxa);
            i++;
        }
        return maxa;
    }
};
