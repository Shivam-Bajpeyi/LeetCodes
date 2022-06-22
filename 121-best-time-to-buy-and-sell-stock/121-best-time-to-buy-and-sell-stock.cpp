class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];
        
        for(int i=1; i<prices.size(); i++){
            if(prices[i] > buy) //book profit when price gets higher
                profit = max(profit, prices[i]-buy);
            else    //buy when price gets dowb
                buy = prices[i];
        }
        
        return profit;
    }
};