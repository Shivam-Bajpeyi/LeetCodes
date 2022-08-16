//Tabulation(bottom-up approach): to avoid overlapping subproblems
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));   //dp[ind][amount]
        
        //construct base of the table
        // for(int i=0; i<n; i++)  //amount= 0
        //     dp[i][0]= 1;    
        for(int T=0; T<=amount; T++)    //index = 0
            dp[0][T] = (T%coins[0]==0);
        
        
        //build dp from bottom to up
        for(int i=1; i<n; i++){
            for(int T=0; T<= amount; T++){
                //take- not take
                int notTake = dp[i-1][T];
        
                int take = 0;
                if(coins[i]<= T)
                    take = dp[i][T-coins[i]];
                
                dp[i][T] = notTake+take;
            }
        }
        
        return dp[n-1][amount];
    }
};