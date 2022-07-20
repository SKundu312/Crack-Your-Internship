class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s1,s2;
        int n=arr.size();
        vector<int> nextSmall(n),preSmall(n);
        for(int i=0;i<n;i++){
            preSmall[i]=i;
            nextSmall[i]=n-i-1;
        }
        for(int i=0;i<n;i++){
            while(!s1.empty() && arr[s1.top()]>arr[i]){
                nextSmall[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && arr[s2.top()]>=arr[i]){
                preSmall[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        int ans=0;
        int modu=1e9+7;
        for(int i=0;i<n;i++){
           long long x=((preSmall[i]+1)*(nextSmall[i]+1))%modu;
            x=(arr[i]*x)%modu;
            ans=(ans+x)%modu;
            ans%=modu;
        }
        return ans;
    }
};
