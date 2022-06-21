//O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int peak=prices[0];
        int valley=prices[0];
        int maxa=0;
        for(int i=0;i<prices.size()-1;i++){
            while(i<prices.size()-1 && prices[i]>=prices[i+1])
                i++;
            valley=prices[i];
            while(i<prices.size()-1 && prices[i]<=prices[i+1])
                i++;
            peak=prices[i];
            maxa+=peak-valley;
        }
        return maxa;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0,profit=0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]<prices[i+1]){
                profit=prices[i+1]-prices[i];
                sum+=profit;
            }
            profit=0;
        }
        return sum;
    }
};
