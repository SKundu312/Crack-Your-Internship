//O(n/2)
class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i=1;i<=n/2;i++){
            if(n%i==0) k--;
            if(k==0) return i;
        }
        if(k==1) return n;
        return -1;
    }
};

//Osqrt(n))
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0) 
                ans.push_back(i);
        }
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]!=n/ans[i])
                ans.push_back(n/ans[i]);
        }
        if(k>ans.size()) return -1;
        return ans[k-1];
    }
};
