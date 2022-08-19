// //DP Memoization: top-down (to deal with overlapping subproblems)
// class Solution {
// public:
//     int lcs(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp){
//         if(ind1<0 || ind2<0) return 0;
        
//         //if we already have the answer stored in our dp
//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
//         //matching- not matching
//         if(text1[ind1]== text2[ind2])
//             return dp[ind1][ind2] = 1+ lcs(ind1-1, ind2-1, text1, text2, dp);
        
//         else
//             return dp[ind1][ind2] = max(lcs(ind1-1, ind2, text1, text2, dp), lcs(ind1, ind2-1, text1, text2, dp));
//     }
    
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.size();
//         int n2 = text2.size();
        
//         vector<vector<int>> dp(n1, vector<int>(n2, -1));
//         return lcs(n1-1, n2-1, text1, text2, dp);     //f(ind1, ind2);
//     }
// };


//DP tabulation: bottom up(make dp table with base case to exploration cases)
//doing shifting of index to utilize base case=> -1 -> 0
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        //dp table: 0 to n1-1 --> 1 to n1 so that 0 --> -1
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        //base case: shift indexes to right -1 -> 0
        for(int ind1=0; ind1<=n1; ind1++) dp[ind1][0] = 0;
        for(int ind2=0; ind2<=n2; ind2++) dp[0][ind2] = 0;
        
        //form table: ind1-> 1 to n1 & ind2-> 1 to n2
        for(int ind1=1; ind1<=n1; ind1++){
            for(int ind2=1; ind2<=n2; ind2++){
            //matching- not matching
            if(text1[ind1-1]== text2[ind2-1])   //do ind-1 in both string to match chars
                dp[ind1][ind2] = 1+ dp[ind1-1][ind2-1];
        
        else
            dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            
            }
        }
        
        return dp[n1][n2];
    }
};