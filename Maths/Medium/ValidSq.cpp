class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> v={p1,p2,p3,p4};
        map<double,int> m;
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                int x=v[i][0]-v[j][0];
                int y=v[i][1]-v[j][1];
                double d=pow(x,2)+pow(y,2);
                m[d]++;
            }
        }
        if(m.size()!=2) return false;
        else{
            map<double,int>:: iterator itr=m.begin();
            double f=itr->first;
            if(f==0) return false;
            if(itr->second!=4) return false;
            ++itr;
            if(itr->second!=2) return false;
            return true;
        }
    }
};
