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


// //2. DP memoization: to avoid solving overlapping suubproblems
// class Solution {
// public:
//     int n;  //prices.size()
    
//     int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
//         if(ind>=n) return 0;    //no more profit can be made
        
//         if(dp[ind][buy] != -1) return dp[ind][buy];
        
//         //if its turn to buy: buy and not-buy (whichever is more profitable)
//         if(buy==1)
//             return dp[ind][buy] = max(-prices[ind] + f(ind+1, 0, prices, dp), 0+ f(ind+1, 1, prices, dp));
        
//         //its turn to sell: selling and not-selling (whichever is more profitable)
//         else
//             return dp[ind][buy] = max(prices[ind] + f(ind+2, 1, prices, dp), 0+ f(ind+1, 0, prices, dp));
        
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
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
        
//         //dp[n+2][buy]: to manage the base case n==0
//         vector<vector<int>> dp(n+2, vector<int> (2, INT_MIN));
            
//         //base case
//         dp[n][0] = dp[n][1] = dp[n+1][0] = dp[n+1][1] = 0;
        
//         for(int ind= n-1; ind>=0; ind--){
//             for(int buy=0; buy<=1; buy++){
//                 //if its turn to buy: buy and not-buy (whichever is more profitable)
//                 if(buy==1)
//                     dp[ind][buy] = max(-prices[ind]+ dp[ind+1][0] , 0+ dp[ind+1][1]);

//                 //its turn to sell: selling and not-selling (whichever is more profitable)
//                 else
//                     dp[ind][buy] = max(prices[ind]+ dp[ind+2][1], 0+ dp[ind+1][0]);
//                }
//         }
        
//         return dp[0][1];
//     }
// };


//4. Tabulation- space optimized using prev (store i+1 states)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        //ahead for i+1 state, aheadNext for i+2 state
        vector<int> ahead(2, 0), aheadNext(2, 0), curr(2, 0);
            
        for(int ind= n-1; ind>=0; ind--){
            //time to buy
            curr[1] = max(-prices[ind]+ ahead[0] , 0+ ahead[1]);
            //its turn to sell: selling and not-selling (whichever is more profitable)
            curr[0] = max(prices[ind]+ aheadNext[1], 0+ ahead[0]);
        
            aheadNext = ahead;
            ahead = curr;
        }
        
        return curr[1];
    }
};