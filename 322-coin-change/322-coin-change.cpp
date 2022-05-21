class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 1e5));
        
        //i: represents coin (coin[i-1])
        for(int i=0; i<=n; i++)
        {
            //j: represents amount
            for(int j=0; j<=amount; j++)
            {
                if(j==0)    //to return 0 amount, we dont need any coin
                    dp[i][j] = 0;
                
                else if(i==0)    //0 coin can be given infinity times to return an anount
                    dp[i][j] = 1e5;
                
                else if(coins[i-1] >j)   //coin value > amount (2> 1): then give coins of previous value coin                      
                    dp[i][j] = dp[i-1][j];
                
                else    //amount > coin value (10 > 2): then give 1 coin of this value and also coins for dp[i][restAmount]
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            }
        }
        
        return dp[n][amount]>1e4 ? -1: dp[n][amount];
    }
};