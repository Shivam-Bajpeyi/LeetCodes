class Solution {
public:
    int mod = 1e9+7;
    int helper(int target, int zero, int one, vector<int> &dp){
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        
        if(dp[target] != -1) return dp[target];
        
        //explore- substarct one and zero from target
        long long sum = helper(target-zero, zero, one, dp) + helper(target-one, zero, one, dp);
        
        return dp[target]= sum%mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        
        //top-down
        int ans = 0;
        for(int target=low; target<=high; target++){
            ans =   (ans%mod + helper(target, zero, one, dp)%mod)%mod;
        }
        
        return ans;
    }
};