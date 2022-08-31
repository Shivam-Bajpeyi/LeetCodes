//similar to II just limit 2 transaction(buy+sell) here by using cap.

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
    
//     int maxProfit(vector<int>& prices) {
//         return f(0, 1, prices, 2);
//     }
// };


//2. DP memoization: dp[n][buy][cap]= dp[n][2][3]
//buy = 2= 0/1, cap = 3= 0/1/2
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
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        
        return f(0, 1, prices, 2, dp);
    }
};