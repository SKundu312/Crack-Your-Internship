class Solution {
public:
    bool check(int i, string needle, string haystack){
        int j=0;
        while(j<needle.size()){
            if(needle[j++]!=haystack[i++]) return false; 
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        int ans=-1;
        for(int i=0;i<haystack.size();i++){
            if(needle[0]==haystack[i]){
                ans=i;
               if(check(i,needle,haystack)) return ans;
               else ans=-1;
            }
        }
        return ans;
    }
};
