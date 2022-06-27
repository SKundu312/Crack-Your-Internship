class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        int ans[temp.size()];
        memset(ans, 0, sizeof(ans));
        for(int i=0;i<temp.size();i++){
            while(!st.empty() && temp[st.top().first]<temp[i]){
                
                ans[st.top().first]=i-st.top().first;
                st.pop();
            }
            st.push({i,temp[i]});
        }
        return vector<int>(ans,ans+temp.size());
    }
};
