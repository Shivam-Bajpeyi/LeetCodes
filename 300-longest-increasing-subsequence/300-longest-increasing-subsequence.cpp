//pick- notPick

//1. recursion
// class Solution {
// public:
//     int f(int ind, int prev, vector<int>& nums){
//         if(ind== nums.size())
//             return 0;
        
//         //notPick- pick
//         int notPick = 0+ f(ind+1, prev, nums);
        
//         int pick = 0;
//         if(prev==-1 || nums[ind]> nums[prev])
//             pick = 1+ f(ind+1, ind, nums);
        
//         //max out of it 
//         return max(notPick, pick);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         return f(0, -1, nums);    //f(ind, prev_ind)
//     }
// };


//2. DP memoization: dp[n][n]
// class Solution {
// public:
//     int f(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp){
//         if(ind== nums.size())
//             return 0;
        
//         if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
//         //notPick- pick
//         int notPick = 0+ f(ind+1, prev, nums, dp);
        
//         int pick = 0;
//         if(prev==-1 || nums[ind]> nums[prev])
//             pick = 1+ f(ind+1, ind, nums, dp);
        
//         //max out of it 
//         return dp[ind][prev+1] = max(notPick, pick);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         //dp[n][n+1]: 1- based index to deal with prev = -1;
//         vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
//         return f(0, -1, nums, dp);    //f(ind, prev_ind)
//     }
// };


//3. Tabulation: using dp[n][n+1]
//ind = n-1 to 0 and prev = ind-1 to -1 (1-based: -1->0)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //dp[n+1][n+1]: 1- based index to deal with prev = -1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int ind=n-1; ind>=0; ind--){
            for(int prev=ind-1; prev>=-1; prev--){
                //notPick- pick
                int notPick = 0+ dp[ind+1][prev+1];
                int pick = 0;
                if(prev==-1 || nums[ind]> nums[prev])
                    pick = 1+dp[ind+1][ind+1];

                //max out of it 
                dp[ind][prev+1] = max(notPick, pick); 
            }
        }
        
        return dp[0][0];
    }
};