class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> m(26,0);
        int l=0;
        int res=0,maxF=0;
        for(int r=0;r<s.size();r++){
            m[s[r]-'A']++;
            maxF=max(maxF,m[s[r]-'A']);
            while(((r-l+1)-maxF)>k){
                m[s[l]-'A']--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};
