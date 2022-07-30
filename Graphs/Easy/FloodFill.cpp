class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& image){
        if(i>=0 && j>=0 && i<image.size() && j<image[0].size()) return true;
        else return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int old=image[sr][sc];
        image[sr][sc]=color;
        vector<vector<bool>> vis(image.size(),vector<bool>(image[0].size(),false));
        vis[sr][sc]=true;
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        while(!q.empty()){
            pair<int,int> ele=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int x=ele.first+dx[k];
                int y=ele.second+dy[k];
                if(isValid(x,y,image) &&!vis[x][y] && old==image[x][y]){
                    q.push({x,y});
                    vis[x][y]=true;
                    image[x][y]=color;
                }
            }
        }
        return image;
    }
};
