class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0;
        int diff=0;
        priority_queue<int> pq;
        for(;i<heights.size()-1;i++){
            if(heights[i]<heights[i+1]){
                diff=heights[i+1]-heights[i];
                bricks-=diff;
                pq.push(diff);
                if(bricks<0) {
                    bricks+=pq.top();
                    pq.pop();
                    ladders--;
                }
                if(ladders<0)
                    return i;
        }}
        return i;
    }
};
