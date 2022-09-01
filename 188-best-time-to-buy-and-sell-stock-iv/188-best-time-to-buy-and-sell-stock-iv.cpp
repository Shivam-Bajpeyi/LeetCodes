//same as Buy and sell stocks III there k = 2, and here k values will be given

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
    
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         //dp[n+1][2][k+1]
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        
//         return f(0, 1, prices, k, dp);
//     }
// };


//3. tabulation: dp[n+1][2][k+1]
// class Solution {
// public: 
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         //dp[n+1][2][k+1]
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
//         for(int ind= n-1; ind>=0; ind--){
//             for(int buy=0; buy<=1; buy++){
//                 for(int cap=1; cap<=k; cap++){
//                     if(buy==1)
//                         dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap], 0+dp[ind+1][1][cap]);
                    
//                     else
//                         dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1], 0+dp[ind+1][0][cap]);
//                 }
//             }
//         }
        
//         return dp[0][1][k];
//     }
// };


//4. tabulation(space- optimized): using ahead[2][k+1] and curr[2][k+1]
// class Solution {
// public: 
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
        
//         //ahead will store ind+1 states
//         vector<vector<int>> ahead(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));
        
//         //put curr as dp[ind] and ahead as dp[ind+1]
//         for(int ind= n-1; ind>=0; ind--){
//             for(int buy=0; buy<=1; buy++){
//                 for(int cap=1; cap<=k; cap++){
//                     if(buy==1)
//                         curr[buy][cap] = max(-prices[ind]+ahead[0][cap], 0+ahead[1][cap]);
                    
//                     else
//                         curr[buy][cap] = max(prices[ind]+ahead[1][cap-1], 0+ahead[0][cap]);
//                 }
//             }
            
//             ahead = curr;
//         }
        
//         return curr[1][k];
//     }
// };


//5. tabulation(space- optimized): using tn(transaction number) ahead[2*k+1] and curr[2*k+1]
class Solution {
public: 
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        //ahead will store ind+1 states
        vector<int> ahead(2*k+1, 0), curr(2*k+1, 0);
        
        //put curr as dp[ind] and ahead as dp[ind+1]
        for(int ind= n-1; ind>=0; ind--){
            for(int tn=0; tn<2*k; tn++){
                if(tn%2==0)
                    curr[tn] = max(-prices[ind]+ahead[tn+1], 0+ahead[tn]);
                    
                else
                    curr[tn] = max(prices[ind]+ahead[tn+1], 0+ahead[tn]);
            }
            
            ahead = curr;
        }
        
        return curr[0];
    }
};