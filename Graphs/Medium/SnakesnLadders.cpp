class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        map<int,pair<int,int>> m;
        int k=n*n;
        queue<pair<int,int>> q;
        q.push({1,0});
        int fl=0;
        if(n%2==0){
            fl=0;
        }
        else{
            fl=1;
        }
        vector<bool> vis(k+1,false);
        for(int i=0;i<board.size();i++){
            if(fl==0){
                for(int j=0;j<board[i].size();j++){
                    m[k--]={i,j};
                }
                 fl=1-fl;
            }
            else{
                for(int j=board[i].size()-1;j>=0;j--){
                    m[k--]={i,j};
                }
                 fl=1-fl;
            }
        }
        vis[1]=true;
        while(!q.empty()){
            pair<int,int>ele=q.front();
            q.pop();
            int pos=ele.first;
            int ans=ele.second;
            if(pos==n*n) return ans;
            for(int i=1;i<=6;i++){
                int next=pos+i;
                if(next<=n*n){
                    if(!vis[next] && board[m[next].first][m[next].second]==-1){
                        vis[next]=true;
                        q.push({next,ans+1});
                    }
                    else if(board[m[next].first][m[next].second]!=-1){
                        next=board[m[next].first][m[next].second];
                        if(!vis[next]){vis[next]=true;
                        q.push({next,ans+1});}
                    }
                }
            }
        }
        return -1;
    }
};
