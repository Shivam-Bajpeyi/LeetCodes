//profit = selling - buying - fee
//same as buy and sell stocks II - just substract the transaction fee after every transaction(after sell)


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        //dp[n+1][buy]: to manage the base case n==0
        vector<int> ahead(2, 0), curr(2, 0);
        
        int profit = 0;
        for(int ind= n-1; ind>=0; ind--){
            //buy
            curr[1] = max(-prices[ind]+ ahead[0] , 0+ ahead[1]);
            //sell with fee
            curr[0] = max(prices[ind]-fee+ ahead[1], 0+ ahead[0]);
            
            ahead = curr;
        }
        
        return curr[1];
    }
};