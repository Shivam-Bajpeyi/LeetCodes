//Memoization: dp[startPos][k]
//startPos can be negative so can't use 2d vector, use map

class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;
    int mod = 1e9+7;
    
    int f(int startPos, int endPos, int k){
        if(startPos== endPos && k==0) return 1;
        
        if(k<=0 || startPos+k < endPos || startPos-k > endPos) return 0;
        
        //avoid solving already solved sub-problems
        if(dp[startPos].find(k) != dp[startPos].end()) 
            return dp[startPos][k];
        
        //left or right
        int left = f(startPos-1, endPos, k-1)%mod;
        int right = f(startPos+1, endPos, k-1)%mod;
        
        return dp[startPos][k] = left+right%mod;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        int ans;
        // vector<vector<vector<int>>> dp(1001, vector<vector<int>> (1001, vector<int>(1001, -1)));
        ans = f(startPos, endPos, k);
        
        return ans%mod;
    }
};