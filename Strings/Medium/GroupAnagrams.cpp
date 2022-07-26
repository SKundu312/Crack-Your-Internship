//O(m.n.log n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size()==1){
            ans.push_back(strs);
            return ans;
        }
        map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            string dup=strs[i];
            sort(dup.begin(),dup.end());
            m[dup].push_back(strs[i]);
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};
