class Solution {
public:
    int mySqrt(int x) {
        long l=1,r=x;
        int ans=0;
        while(l<=r){
            long m=l+(r-l)/2;
            if(m*m>(long)x)
                r=m-1;
            else if(m*m==x)
                return m;
            else{
                ans=m;
                l=m+1;
            }
        }
        return ans;
    }
};
