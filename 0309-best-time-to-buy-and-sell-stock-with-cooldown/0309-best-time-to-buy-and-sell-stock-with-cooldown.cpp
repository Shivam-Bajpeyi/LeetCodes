class Solution {
public:
    int profit(int ind, vector<int> &prices, int buy, vector<vector<int>> &dp){
        if(ind>= prices.size())
            return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        //buy: buy or not buy
        if(buy==1){
            return dp[ind][buy] = max(-prices[ind]+ profit(ind+1, prices, 1-buy, dp), profit(ind+1, prices, buy, dp));
        }
        //sell: sell(can't buy on next day) or not sell
        else{
            return dp[ind][buy] = max(prices[ind]+ profit(ind+2, prices, 1-buy, dp), profit(ind+1, prices, buy, dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        //dp
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        //buy = 1, sell = 0
        return profit(0, prices, 1, dp);    
    }
};