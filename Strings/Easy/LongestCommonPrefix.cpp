class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int mini=0;
        for(int i=1;i<strs.size();i++){
            if(strs[i].size()<strs[mini].size()) mini=i;
        }

        for(int j=0;j<strs[mini].size();j++){
            for(int i=0;i<strs.size();i++){
                if(strs[i][j]!=strs[mini][j]) return ans;
            }
            ans+=strs[mini][j];
        }
        return ans;
    }
};
