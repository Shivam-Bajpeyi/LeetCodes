//same as buy and sell stocks- II
//applying cooldown: after selling stock we can't buy next day that means we will buy day after tomorrow(ind+2)

// 1. recursion
// class Solution {
// public:
//     int n;
//     int f(int ind, bool buy, vector<int> &prices){
//         if(ind>=n) return 0;    //no more profit can be made
        
//         //if its turn to buy: buy and not-buy (whichever is more profitable)
//         if(buy==1)
//             return max(-prices[ind] + f(ind+1, 0, prices), 0+ f(ind+1, 1, prices));
        
//         //its turn to sell: sell(apply cooldown- can't buy next day) and not-sell
//         else
//             return max(prices[ind] + f(ind+2, 1, prices), 0+ f(ind+1, 0, prices));
        
//     }
    
//     int maxProfit(vector<int>& prices) {
//         n = prices.size();
//         return f(0, 1, prices);
//     }
// };


//2. DP memoization: to avoid solving overlapping suubproblems
class Solution {
public:
    int n;  //prices.size()
    
    int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(ind>=n) return 0;    //no more profit can be made
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        //if its turn to buy: buy and not-buy (whichever is more profitable)
        if(buy==1)
            return dp[ind][buy] = max(-prices[ind] + f(ind+1, 0, prices, dp), 0+ f(ind+1, 1, prices, dp));
        
        //its turn to sell: selling and not-selling (whichever is more profitable)
        else
            return dp[ind][buy] = max(prices[ind] + f(ind+2, 1, prices, dp), 0+ f(ind+1, 0, prices, dp));
        
    }
    
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        
        //dp[n][buy]
        vector<vector<int>> dp(n, vector<int> (2, -1));
            
        //f(ind, buy)
        return f(0, 1, prices, dp);
    }
};