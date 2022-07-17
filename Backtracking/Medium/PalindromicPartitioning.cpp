class Solution {
public:
    bool isPalin(string s, int i,int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(string s, int i, vector<string>& row, vector<vector<string>>& ans){
        if(i==s.size()){
            ans.push_back(row);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPalin(s,i,j)){
                row.push_back(s.substr(i,j+1-i));
                backtrack(s,j+1,row,ans);
                row.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> row;
        backtrack(s,0,row,ans);
        return ans;
    }
};
