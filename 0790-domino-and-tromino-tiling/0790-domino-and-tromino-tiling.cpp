class Solution {
public:
    
    vector<int> dp;
    const unsigned int t = 1000000007;
    int numTilings(int n) {
        dp.assign(1001, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        if(n > 3) {
            for(int i = 4; i <= n; i++) {
            dp[i] = (((dp[i-1])%t)*2 + (dp[i-3])%t) % t;
           }
        }
        return dp[n];
    }
};