//memoization
class Solution {
public:
    int f(int cnt, int target, vector<int> &nums, vector<int> &dp){
        if(target==0){
            return 1;
        }
        
        if(dp[target] != -1) return dp[target];
        
        for(int it: nums){
            if(it<= target)
                cnt += f(0, target-it, nums, dp);
        }
        
        return dp[target] = cnt;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int cnt = 0;
        vector<int> dp(target+1, -1);
        return f(cnt, target, nums, dp);
    }
};