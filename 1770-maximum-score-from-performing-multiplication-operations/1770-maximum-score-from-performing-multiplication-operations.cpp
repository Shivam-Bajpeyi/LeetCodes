//1. recursion
// class Solution {
// public:
//     int f(int i, int l, int r, vector<int>& nums, vector<int>& multi){
//         if(l>r || i==multi.size()) return 0;
        
//         //2 options to multiply, either at front or back
//         int left = nums[l]*multi[i] + f(i+1, l+1, r, nums, multi);
//         int right = nums[r]*multi[i] + f(i+1, l, r-1, nums, multi);
        
//         return max(left, right);
//     }
    
//     int maximumScore(vector<int>& nums, vector<int>& multi) {
//         int n = nums.size();
//         return f(0, 0, n-1, nums, multi);
//     }
// };

//2. memoization
// class Solution {
// public:
//     int f(int i, int l, int r, vector<int>& nums, vector<int>& multi, vector<vector<int>> &dp){
//         if(l>r || i==multi.size()) return 0;
        
//         if(dp[l][r] != -1) return dp[l][r];
        
//         //2 options to multiply, either at front or back
//         int left = nums[l]*multi[i] + f(i+1, l+1, r, nums, multi, dp);
//         int right = nums[r]*multi[i] + f(i+1, l, r-1, nums, multi, dp);
        
//         return dp[l][r] = max(left, right);
//     }
    
//     int maximumScore(vector<int>& nums, vector<int>& multi) {
//         int n = nums.size();
        
//         //dp[n+1][n+1]
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         return f(0, 0, n-1, nums, multi, dp);
//     }
// };

//2. memoization: just use i as r => r = n- (i-l) -1
class Solution {
public:
    int f(int l, int i, int n, vector<int>& nums, vector<int>& multi, vector<vector<int>> &dp){
        if(i==multi.size()) return 0;
        
        if(dp[l][i] != INT_MIN) return dp[l][i];
        
        //2 options to multiply, either at front or back
        int left = nums[l]*multi[i] + f(l+1, i+1, n, nums, multi, dp);
        int right = nums[n-(i-l)-1]*multi[i] + f(l, i+1, n, nums, multi, dp);
        
        return dp[l][i] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        int n = nums.size();
        int m = multi.size();
        
        //dp[n+1][n+1]
        vector<vector<int>> dp(m+1, vector<int>(m+1, INT_MIN));
        return f(0, 0, n, nums, multi, dp);
    }
};