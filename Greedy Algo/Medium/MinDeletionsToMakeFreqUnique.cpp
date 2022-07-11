class Solution {
public:
    vector<int> sorta(map<char,int>& M){
        vector<int> MM;
        for (auto& it : M) {
           MM.push_back(it.second);
        }
        sort(MM.begin(),MM.end(),greater<int>());
        return MM;
    }
    int minDeletions(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
        vector<int> v=sorta(m);
        int ans=0;
        for(int i=1;i<v.size();i++){
            while(v[i-1]<=v[i] && v[i]){
                ans+=1;
                v[i]--;}
        }
        return ans;
    }
};
