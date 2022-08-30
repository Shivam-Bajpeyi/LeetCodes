// 1-> buy; 0-> not-buy
//try out all possible ways to find max profit
//on a particular day we can buy/not-but or sell/not-sell the stock
//profit = selling price - buying price; so buying = -prices[i] and selling = +prices[i]

// 1. recursion
// class Solution {
// public:
//     int n;  //prices.size()
    
//     int f(int ind, bool buy, vector<int> &prices){
//         if(ind==n) return 0;    //no more profit can be made
        
//         //if its turn to buy: buy and not-buy (whichever is more profitable)
//         if(buy==1)
//             return max(-prices[ind] + f(ind+1, 0, prices), 0+ f(ind+1, 1, prices));
        
//         //its turn to sell: selling and not-selling (whichever is more profitable)
//         else
//             return max(prices[ind] + f(ind+1, 1, prices), 0+ f(ind+1, 0, prices));
        
//     }
    
//     int maxProfit(vector<int>& prices) {
//         n = prices.size();
//         //f(ind, buy)
//         return f(0, 1, prices);
//     }
// };

//2. DP memoization: to avoid solving overlapping suubproblems
// class Solution {
// public:
//     int n;  //prices.size()
    
//     int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
//         if(ind==n) return 0;    //no more profit can be made
        
//         if(dp[ind][buy] != -1) return dp[ind][buy];
        
//         //if its turn to buy: buy and not-buy (whichever is more profitable)
//         if(buy==1)
//             return dp[ind][buy] = max(-prices[ind] + f(ind+1, 0, prices, dp), 0+ f(ind+1, 1, prices, dp));
        
//         //its turn to sell: selling and not-selling (whichever is more profitable)
//         else
//             return dp[ind][buy] = max(prices[ind] + f(ind+1, 1, prices, dp), 0+ f(ind+1, 0, prices, dp));
        
//     }
    
//     int maxProfit(vector<int>& prices) {
//         n = prices.size();
        
//         //dp[n][buy]
//         vector<vector<int>> dp(n, vector<int> (2, -1));
            
//         //f(ind, buy)
//         return f(0, 1, prices, dp);
//     }
// };


//3. Tabulation: make dp table in reverse from ind-> n-1 to 0 & buy -> 0 to 1 using base case & recurrence relation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        //dp[n+1][buy]: to manage the base case n==0
        vector<vector<int>> dp(n+1, vector<int> (2, INT_MIN));
            
        //base case
        dp[n][0] = dp[n][1] = 0;
        
        for(int ind= n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                //if its turn to buy: buy and not-buy (whichever is more profitable)
                if(buy==1)
                    dp[ind][buy] = max(-prices[ind]+ dp[ind+1][0] , 0+ dp[ind+1][1]);

                //its turn to sell: selling and not-selling (whichever is more profitable)
                else
                    dp[ind][buy] = max(prices[ind]+ dp[ind+1][1], 0+ dp[ind+1][0]);
               }
        }
        
        return dp[0][1];
    }
};



        