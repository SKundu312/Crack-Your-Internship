class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        vector<int> v(26,0);
        for(int i=0;i<tasks.size();i++)
            v[tasks[i]-'A']++;
        sort(v.begin(),v.end());
        int maxF=v[25]-1;
        int idle=maxF*n;
        for(int i=24;i>=0;i--){
            idle-=min(v[i],maxF);
        }
        return idle>0?idle+tasks.size():tasks.size();
    }
};
