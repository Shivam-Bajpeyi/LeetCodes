class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentPrice = prices[0];
        int profit = 0;
        
        for(int i=1; i<prices.size(); i++){
            if(prices[i] < currentPrice)       //if stock price gets down, we will start purchasing that day so that we can book profit when price will be high
                currentPrice = prices[i];
            else{    //if stock price gets down, its time to calculate profit, if we are getting max profit then sell it o/w not
                if(prices[i]-currentPrice > profit)
                    profit = prices[i] - currentPrice;
            }
        }
        
        return profit;
    }
};