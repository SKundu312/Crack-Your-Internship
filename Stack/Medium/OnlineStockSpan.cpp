class StockSpanner {
     stack<pair<int,int>> st;
    int i;
public:
    StockSpanner() {
       i=0;
    }
    
    int next(int price) {
        //int ans=1;
        if(st.empty()){ 
            st.push({price,i++});
            return 1;
        }
        else{
            while(!st.empty() && price>=st.top().first) st.pop();
            int ans;
            if(!st.empty()) ans=i-st.top().second;
            else ans=i+1;
                st.push({price,i++});
            return ans;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
