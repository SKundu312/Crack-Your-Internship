class Solution {
public:
    int backtrack(vector<vector<int>>& grid, int i, int j, int zero){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1)
            return 0;
        if(grid[i][j]==2)
            return zero==-1?1:0;
        grid[i][j]=-1;
        zero--;
        int totalPath=backtrack(grid,i-1,j,zero)+backtrack(grid,i,j-1,zero)+backtrack(grid,i+1,j,zero)+backtrack(grid,i,j+1,zero);
        grid[i][j]=0;
        zero++;
        return totalPath;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero=0,sx=0,sy=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) zero++;
                else if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
            }   
        }
        return backtrack(grid,sx,sy,zero);
    }
};
