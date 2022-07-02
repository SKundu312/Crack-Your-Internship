#define MAX 9e9
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long> pq;
        pq.push(-1*1);
        int i=0;
        long val=1;
        while(!pq.empty() && i<n){
            val=-1*pq.top();
            pq.pop();
            while(!pq.empty() && val==-1*pq.top())
                pq.pop();
            i++;
            pq.push(-1*val*2);
            pq.push(-1*val*3);
            pq.push(-1*val*5);
        }
        return val;
    }
};
