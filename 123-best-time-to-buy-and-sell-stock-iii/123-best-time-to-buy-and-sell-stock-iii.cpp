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
// class Solution {
// public:
//     int f(int ind, int buy, vector<int> &prices, int cap, vector<vector<vector<int>>> &dp){
//         if(ind==prices.size()) return 0;
//         if(cap==0) return 0;
        
//         if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
//         if(buy==1)
//             return dp[ind][buy][cap] = max(-prices[ind]+ f(ind+1, 0, prices, cap, dp), 0+ f(ind+1, 1, prices, cap, dp));
//         else
//             return dp[ind][buy][cap] = max(prices[ind]+ f(ind+1, 1, prices, cap-1, dp), 0+ f(ind+1, 0, prices, cap, dp));
//     }
    
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        
//         return f(0, 1, prices, 2, dp);
//     }
// };


//3. Tabulation: make dp[n+1][buy][cap] in reverse way 
// ind = n-1 to 0, buy = 0 to 1, cap= 1 to 2
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
        
//         //ind==0 || cap==0 => dp[ind][buy][cap]= 0;    
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    
//         //use recurrence relation to make table
//         for(int ind= n-1; ind>=0; ind--){
//             for(int buy=0; buy<=1; buy++){
//                 for(int cap=1; cap<=2; cap++){
//                     if(buy==1)
//                         dp[ind][buy][cap] = max(-prices[ind]+ dp[ind+1][0][cap], 0+ dp[ind+1][1][cap]);
//                     else
//                         dp[ind][buy][cap] = max(prices[ind]+ dp[ind+1][1][cap-1], 0+ dp[ind+1][0][cap]); 
//                 }
//             }
//         }
        
//         //ind==0, buy= 0, cap= 0
//         return dp[0][1][2];
//     }
// };



//4. Tabulation(space-optimized): make dp[n+1][buy][cap] in reverse way 
// ind = n-1 to 0, buy = 0 to 1, cap= 1 to 2
//replace [ind+1] with ahead
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        //ind==0 || cap==0 => dp[ind][buy][cap]= 0;    
        vector<vector<int>> ahead(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
    
        //use recurrence relation to make table
        for(int ind= n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy==1)
                        curr[buy][cap] = max(-prices[ind]+ ahead[0][cap], 0+ ahead[1][cap]);
                    else
                        curr[buy][cap] = max(prices[ind]+ ahead[1][cap-1], 0+ ahead[0][cap]); 
                }
            }
            
            ahead = curr;
        }
        
        //ind==0, buy= 0, cap= 0
        return curr[1][2];
    }
};