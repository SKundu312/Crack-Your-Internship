class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++){
            int count=1;
            while(!st.empty() && st.top().first==s[i]){
                count=st.top().second+1;
                st.pop();
            }
            st.push({s[i],count});
            if(st.top().second==k)
                st.pop();
        }
        string ans="";
        while(!st.empty()){
            while(st.top().second--)
                ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
