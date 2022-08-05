class Solution {
public:
    void dfs(vector<int>& ans,int curr,set<int>& vis,unordered_map<int,vector<int>>& m){
        if(vis.find(curr)==vis.end()){
            vis.insert(curr);
            ans.push_back(curr);
            for(auto it:m[curr]){
                dfs(ans,it,vis,m);
            }
        }
        else return;
    }
    vector<int> restoreArray(vector<vector<int>>& adjP) {
        if(adjP.size()==1) return adjP[0];
        vector<int> ans;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<adjP.size();i++){
            m[adjP[i][0]].push_back(adjP[i][1]);
            m[adjP[i][1]].push_back(adjP[i][0]);
        }
        int strt;
        for(auto it:m){
            if((it.second).size()==1){
                strt=it.first;
                break;
            }
        }
        set<int> vis;
        dfs(ans,strt,vis,m);
        return ans;
    }
};
