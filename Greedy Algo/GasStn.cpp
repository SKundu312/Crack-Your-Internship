class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) return -1;
        int ans=0,sum=0;
        for(int i=0;i<gas.size();i++){
            sum+=(gas[i]-cost[i]);
            if(sum<0){
                sum=0;
                ans=i+1;
            }
        }
        return ans;
    }
};

//greedy+suffix sum logic
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxa=INT_MIN,s=0,strt=-1;
        for(int i=gas.size()-1; i>=0; --i){
            s += (gas[i]-cost[i]);
            if(s > maxa){
                maxa = s;
                strt = i;
            }
        }
        if(strt==-1) return -1;
        int sum=0,i=strt;
        do{
            sum+=gas[i];
            if(sum>=cost[i])
                sum-=cost[i];
            else
                return -1;
            i=(i+1)%gas.size();
        }while(i!=strt);
        return strt;
    }
};

