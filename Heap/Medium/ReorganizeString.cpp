class Solution {
public:
    string reorganizeString(string s) {
        string ans="";
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i: m){
            pq.push({i.second,i.first});
        }
        while(pq.size()>1){
            char mostFreq=pq.top().second;
            pq.pop();
            char nextFreq=pq.top().second;
            pq.pop();
            ans+=mostFreq;
            ans+=nextFreq;
            if(m[mostFreq]>1){
                m[mostFreq]-=1;
                pq.push({m[mostFreq],mostFreq});
            }
            if(m[nextFreq]>1){
                m[nextFreq]-=1;
                pq.push({m[nextFreq]-1,nextFreq});
            }
        }
        if(pq.size()){
            char lastCh=pq.top().second;
            if(m[lastCh] > 1)
                return "";
            else
                ans+=lastCh;
            
        }
        return ans;
    }
};
