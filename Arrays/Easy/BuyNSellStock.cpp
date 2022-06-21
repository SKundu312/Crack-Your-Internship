//O(N^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        for(int i=0;i<prices.size()-1;i++){
            for(int j=i+1;j<prices.size();j++){
                int profit = prices[j]-prices[i];
                if(maxi<profit)
                    maxi=profit;
            }
        }
        return maxi;
    }
};

//O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX,pr=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min)
                min=prices[i];
            if((prices[i]-min)>pr)
                pr=prices[i]-min;
        }
        return pr;
    }
};
