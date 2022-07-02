class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int sum=0;
        int i=0,j=s.size()-1;
        while(i<s.size()){
            while(s[i]!=s[j] && i<=j) j--;
            sum=j-i+1;
            int h=i+1,k=s.size()-1;
            while(h<j){
                while(s[h]!=s[k] && k>j) k--;
                sum+=(k-j);
                j=k;
                k=s.size()-1;
                h++;
            }
            i=j+1;
            j=s.size()-1;
            ans.push_back(sum);
            sum=0;
        }
        return ans;
    }
};
