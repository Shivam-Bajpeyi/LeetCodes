//same as Buy and sell stocks III: there we need to do 2 transactions and here that number is k

//1. recursion
// class Solution {
// public:
//     int f(int ind, int buy, vector<int> &prices, int cap){
//         if(ind==prices.size()) return 0;
//         if(cap==0) return 0;
        
//         if(buy==1)
//             return max(-prices[ind]+ f(ind+1, 0, prices, cap), 0+ f(ind+1, 1, prices, cap));
//         else
//             return max(prices[ind]+ f(ind+1, 1, prices, cap-1), 0+ f(ind+1, 0, prices, cap));
//     }
    
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         return f(0, 1, prices, k);
//     }
// };

//2. DP memoizations
class Solution {
public:
    int f(int ind, int buy, vector<int> &prices, int cap, vector<vector<vector<int>>> &dp){
        if(ind==prices.size()) return 0;
        if(cap==0) return 0;
        
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        if(buy==1)
            return dp[ind][buy][cap] = max(-prices[ind]+ f(ind+1, 0, prices, cap, dp), 0+ f(ind+1, 1, prices, cap, dp));
        else
            return dp[ind][buy][cap] = max(prices[ind]+ f(ind+1, 1, prices, cap-1, dp), 0+ f(ind+1, 0, prices, cap, dp));
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //dp[n+1][2][k+1]
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        
        return f(0, 1, prices, k, dp);
    }
};