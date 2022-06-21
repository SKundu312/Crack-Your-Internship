//O(M*N)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        multimap<int,int>m;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++){
                if(!matrix[i][j])
                    m.insert({i,j});
            }
        for(auto it=m.begin();it!=m.end();it++){
            for(int j=0;j<matrix[it->first].size();j++)
                matrix[it->first][j]=0;
            for(int i=0;i<matrix.size();i++)
                matrix[i][it->second]=0;
        }
        
        
}};
