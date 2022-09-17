//think it as this is the lst balloon and do bottom up like MCM

//1. recursion
// class Solution {
// public:
//     int f(int i, int j, vector<int>& nums){
//         if(j<i) return 0;       //0 points if there is no balloon
        
//         int maxi = INT_MIN;
//         for(int ind= i; ind<=j; ind++){
//             int cost = nums[i-1]*nums[ind]*nums[j+1] + f(i, ind-1, nums) + f(ind+1, j, nums);
//             maxi = max(maxi, cost);
//         }
        
//         return maxi;
//     }
    
//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();
//         nums.insert(nums.begin(), 1);
//         nums.insert(nums.end(), 1);

//         return f(1, n, nums);
//     }
// };


//1. Memoization
class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
        if(j<i) return 0;       //0 points if there is no balloon
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = INT_MIN;
        for(int ind= i; ind<=j; ind++){
            int cost = nums[i-1]*nums[ind]*nums[j+1] + f(i, ind-1, nums, dp) + f(ind+1, j, nums, dp);
            maxi = max(maxi, cost);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        //dp[n+1][n+1]
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        //add both sides 1 for ease of multiplication
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        return f(1, n, nums, dp);
    }
};