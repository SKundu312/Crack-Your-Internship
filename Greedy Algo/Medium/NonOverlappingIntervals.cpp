class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int l=0,r=1;
        while(r<intervals.size()){
            if(intervals[l][1]<=intervals[r][0]){
                l=r;
                r+=1;
            }
            else if(intervals[l][1]<=intervals[r][1]){
                ans+=1;
                r+=1;
            }
            else if(intervals[l][1]>intervals[r][1]){
                ans+=1;
                l=r;
                r+=1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2){
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        // for(int i=0;i<intervals.size();i++){
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        // }
        int ans=1;
        int prev=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=intervals[prev][1]){
                ans++;
                prev=i;
            }
        }
        return intervals.size()-ans;
    }
};
