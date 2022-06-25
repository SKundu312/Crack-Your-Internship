class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<double,int> m;
        double d;
        for(int i=0;i<points.size();i++){
            d=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            cout<<d<<" ";
            m.insert({d,i});
        }
        vector<vector<int>> ans;
        for(auto i=m.begin();i!=m.end() && k>0;i++){
            vector<int> temp={points[i->second][0],points[i->second][1]};
            ans.push_back(temp);
            k--;
        }
        return ans;
    }
};

