class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                pq.push(matrix[i][j]);
            }
        }
        while(k>1){
            k--;
            pq.pop();
        }
        return pq.top();
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<k;i++)
            pq.push(matrix[i/c][i%c]);
        for(int i=k;i<r*c;i++){
            if(pq.top()>matrix[i/c][i%c]){
                pq.pop();
                pq.push(matrix[i/c][i%c]);
            }
        }
        return pq.top();
    }
};
