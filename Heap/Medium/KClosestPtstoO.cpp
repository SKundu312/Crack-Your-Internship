//O(N log K)
class Solution {
public:
    double dist(vector<int>& v){
        return sqrt(pow(v[0],2)+pow(v[1],2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<points.size();i++){
            pair<double,int>p={dist(points[i]),i};
            if(pq.size()<k){
                pq.push(p);
            }else if(p.first<pq.top().first){
                pq.pop();
                pq.push(p);
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            int i=pq.top().second;
            pq.pop();
            ans.push_back(points[i]);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//O(Nlog N)
class Solution {
public:
    double dist(vector<int>& v){
        return sqrt(pow(v[0],2)+pow(v[1],2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),[&](vector<int>& a, vector<int>& b){
            return dist(a)<dist(b);
        });
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};

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

