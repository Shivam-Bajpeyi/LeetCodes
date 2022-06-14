class Solution {
public:
    int helper(string word1, string word2,int m,int n,vector<vector<int>> &dp)
    {
        // length 0 cannot contribute in counting subsequence length
        if(m==0 or n==0)
            return 0;
        
        // if we have already calculated it then just return it
        if(dp[m][n] != -1)
            return dp[m][n];
        
        // here we check by using by [m-1][n-1] becuse strings are 0 base indexed
        // if matched, congrats common sequence length has increased by one
        if(word1[m-1] == word2[n-1])
            return dp[m][n] = 1+helper(word1,word2,m-1,n-1,dp);
        
        // if not matvhing, try to move pointer where the common sequence remains large
        else
            return dp[m][n] = max(helper(word1,word2,m-1,n,dp),helper(word1,word2,m,n-1,dp));
    }
    
    int minDistance(string word1, string word2) 
    {
        // m + n - (2 * LCS)
        
        // size of word1 & word2
        int m = word1.size();
        int n = word2.size();
        
        // make dp[] 
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        
        // find lcs
        int lcs = helper(word1,word2,m,n,dp);
        
        // return min steps to make them similar = m+n -(2*lcs) 
        return m+n-(2*lcs);
    }
};